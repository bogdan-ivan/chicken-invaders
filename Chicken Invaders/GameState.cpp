#include "GameState.h"
#include <iostream>
#include "HighScoreBoard.h"

GameState::GameState(StateData* stateData, GameDifficulty* difficulty, std::string profileName, std::pair<std::string, std::string> customization,
	bool smartHint, bool smartAssistant)
	:State(stateData), m_nukeActive(false), m_profileName(profileName), m_textDisplayTime(0), m_textDisplayLimit(215.f), m_waveNumber(2),
	m_musicPlaying(true), m_difficulty(difficulty), m_repeatCnt(0)
{
	logger = Logger::getInstance();
	logger->startLogging("Logging.txt");
	
	m_levelManager = std::make_unique<LevelManager>(10, m_enemies, &m_projectiles, &m_powerUps, difficulty, m_stateData->m_gfxSettings->m_resolution);

	initializeFonts();
	initializeText();
	initializeScore();
	initializePauseMenu();
	initializeBackground();
	initializePlayers(customization, difficulty);
	initializePlayerGUI();
	if(smartHint)
		initializeSmartMove();
	if(smartAssistant)
		initializeSmartAssistant();
	initializeRewards();
	initializeShaders();
	AudioCache::playMusic("PlayingTheme");
}

GameState::~GameState()
{
	AudioCache::stopMusic("PlayingTheme");
}

void GameState::updateInput(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && getKeytime())
	{
		if (!m_paused)
			pauseState();
		else
			unpauseState();
	}

}

void GameState::update(const float& deltaTime)
{

	updateMousePositions(); 
	updateKeytime(deltaTime);
	updateInput(deltaTime);
	if (m_textDisplayTime > m_textDisplayLimit)
	{
		if (!m_paused)
		{
			if (!m_musicPlaying)
			{
				AudioCache::playMusic("PlayingTheme");
				m_musicPlaying = true;
			}
			updateBackground(deltaTime);

			for (auto& p : m_players)
			{
				p.update(deltaTime);
			}
			for (auto& e : m_enemies)
			{
				e.update(deltaTime);
			}
			for (auto& p : m_projectiles)
			{
				p.update(deltaTime);
			}
			for (auto& powerUp : m_powerUps)
			{
				powerUp.update(deltaTime);
			}

			checkBoss();
			m_playerGUI->update(deltaTime);

			if (m_enemies.size() == 0)
			{
				if (m_levelManager->isLevelComplete())
				{
					if (!m_levelManager->isGameComplete())
					{
						m_levelManager->nextLevel();
						m_waveNumber = 1;
					}
					else
					{
						m_levelManager.release();
						m_difficulty->increaseEnemyHp();
						m_waveNumber = 1;
						m_levelManager = std::make_unique<LevelManager>(10, m_enemies, &m_projectiles, &m_powerUps, m_difficulty, m_stateData->m_gfxSettings->m_resolution);
						m_textDisplayTime = 0.f;
						m_repeatCnt += m_levelManager->getNumberOfLevels();
						m_waveText.setString("Level " + std::to_string(m_levelManager->m_currentLevel + 1 + m_repeatCnt) + " - Wave " + std::to_string(m_waveNumber++));
					}
				}
				else
				{
					m_textDisplayTime = 0.f;
					m_levelManager->update();
					m_waveText.setString("Level " + std::to_string(m_levelManager->m_currentLevel + 1 + m_repeatCnt) + " - Wave " + std::to_string(m_waveNumber++));
				}
			}

			if(m_smartMove.get() != nullptr)
				m_smartMove->update(deltaTime);
			if (m_smartAssistant.get() != nullptr)
				m_smartAssistant->update(deltaTime);

			removeDeadEnemies();
			if (m_players.at(0).isAlive())
				collisionDetection();
			removeOutOfBorderBullets();
			removeExpiredPowerUps();
			m_score->update();
		}
		else
		{
			m_pauseMenu->update(m_mousePosView);
		}

		if (m_players[0].hasLifes() == false)
		{
				m_textDisplayTime = 0.f;
				m_waveText.setString("     GAME OVER !");
				HighScoreBoard::addScore(m_score->getScore(), m_profileName);
				
		}
		if (m_players[0].usedRocket() == true)
		{
			m_nukeActive = true;
			for (auto& e : m_enemies)
			{
				e.setAlive(false);
			}
		}
		if (m_nukeActive && m_nukeCounter < m_nukeDuration)
		{
			m_nukeCounter += deltaTime;
			m_nukeAnimation->update(deltaTime);
			m_nukeArea.setTextureRect(m_nukeAnimation->m_uvRect);
		}
		else
		{
			m_nukeCounter = 0.f;
			m_nukeActive = false;
		}
	}
	else
	{
		updateBackground(deltaTime);
		m_textDisplayTime += deltaTime;

		for (auto& p : m_players)
		{
			p.update(deltaTime);
		}
		for (auto& p : m_projectiles)
		{
			p.update(deltaTime);
		}
		for (auto& powerUp : m_powerUps)
		{
			powerUp.update(deltaTime);
		}

		if (m_players[0].hasLifes() == false)
		{
			if(m_textDisplayTime > m_textDisplayLimit / 1.2f)
				endState();
		}

		m_playerGUI->update(deltaTime);
		

		if (m_players.at(0).isAlive())
			collisionDetection();
		
		if (m_players[0].usedRocket() == true)
		{
			m_nukeActive = true;
			for (auto& e : m_enemies)
			{
				e.setAlive(false);
			}
		}
		if (m_nukeActive && m_nukeCounter < m_nukeDuration)
		{
			m_nukeCounter += deltaTime;
			m_nukeAnimation->update(deltaTime);
			m_nukeArea.setTextureRect(m_nukeAnimation->m_uvRect);
		}
		else
		{
			m_nukeCounter = 0.f;
			m_nukeActive = false;
		}
	}
}

