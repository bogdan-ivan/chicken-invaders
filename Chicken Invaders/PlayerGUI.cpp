#include "PlayerGUI.h"
#include <iostream>
#include "Gui.h"

PlayerGUI::PlayerGUI(Player* player, sf::VideoMode& vm)
	:m_player(player), m_vm(vm), m_fightingBoss(false), m_bossBarUpdate(0)
{
	initializeFont();
	initializeLifesDisplay();
	initializeFirepowerDisplay();
	initializeMeatDisplay();
	initializeRocketDisplay();
	initializeOverheatBar();
	initializeBossBar();
}

PlayerGUI::~PlayerGUI()
{
	delete m_overheatBar;
	delete m_bossBar;
}

void PlayerGUI::update(const float& deltaTime)
{
	updateLifesDisplay();
	updateFirepowerDisplay();
	updateMeatDisplay();
	updateRocketDisplay();
	updateOverheatBar();
	if(m_fightingBoss)
		updateBossBar();
}

void PlayerGUI::draw(sf::RenderTarget& target)
{
	drawLifesDisplay(target);
	drawFirepowerDisplay(target);
	drawMeatDisplay(target);
	drawRocketDisplay(target);
	drawOverheatBar(target);
	if (m_fightingBoss)
		drawBossBar(target);
}

void PlayerGUI::enableBossBar(uint16_t hp)
{
	m_fightingBoss = true;
	m_bossBarUpdate = hp;
}

void PlayerGUI::disableBossBar()
{
	m_fightingBoss = false;
}

void PlayerGUI::initializeFont()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void PlayerGUI::initializeLifesDisplay()
{
	m_lifesIcon.setSize(sf::Vector2f(Gui::p2pX(3.f, m_vm), Gui::p2pY(4.f, m_vm)));
	m_lifesIcon.setTexture(TextureCache::getTexture("LifesIcon"));
	m_lifesIcon.setPosition(Gui::p2pX(2.f, m_vm), Gui::p2pY(90.f, m_vm));

	m_lifesText.setFont(m_font);
	m_lifesText.setPosition(sf::Vector2f(Gui::p2pX(3.f, m_vm), Gui::p2pY(85.f, m_vm)));
	m_lifesText.setCharacterSize(Gui::charSize(80, m_vm));
	m_lifesText.setFillColor(sf::Color(255, 255, 255, 200));
	m_lifesText.setString("XXX");
}

void PlayerGUI::initializeFirepowerDisplay()
{
	m_firepowerIcon.setSize(sf::Vector2f(Gui::p2pX(3.f, m_vm), Gui::p2pY(4.f, m_vm)));
	m_firepowerIcon.setTexture(TextureCache::getTexture("FirepowerIcon"));
	m_firepowerIcon.setPosition(Gui::p2pX(7.f, m_vm), Gui::p2pY(90.f, m_vm));

	m_firepowerText.setFont(m_font);
	m_firepowerText.setPosition(sf::Vector2f(Gui::p2pX(8.f, m_vm), Gui::p2pY(85.f, m_vm)));
	m_firepowerText.setCharacterSize(Gui::charSize(80, m_vm));
	m_firepowerText.setFillColor(sf::Color(255, 255, 255, 200));
	m_firepowerText.setString("XXX");
}

void PlayerGUI::initializeMeatDisplay()
{
	m_meatIcon.setSize(sf::Vector2f(Gui::p2pX(3.f, m_vm), Gui::p2pY(4.f, m_vm)));
	m_meatIcon.setTexture(TextureCache::getTexture("MeatIcon"));
	m_meatIcon.setPosition(Gui::p2pX(12.f, m_vm), Gui::p2pY(90.f, m_vm));

	m_meatText.setFont(m_font);
	m_meatText.setPosition(sf::Vector2f(Gui::p2pX(13.f, m_vm), Gui::p2pY(85.f, m_vm)));
	m_meatText.setCharacterSize(Gui::charSize(80, m_vm));
	m_meatText.setFillColor(sf::Color(255, 255, 255, 200));
	m_meatText.setString("XXX");
}

void PlayerGUI::initializeRocketDisplay()
{
	m_rocketIcon.setSize(sf::Vector2f(Gui::p2pX(3.f, m_vm), Gui::p2pY(4.f, m_vm)));
	m_rocketIcon.setTexture(TextureCache::getTexture("RocketIcon"));
	m_rocketIcon.setPosition(Gui::p2pX(17.f, m_vm), Gui::p2pY(90.f, m_vm));

	m_rocketText.setFont(m_font);
	m_rocketText.setPosition(sf::Vector2f(Gui::p2pX(18.f, m_vm), Gui::p2pY(85.f, m_vm)));
	m_rocketText.setCharacterSize(Gui::charSize(80, m_vm));
	m_rocketText.setFillColor(sf::Color(255, 255, 255, 200));
	m_rocketText.setString("XXX");
}

void PlayerGUI::initializeOverheatBar()
{
	m_overheatBar = new ProgressBar(
		1.f, 7.6f, 13.4f, 3.9f,
		m_player->getMaxOverheat(),
		sf::Color::Blue, 220,
		m_vm, &m_font);
}

void PlayerGUI::initializeBossBar()
{
	m_bossBar = new ProgressBar(
		30.f, 2.6f, 35.0f, 3.9f,
		50,
		sf::Color::Red, 220,
		m_vm, &m_font);
}

void PlayerGUI::updateLifesDisplay()
{
	m_lifesString = std::to_string(m_player->getLifes());
	m_lifesText.setString(m_lifesString);
}

void PlayerGUI::updateFirepowerDisplay()
{
	m_firepowerString = std::to_string(m_player->getFirepower());
	m_firepowerText.setString(m_firepowerString);
}

void PlayerGUI::updateMeatDisplay()
{
	m_meatString = std::to_string(m_player->getMeats());
	m_meatText.setString(m_meatString);
}

void PlayerGUI::updateRocketDisplay()
{
	m_rocketString = std::to_string(m_player->getRockets());
	m_rocketText.setString(m_rocketString);
}

void PlayerGUI::updateOverheatBar()
{
	m_overheatBar->update(m_player->getOverheat());
}

void PlayerGUI::updateBossBar()
{
	m_bossBar->update(m_bossBarUpdate);
}

void PlayerGUI::drawLifesDisplay(sf::RenderTarget& target)
{
	target.draw(m_lifesIcon);
	target.draw(m_lifesText);
}

void PlayerGUI::drawFirepowerDisplay(sf::RenderTarget& target)
{
	target.draw(m_firepowerIcon);
	target.draw(m_firepowerText);
}

void PlayerGUI::drawMeatDisplay(sf::RenderTarget& target)
{
	target.draw(m_meatIcon);
	target.draw(m_meatText);
}

void PlayerGUI::drawRocketDisplay(sf::RenderTarget& target)
{
	target.draw(m_rocketIcon);
	target.draw(m_rocketText);
}

void PlayerGUI::drawOverheatBar(sf::RenderTarget& target)
{
	m_overheatBar->draw(target);
}

void PlayerGUI::drawBossBar(sf::RenderTarget& target)
{
	m_bossBar->draw(target);
}




