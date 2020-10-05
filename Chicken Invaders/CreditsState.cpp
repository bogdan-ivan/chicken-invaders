#include "CreditsState.h"
#include <sstream>

CreditsState::CreditsState(StateData* stateData)
	:State(stateData)
{
	initializeFonts();
	initializeGui();
	initializeBackground();
	initializeText();
}

CreditsState::~CreditsState()
{
	for (auto& button : m_buttons)
	{
		delete button.second;
	}
	for (auto& list : m_dropDownLists)
	{
		delete list.second;
	}
}

void CreditsState::updateInput(const float& deltaTime)
{

}

void CreditsState::update(const float& deltaTime)
{
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void CreditsState::updateGui(const float& deltaTime)
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

	

	
	for (auto& list : m_dropDownLists)
	{
		list.second->update(m_mousePosView, deltaTime);
	}
}

void CreditsState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawGui(*target);
	target->draw(m_optionsText);

	//REMOVE LATER!!!
	sf::Text mouseText;
	mouseText.setPosition(m_mousePosView.x, m_mousePosView.y - 50);
	mouseText.setFont(m_font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << m_mousePosView.x << " " << m_mousePosView.y;
	mouseText.setString(ss.str());
	target->draw(mouseText);
}

void CreditsState::drawGui(sf::RenderTarget& target)
{
	for (auto& button : m_buttons)
	{
		button.second->draw(target);
	}
	for (auto& list : m_dropDownLists)
	{
		list.second->draw(target);
	}
}

void CreditsState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void CreditsState::initializeGui()
{
	m_modes = sf::VideoMode::getFullscreenModes();

	m_buttons["BACK"] = new Button(p2pX(70.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Back", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	//std::string toggle[] = { "OFF","ON" };
	//m_dropDownLists["FULLSCREEN"] = new DropDownList(600, 210, 200, 50, m_font, toggle, 2);
	
}

void CreditsState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void CreditsState::initializeText()
{
	m_optionsText.setFont(m_font);
	m_optionsText.setPosition(sf::Vector2f(p2pX(15.f), p2pY(15.f)));
	m_optionsText.setCharacterSize(charSize(40));
	m_optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	m_optionsText.setString(
		"Bogdan Ivan \nRadu Hrihoreanu \nDinu Garbuz");
}

