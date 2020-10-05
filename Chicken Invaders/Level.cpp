#include "Level.h"
#include "Gui.h"

Level::Level(uint16_t numberOfWaves, std::vector<Enemy>& enemies, std::vector<Projectile>* projectiles, std::vector<PowerUp>* powerUps,
	GameDifficulty* difficulty, sf::VideoMode& vm) :
	m_numberOfWaves(numberOfWaves), m_currentWave(-1), m_enemies(enemies), m_projectiles(projectiles), m_powerUps(powerUps), m_vm(vm), m_difficulty(difficulty)
{

}

uint16_t Level::getNumberOfWaves() const noexcept
{
	return m_numberOfWaves;
}

uint16_t Level::getCurrentWave() const noexcept
{
	return m_currentWave;
}

bool Level::isWaveComplete() const noexcept
{
	return m_enemies.size() == 0;
}

bool Level::nextWave() noexcept
{
	m_currentWave++;
	if (m_enemies.size() != 0) {
		m_enemies.erase(m_enemies.begin(), m_enemies.end());
	}
	for (int i = 0; i < m_wavesLogic.at(m_currentWave).getEnemyNumber(); ++i)
	{
		m_enemies.emplace_back(m_allEnemies.at(i));
	}
	m_allEnemies.erase(m_allEnemies.begin(), m_allEnemies.begin() + m_wavesLogic.at(m_currentWave).getEnemyNumber());

	switch (m_wavesLogic.at(m_currentWave).getShape())
	{
	case Shape::RECTANGLE: rectangleSpawn(m_wavesLogic.at(m_currentWave));  break;
	case Shape::DIAMOND: diamondSpawn(m_wavesLogic.at(m_currentWave)); break;
	case Shape::RANDOM: randomSpawn(m_wavesLogic.at(m_currentWave)); break;
	case Shape::TRIANGLE: triangleSpawn(m_wavesLogic.at(m_currentWave)); break;
	case Shape::XSHAPE: xshapeSpawn(m_wavesLogic.at(m_currentWave)); break;
	default: break;
	}
	return true;
}

void Level::addWave(Wave wave)
{
	m_wavesLogic.emplace_back(wave);
	generateEnemies(wave);
}

void Level::generateEnemies(Wave wave)
{
	std::string enemy;
	sf::Vector2u sprite;
	float switchTime;

	switch (wave.getShape())
	{
	case Shape::METEORITES:
		enemy = "MeteorAnim";
		sprite.x = 4;
		sprite.y = 30;
		switchTime = 0.05f;
		for (int i = 0; i < wave.getEnemyNumber(); i++)
		{
			float size = Animation::getRandomFloat(50.0f, 100.0f);
			m_allEnemies.emplace_back(TextureCache::getTexture(enemy), m_projectiles, m_powerUps, sprite, m_difficulty->getHp(), 
				m_difficulty->getEnemyFireRate(), m_difficulty->getEnemyFireCooldown(), switchTime, m_difficulty->getEnemySpeed(),
				Animation::getRandomFloat(-250.0f, 700.0f), Animation::getRandomFloat(-200.0f, 200.0f), size, size, wave.getPattern(),
				m_vm);
		}
		break;
	default:
		enemy = "Enemy";
		sprite.x = 5;
		sprite.y = 1;
		for (int i = 0; i < wave.getEnemyNumber(); i++)
		{
			m_allEnemies.emplace_back(TextureCache::getTexture(enemy), m_projectiles, m_powerUps, sprite, m_difficulty->getHp(),
				m_difficulty->getEnemyFireRate(), m_difficulty->getEnemyFireCooldown(), 1.0f, m_difficulty->getEnemySpeed(), 0, 0,
				defaultEnemySize, defaultEnemySize, wave.getPattern(), m_vm);
		}
		break;
	}

	if (m_enemies.size() == 0)
		nextWave();
}

void Level::rectangleSpawn(Wave wave)
{
	for (int i = 0; i < m_enemies.size(); i++)
	{
		if (i < 10)
			m_enemies.at(i).setPosition(sf::Vector2f(200.0f + (float)(i % 10 * 100), 50.0f));
		else if (i > 9 && i < 20)
			m_enemies.at(i).setPosition(sf::Vector2f(200.0f + (float)(i % 10 * 100), 200.0f));
		else if (i > 19 && i < 30)
			m_enemies.at(i).setPosition(sf::Vector2f(200.0f + (float)(i % 10 * 100), 350.0f));
		else if (i > 29 && i < 40)
			m_enemies.at(i).setPosition(sf::Vector2f(200.0f + (float)(i % 10 * 100), 500.0f));
	}
}

