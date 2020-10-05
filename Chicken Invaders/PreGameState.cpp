#include "PreGameState.h"
#include "ChooseDifficultyState.h"
#include "StatisticsState.h"
#include "MultiplayerState.h"
#include "AchievementsState.h"
#include "CustomizationState.h"
#include <iostream>

PreGameState::PreGameState(StateData* stateData, std::string profileName)
	:State(stateData), m_profileName(profileName)
{
	initializeFonts();
	initializeButtons();
	initializeBackground();
	initializeText();
	Statistics::setProfileName(profileName);
	Statistics::loadFromFile();
}

PreGameState::~PreGameState()
{
	for (auto& b : m_buttons)
	{
		delete b.second;
	}
}

void PreGameState::updateInput(const float& deltaTime)
{

}

void PreGameState::update(const float& deltaTime)
{
	updateKeytime(deltaTime);
	updateMousePositions();
	updateInput(deltaTime);
	updateButtons();
}

void PreGameState::updateButtons()
{
	for (auto& b : m_buttons)
	{
		b.second->update(m_mousePosView);
	}

	if (m_buttons["DIFFICULTY_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new ChooseDifficultyState(m_stateData, m_profileName, std::make_pair(CustomizationState::getPlayerColor(),CustomizationState::getEngineColor())));
		AudioCache::stopMusic("BlindingLights");
	}

	if (m_buttons["MULTIPLAYER_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new MultiplayerState(m_stateData));
		AudioCache::stopMusic("BlindingLights");
	}

	if (m_buttons["CUSTOMIZATION_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new CustomizationState(m_stateData));
	}

	if (m_buttons["STATISTICS_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new StatisticsState(m_stateData));
	}

	if (m_buttons["ACHIEVEMENTS_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new AchievementsState(m_stateData));
	}

	if (m_buttons["EXIT_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		endState();
	}
}

void PreGameState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawButtons(*target);
	target->draw(m_titleText);
}

void PreGameState::drawButtons(sf::RenderTarget& target)
{
	for (auto& b : m_buttons)
	{
		b.second->draw(target);
	}
}

void PreGameState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void PreGameState::initializeButtons()
{
	m_buttons["DIFFICULTY_STATE"] = new Button(p2pX(40.f), p2pY(35.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Singleplayer", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["MULTIPLAYER_STATE"] = new Button(p2pX(40.f), p2pY(45.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Multiplayer", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["CUSTOMIZATION_STATE"] = new Button(p2pX(40.f), p2pY(55.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Customization", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["STATISTICS_STATE"] = new Button(p2pX(40.f), p2pY(65.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Statistics", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["ACHIEVEMENTS_STATE"] = new Button(p2pX(40.f), p2pY(75.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Achievements", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["EXIT_STATE"] = new Button(p2pX(40.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Back", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);
}

void PreGameState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void PreGameState::initializeText()
{
	m_titleText.setFont(m_font);
	m_titleText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(10.f)));
	m_titleText.setCharacterSize(charSize(45));
	m_titleText.setFillColor(sf::Color(255, 255, 255, 200));
	m_titleText.setString("Save the world !");
}
