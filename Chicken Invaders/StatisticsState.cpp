#include "StatisticsState.h"

StatisticsState::StatisticsState(StateData* stateData)
	:State(stateData)
{
	initializeFonts();
	initializeGui();
	initializeBackground();
	initializeText();
}

StatisticsState::~StatisticsState()
{
	for (auto& button : m_buttons)
	{
		delete button.second;
	}
}

void StatisticsState::updateInput(const float& deltaTime)
{

}

void StatisticsState::update(const float& deltaTime)
{
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void StatisticsState::updateGui(const float& deltaTime)
{
	for (auto& button : m_buttons)
	{
		button.second->update(m_mousePosView);
	}

	if (m_buttons["BACK"]->isPressed())
	{
		AudioCache::playSound("ButtonClick");
		endState();
	}
}

void StatisticsState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawGui(*target);
	target->draw(m_optionsText);
	target->draw(m_valuesText);
	target->draw(m_titleText);
}

void StatisticsState::drawGui(sf::RenderTarget& target)
{
	for (auto& button : m_buttons)
	{
		button.second->draw(target);
	}
}

void StatisticsState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void StatisticsState::initializeGui()
{
	m_buttons["BACK"] = new Button(p2pX(40.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Back", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

}

void StatisticsState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void StatisticsState::initializeText()
{
	m_optionsText.setFont(m_font);
	m_optionsText.setPosition(sf::Vector2f(p2pX(15.f), p2pY(15.f)));
	m_optionsText.setCharacterSize(charSize(60));
	m_optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	m_optionsText.setString(
		"Shots fired \nShots hit \nAccuracy \nEnemies killed \nDeaths \nRockets Used \nPowerUps Collected \nKeys");
	m_valuesText.setFont(m_font);
	m_valuesText.setPosition(sf::Vector2f(p2pX(65.f), p2pY(15.f)));
	m_valuesText.setCharacterSize(charSize(60));
	m_valuesText.setFillColor(sf::Color(255, 255, 255, 200));
	m_valuesText.setString(
		std::to_string(Statistics::getShotsFired()) + "\n" + std::to_string(Statistics::getShotsHit()) + "\n"
		+ std::to_string(Statistics::getAccuracy()) + "%\n" + std::to_string(Statistics::getEnemiesKilled()) + "\n"
		+ std::to_string(Statistics::getDeaths()) + "\n" + std::to_string(Statistics::getRocketsUsed()) + "\n"
		+ std::to_string(Statistics::getPowerUpsCollected()) + "\n" + std::to_string(Statistics::getKeys()));
	m_titleText.setFont(m_font);
	m_titleText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(10.f)));
	m_titleText.setCharacterSize(charSize(60));
	m_titleText.setFillColor(sf::Color(255, 255, 255, 200));
	m_titleText.setString("Statistics");
}
