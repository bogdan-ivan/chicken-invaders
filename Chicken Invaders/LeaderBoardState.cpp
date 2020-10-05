#include "LeaderBoardState.h"
#include "GameState.h"
#include <iostream>

LeaderBoardState::LeaderBoardState(StateData* stateData)
	:State(stateData)
{
	initFonts();
	initGui();
	initializeLeaderboard();
	initializeText();
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("Game2"));
}

LeaderBoardState::~LeaderBoardState()
{
	for (auto& b : m_buttons)
	{
		delete b.second;
	}
	for (auto& list : m_dropDownLists)
	{
		delete list.second;
	}
	delete m_highScoreBoard;
}

void LeaderBoardState::updateInput(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		endState();
}

void LeaderBoardState::update(const float& deltaTime)
{
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void LeaderBoardState::updateGui(const float& deltaTime)
{

	m_optionsText.setString(m_highScoreBoard->getString());

	for (auto& b : m_buttons)
	{
		b.second->update(m_mousePosView);
	}

	if (m_buttons["RESET_LEADERBOARD"]->isPressed() && m_dropDownLists["CHOICE"]->getActiveElementId() == 1)
	{
		AudioCache::playSound("ButtonClick");
		HighScoreBoard::resetScore();
	}

	if (m_buttons["BACK"]->isPressed())
	{
		AudioCache::playSound("ButtonClick");
		endState();
	}

	for (auto& list : m_dropDownLists)
	{
		list.second->update(m_mousePosView, deltaTime);
	}
}

void LeaderBoardState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawGui(*target);
	target->draw(m_optionsText);
}

void LeaderBoardState::drawGui(sf::RenderTarget& target)
{
	for (auto& b : m_buttons)
	{
		b.second->draw(target);
	}
	for (auto& list : m_dropDownLists)
	{
		list.second->draw(target);
	}
}

void LeaderBoardState::initFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void LeaderBoardState::initGui()
{
	m_buttons["RESET_LEADERBOARD"] = new Button(p2pX(5.f), p2pY(15.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Reset", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["BACK"] = new Button(p2pX(70.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Back", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	std::string sure[] = { "NO","YES" };
	m_dropDownLists["CHOICE"] = new DropDownList(p2pX(5.f), p2pY(25.f), p2pX(20.f), p2pY(6.f), m_font, sure, 2);
}

void LeaderBoardState::initializeText()
{
	m_optionsText.setFont(m_font);
	m_optionsText.setPosition(sf::Vector2f(p2pX(35.f), p2pY(15.f)));
	m_optionsText.setCharacterSize(charSize(40));
	m_optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	m_optionsText.setString(m_highScoreBoard->getString());
}

void LeaderBoardState::initializeLeaderboard()
{
	m_highScoreBoard = new HighScoreBoard();
}
