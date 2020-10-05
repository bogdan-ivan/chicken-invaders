#pragma once
#include "State.h"
#include "PauseMenu.h"
#include "PlayerGUI.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"
#include "LevelManager.h"
#include "GameDifficulty.h"
#include "SmartMove.h"
#include "SmartAssistant.h"

enum class GameMode
{
	SINGLEPLAYER,
	LANCOOP2,
	LANCOOP3,
	LANCOOP4,
	ONLINECOOP2,
	ONLINECOOP3,
	ONLINECOOP4,
};

class GameState :
	public State
{
public:
	GameState(StateData* stateData, GameDifficulty* difficulty, std::string profileName, std::pair<std::string, std::string> customization,
		bool smartHint, bool smartAssistant);
	~GameState();
	void updateInput(const float& deltaTime);
	void update(const float& deltaTime) override;
	void draw(sf::RenderTarget* target = nullptr) override;
private:
	void removeDeadEnemies();
	void collisionDetection();
	void removeOutOfBorderBullets();
	void checkBoss();
	void removeExpiredPowerUps();

	void updatePauseMenuButtons();
	void updatePlayerGUI(const float& deltaTime);
	void updateBackground(const float& deltaTime);

	void initializeFonts();
	void initializeScore();
	void initializePauseMenu();
	void initializeBackground();
	void initializePlayers(std::pair<std::string, std::string> customization, GameDifficulty* difficulty);
	void initializePlayerGUI();
	void initializeSmartMove();
	void initializeSmartAssistant();
	void initializeRewards();
	void initializeShaders();
	void initializeText();
private:
	GameMode m_gameMode;
	sf::RectangleShape m_backround;
	sf::RectangleShape m_nukeArea;
	std::unique_ptr<Animation> m_nukeAnimation;
	bool m_nukeActive;
	std::vector<Player> m_players;
	std::unique_ptr<PlayerGUI> m_playerGUI;
	std::vector<Enemy> m_enemies;
	std::vector<Projectile> m_projectiles;
	std::vector<PowerUp> m_powerUps;
	std::unique_ptr<Score> m_score;
	std::shared_ptr<Logger> logger;
	std::unique_ptr<PauseMenu> m_pauseMenu;
	sf::Font m_font;
	std::unique_ptr<LevelManager> m_levelManager;
	std::unique_ptr<SmartMove> m_smartMove;
	std::unique_ptr<SmartAssistant> m_smartAssistant;
	int m_chickenReward;
	int m_meatReward;
	int m_repeatCnt;
	float m_textDisplayTime;
	float m_textDisplayLimit;
	int m_powerUpReward;
	float m_nukeCounter;
	float m_nukeDuration;
	int m_waveNumber;
	std::string m_profileName;
	sf::Shader m_coreShader;
	sf::Text m_waveText;
	std::string m_waveString;
	bool m_musicPlaying;
	GameDifficulty* m_difficulty;
};