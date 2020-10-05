#include "MultiplayerState.h"
#include "GameState.h"
#include <iostream>

MultiplayerState::MultiplayerState(StateData* stateData)
	:State(stateData)
{
	initializeFonts();
	initializeButtons();
	initializeBackground();
	initializeText();
}

MultiplayerState::~MultiplayerState()
{
	for (auto& b : m_buttons)
	{
		delete b.second;
	}
}

void MultiplayerState::updateInput(const float& deltaTime)
{

}

void MultiplayerState::update(const float& deltaTime)
{
	updateMousePositions();
	updateInput(deltaTime);
	updateButtons();
}

void MultiplayerState::updateButtons()
{
	for (auto& b : m_buttons)
	{
		b.second->update(m_mousePosView);
	}

	if (m_buttons["HOST_GAME"]->isPressed())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new GameState(m_stateData,nullptr,"",std::make_pair("",""),0,0));
		AudioCache::stopMusic("BlindingLights");
	}

	if (m_buttons["CONNECT_TO_SERVER"]->isPressed())
	{
		AudioCache::playSound("ButtonClick");
		//m_states->push(new GameState(m_stateData, nullptr));
		AudioCache::stopMusic("BlindingLights");
	}

	if (m_buttons["EXIT_STATE"]->isPressed())
	{
		AudioCache::playSound("ButtonClick");
		endState();
	}
}

void MultiplayerState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawButtons(*target);
	target->draw(m_titleText);
}

void MultiplayerState::drawButtons(sf::RenderTarget& target)
{
	for (auto& b : m_buttons)
	{
		b.second->draw(target);
	}
}

void MultiplayerState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void MultiplayerState::initializeButtons()
{
	m_buttons["HOST_GAME"] = new Button(p2pX(50.f), p2pY(35.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Host", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);
	m_buttons["CONNECT_TO_SERVER"] = new Button(p2pX(50.f), p2pY(45.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Connect", charSize(100),
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

void MultiplayerState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void MultiplayerState::initializeText()
{
	m_titleText.setFont(m_font);
	m_titleText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(10.f)));
	m_titleText.setCharacterSize(charSize(40));
	m_titleText.setFillColor(sf::Color(255, 255, 255, 200));
	m_titleText.setString("Friends are fun !");
}