void GameState::draw(sf::RenderTarget * target)
{
	if (!target)
		target = m_window;
	if (m_textDisplayTime < m_textDisplayLimit)
	{
		target->draw(m_backround);
		target->draw(m_waveText);
		for (auto& p : m_players)
		{
			if(p.isAlive())
				p.draw(*m_window, &m_coreShader);
		}
		for (auto& powerUp : m_powerUps)
		{
			powerUp.draw(*m_window);
		}
		m_playerGUI->draw(*target);
		m_textDisplayTime++;
		if (m_nukeActive)
		{
			target->draw(m_nukeArea);
		}
	}
	else
	{
		target->draw(m_backround);
		for (auto& p : m_players)
		{
			p.draw(*m_window, &m_coreShader);
		}
		for (auto& e : m_enemies)
		{
			e.draw(*m_window);
		}
		for (auto& p : m_projectiles)
		{
			p.draw(*m_window);
		}
		for (auto& powerUp : m_powerUps)
		{
			powerUp.draw(*m_window);
		}

		m_playerGUI->draw(*target);
		m_score->draw(*m_window);

		if (m_smartMove.get() != nullptr)
			m_smartMove->draw(*m_window);
		if (m_smartAssistant.get() != nullptr)
			m_smartAssistant->draw(*m_window);

		if (m_paused)
		{
			m_pauseMenu->draw(*target);
			updatePauseMenuButtons();
			AudioCache::pauseMusic("PlayingTheme");
			m_musicPlaying = false;
		}

		if (m_nukeActive)
		{
			target->draw(m_nukeArea);
		}
	}
}

void GameState::removeDeadEnemies()
{
	for (size_t i = 0; i < m_enemies.size(); ++i)
	{
		if (m_enemies[i].getAlive() == false)
		{
			Statistics::increaseEnemiesKilled();
			if(m_enemies[i].getPattern() != Pattern::DIAGONAL)
				m_score->addScore(m_chickenReward);
			m_enemies.erase(m_enemies.begin() + i);
		}
	}
}

void GameState::removeOutOfBorderBullets()
{

	for (auto it = m_projectiles.begin(); it != m_projectiles.end();)
	{
		if (it->getPosition().y < 0 || it->getPosition().x < 0 || it->getPosition().x > m_stateData->m_gfxSettings->m_resolution.width || 
			it->getPosition().y > m_stateData->m_gfxSettings->m_resolution.height)
			it = m_projectiles.erase(it);
		else
			++it;
	}
}

