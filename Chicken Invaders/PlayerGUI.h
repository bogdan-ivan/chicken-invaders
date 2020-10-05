#pragma once

#include "Player.h"
#include "ProgressBar.h"

class Player;

class PlayerGUI
{
public:
	PlayerGUI(Player* player, sf::VideoMode& vm);
	~PlayerGUI();
	void update(const float& deltaTime);
	void draw(sf::RenderTarget& target);
	void enableBossBar(uint16_t hp);
	void disableBossBar();
private:
	void initializeFont();
	void initializeLifesDisplay();
	void initializeFirepowerDisplay();
	void initializeMeatDisplay();
	void initializeRocketDisplay();
	void initializeOverheatBar();
	void initializeBossBar();

	void updateLifesDisplay();
	void updateFirepowerDisplay();
	void updateMeatDisplay();
	void updateRocketDisplay();
	void updateOverheatBar();
	void updateBossBar();

	void drawLifesDisplay(sf::RenderTarget& target);
	void drawFirepowerDisplay(sf::RenderTarget& target);
	void drawMeatDisplay(sf::RenderTarget& target);
	void drawRocketDisplay(sf::RenderTarget& target);
	void drawOverheatBar(sf::RenderTarget& target);
	void drawBossBar(sf::RenderTarget& target);
private:
	Player* m_player;
	sf::VideoMode& m_vm;
	sf::Font m_font;
	bool m_fightingBoss;
	uint16_t m_bossBarUpdate;

	sf::RectangleShape m_lifesIcon;
	sf::RectangleShape m_firepowerIcon;
	sf::RectangleShape m_meatIcon;
	sf::RectangleShape m_rocketIcon;
	sf::Text m_lifesText;
	sf::Text m_firepowerText;
	sf::Text m_meatText;
	sf::Text m_rocketText;
	std::string m_lifesString;
	std::string m_firepowerString;
	std::string m_meatString;
	std::string m_rocketString;

	ProgressBar* m_overheatBar;
	ProgressBar* m_bossBar;
};