void Level::diamondSpawn(Wave wave)
{
	float X = 500.f, Y = 20.f;
	for (int i = 0; i < m_enemies.size(); i++)
	{
		if (i < 10)
		{
			m_enemies.at(i).setPosition(sf::Vector2f(X, Y));
			X -= 50;
			Y += 25;
		}
		else if (i < 20)
		{
			m_enemies.at(i).setPosition(sf::Vector2f(X, Y));
			X += 50;
			Y += 25;
		}
		else if (i < 30)
		{
			m_enemies.at(i).setPosition(sf::Vector2f(X, Y));
			X += 50;
			Y -= 25;
		}
		else if (i < 40)
		{
			m_enemies.at(i).setPosition(sf::Vector2f(X, Y));
			X -= 50;
			Y -= 25;
		}
	}
}

void Level::triangleSpawn(Wave wave)
{
	int triangleLevels = 8;
	float spawnX = 200.0f, spawnY = 50.0f;
	for (int i = 0; i < m_enemies.size();)
	{
		int currentLevel = triangleLevels;
		while (currentLevel != 0 && i < m_enemies.size())
		{
			m_enemies.at(i).setPosition(sf::Vector2f(spawnX + (float)(i % triangleLevels * 100), spawnY));
			currentLevel--;
			i++;
		}
		spawnX += 50.0f;
		spawnY += 75.0f;
		triangleLevels--;
	}
}

void Level::xshapeSpawn(Wave wave)
{
	int crt = 0, nr = 0;
	float crtX = 20.f, crtY = 20.f, pos;
	while (crt < m_enemies.size())
	{
		if (nr == 20)
		{
			nr = 0;
			crtY = 20.f;
			crtX = pos;
		}
		if (crt < m_enemies.size() && nr < 10)
		{
			m_enemies.at(crt).setPosition(sf::Vector2f(crtX, crtY));
			crtX += 35.f;
			crtY += 35.f;
			nr++;
			crt++;
		}
		else if (crt < m_enemies.size() && nr < 20) {
			if (nr == 10)
			{
				pos = crtY + 100.f;
				crtY = 20.f;
			}
			m_enemies.at(crt).setPosition(sf::Vector2f(crtX, crtY));
			crtX -= 35.f;
			crtY += 35.f;
			nr++;
			crt++;
		}
	}
}

void Level::randomSpawn(Wave wave)
{
	for (Enemy& e: m_enemies)
	{
		e.setPosition(sf::Vector2f(Animation::getRandomFloat(50.f, 1000.f), Animation::getRandomFloat(10.f, 400.f)));
	}
}

void Level::addBoss(Wave wave, char nr)
{
	std::string boss("Boss");
	boss.push_back(nr);
	m_wavesLogic.emplace_back(wave);
	for (int i = 0; i < wave.getEnemyNumber() - 1; i++)
	{
		m_allEnemies.emplace_back(TextureCache::getTexture("Enemy"), m_projectiles, m_powerUps, sf::Vector2u(5, 1),
			m_difficulty->getHp(), m_difficulty->getEnemyFireRate(), m_difficulty->getEnemyFireCooldown(), 1.0f,
			m_difficulty->getEnemySpeed(), Gui::p2pX(10.f, m_vm) + i * 50, Gui::p2pY(10.f, m_vm),
			defaultEnemySize, defaultEnemySize, wave.getPattern(), m_vm);
	}
	int weapon = nr == '3' ? 7 : 6;

		m_allEnemies.emplace_back(TextureCache::getTexture(boss), m_projectiles, m_powerUps, sf::Vector2u(1, 1), 1, 0.3f, 3.0f, 1.0f,
			m_difficulty->getEnemySpeed(), Gui::p2pX(40.f, m_vm), Gui::p2pY(20.f, m_vm),
			Gui::p2pX(20.f, m_vm), Gui::p2pY(20.f, m_vm), Pattern::HORIZONTAL, m_vm, weapon, 50);
		m_allEnemies.at(m_allEnemies.size() - 1).setHp(50);
		m_allEnemies.at(m_allEnemies.size() - 1).setPosition(sf::Vector2f(900.f, 400.f));
	
	
}