void GameState::checkBoss()
{
	if (!m_enemies.empty())
	{
		if (m_enemies[m_enemies.size() - 1].isBoss())
			m_playerGUI->enableBossBar(m_enemies[m_enemies.size() - 1].getHp());
		else
			m_playerGUI->disableBossBar();
	}
	
}

void GameState::removeExpiredPowerUps()
{
	for (auto it = m_powerUps.begin(); it != m_powerUps.end();)
	{
		if (it->getExpired())
			it = m_powerUps.erase(it);
		else
			++it;
	}
}

void GameState::updatePauseMenuButtons()
{
	if (m_pauseMenu->isButtonPressed("RESUME"))
	{
		unpauseState();
	}
	if (m_pauseMenu->isButtonPressed("QUIT"))
	{
		Statistics::saveToFile();
		endState();
	}
}

void GameState::updatePlayerGUI(const float& deltaTime)
{
	m_playerGUI->update(deltaTime);
}

void GameState::updateBackground(const float& deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	movement.y += 50 * deltaTime;
	m_backround.move(movement);
	if (m_backround.getPosition().y > 0)
	{
		int y = m_window->getSize().y;
		m_backround.setPosition(sf::Vector2f(0, -y*3));
	}
		
}

void GameState::collisionDetection()
{
	for (auto& enemy : m_enemies)
	{
		for (auto bullet = m_projectiles.begin(); bullet != m_projectiles.end();)
		{
			for (auto player = m_players.begin(); player != m_players.end();)
			{
				if (player->getBody().getGlobalBounds().intersects(enemy.getBody().getGlobalBounds())
					&& m_textDisplayTime > m_textDisplayLimit)
				{
					if (player->getVulnerable())
					{
						player->hit();
						enemy.hit();
						Statistics::increaseDeaths();
						AudioCache::playSound("PlayerDeath");
					}
				}
				if (bullet->getBody().getGlobalBounds().intersects(enemy.getBody().getGlobalBounds()) && bullet->getOwner() == Projectile::ProjectileOwner::PLAYER)
				{
					Statistics::increaseShotsHit();
					enemy.hit();
					if(enemy.getPattern() != Pattern::DIAGONAL)
						AudioCache::playSound("ChickenDeath");
					bullet = m_projectiles.erase(bullet);
				}
				else if (bullet->getBody().getGlobalBounds().intersects(player->getBody().getGlobalBounds()) && bullet->getOwner() == Projectile::ProjectileOwner::ENEMY)
				{
					if (player->getVulnerable())
					{
						player->hit();
						Statistics::increaseDeaths();
						AudioCache::playSound("PlayerDeath");
						bullet = m_projectiles.erase(bullet);
						++player;
						return;
					}
				}
				else
					++bullet;
				++player;
			}
		}
	}

	for (auto& player : m_players)
	{
		for (auto power = m_powerUps.begin(); power != m_powerUps.end();)
		{
			if (power->getBody().getGlobalBounds().intersects(player.getBody().getGlobalBounds()))
			{
				if (player.getVulnerable())
				{
					Statistics::increasePowerUpsCollected();
					PowerUpType powerType = power->getType();
					switch (powerType)
					{
					case::PowerUpType::KEY:
					{
						Statistics::increaseKeys();
						m_score->addScore(m_powerUpReward);
						break;
					}
					case PowerUpType::FIRE_RATE:
						player.increaseFireRate();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::FIRE_POWER:
						player.increaseFirePower();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::MOVEMENT_SPEED:
						player.increaseSpeed();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::ROCKET:
						player.addRocket();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::MEAT:
						player.addMeat();
						m_score->addScore(m_meatReward);
						break;
					case PowerUpType::LIFE:
						player.addLife();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::PULSEGUN:
						player.equipPulseGun();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::NEUTRONGUN:
						player.equipNeutronGun();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::PLASMAGUN:
						player.equipPlasmaGun();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::UTENSILGUN:
						player.equipUtensilGun();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::LASERGUN:
						player.equipLaserGun();
						m_score->addScore(m_powerUpReward);
						break;
					case PowerUpType::HYPERGUN:
						player.equipHyperGun();
						m_score->addScore(m_powerUpReward);
						break;
					default:
						break;
					}
					AudioCache::playSound("PowerUp");
					power = m_powerUps.erase(power);
				}
			}
			else
				++power;
		}
	  }
}

void GameState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void GameState::initializeScore()
{
	m_score = std::make_unique<Score>(m_font, p2pX(1.f), p2pY(1.f), charSize(50));
}

void GameState::initializePauseMenu()
{
	m_pauseMenu = std::make_unique<PauseMenu>(m_stateData->m_gfxSettings->m_resolution, m_font);
	m_pauseMenu->addButton("RESUME", p2pY(25.f), p2pX(15.f), p2pY(7.f), charSize(100), "Resume");
	m_pauseMenu->addButton("SAVE", p2pY(35.f), p2pX(15.f), p2pY(7.f), charSize(100), "Save");
	m_pauseMenu->addButton("LOAD", p2pY(45.f), p2pX(15.f), p2pY(7.f), charSize(100), "Load");
	m_pauseMenu->addButton("QUIT", p2pY(70.f), p2pX(15.f), p2pY(7.f), charSize(100), "Quit");
}

void GameState::initializeBackground()
{
	int y = m_window->getSize().y;
	m_backround.setSize(sf::Vector2f(static_cast<float>(m_window->getSize().x), static_cast<float>(y * 4)));
	m_backround.setPosition(sf::Vector2f(0, -y*3));
	m_backround.setTexture(TextureCache::getTexture("Game1"));
	m_nukeArea.setSize(sf::Vector2f(static_cast<float>(m_window->getSize().x), static_cast<float>(m_window->getSize().y)));
	m_nukeArea.setTexture(TextureCache::getTexture("Explosion1"));
	m_nukeAnimation = std::make_unique<Animation>(TextureCache::getTexture("Explosion1"), sf::Vector2u(10, 11), 0.01f);
	m_nukeCounter = 0.f;
	m_nukeDuration = 1.0f;
}

void GameState::initializePlayers(std::pair<std::string, std::string> customization, GameDifficulty* difficulty)
{
	m_players.emplace_back(TextureCache::getTexture(customization.first), m_projectiles, sf::Vector2u(2, 9), 0.3f,
		difficulty->getPlayerSpeed(), m_stateData->m_gfxSettings->m_resolution, customization.second, 
		difficulty->getLifes(), difficulty->getMaxFirePower(), difficulty->getMaxOverheat(), difficulty->getMaxSpeed(),
		difficulty->getMinSpeed(),  difficulty->getRockets());
	logger->log(LoggingLevel::INFO, "Player added");
}

void GameState::initializePlayerGUI()
{
	m_playerGUI = std::make_unique<PlayerGUI>(&m_players[0], m_stateData->m_gfxSettings->m_resolution);
}

void GameState::initializeSmartMove()
{
	m_smartMove = std::make_unique<SmartMove>(TextureCache::getTexture("Flame"), sf::Vector2u(10, 6), 0.05f, 300, m_enemies, m_window);
}

void GameState::initializeSmartAssistant()
{
	m_smartAssistant = std::make_unique<SmartAssistant>(TextureCache::getTexture("PlayerYellow"), sf::Vector2u(2, 9), 0.2f, 300,
		m_enemies, m_projectiles, m_window, m_stateData->m_gfxSettings->m_resolution);
}

void GameState::initializeRewards()
{
	m_chickenReward = 1000;
	m_meatReward = 100;
	m_powerUpReward = 1000;
}

void GameState::initializeShaders()
{
	if (!m_coreShader.loadFromFile("..//Shaders//vertex_shader.vert", "..//Shaders//fragment_shader.frag"))
	{
		std::cout << "ERROR::GAMESTATE::COULD NOT LOAD SHADER." << "\n";
	}
}

void GameState::initializeText()
{
	m_waveText.setFont(m_font);
	m_waveText.setPosition(sf::Vector2f(p2pX(30.f), p2pY(30.f)));
	m_waveText.setCharacterSize(charSize(45));
	m_waveText.setFillColor(sf::Color(255, 255, 255, 200));
	m_waveText.setString("Level 1 - Wave 1");
}
