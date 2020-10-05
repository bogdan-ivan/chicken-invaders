#include "CustomizationState.h"
#include <iostream>
#include "Statistics.h"

CustomizationState::CustomizationState(StateData* stateData)
	:State(stateData)
{
	initializeFonts();
	initializeGui();
	initializePreviews();
	Statistics::increaseKeys(150);
}

CustomizationState::~CustomizationState()
{
	for (auto& b : m_buttons)
	{
		delete b.second;
	}
	for (auto& list : m_dropDownLists)
	{
		delete list.second;
	}
}

void CustomizationState::updateInput(const float& deltaTime)
{

}

void CustomizationState::update(const float& deltaTime)
{
	updateKeytime(deltaTime);
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void CustomizationState::updateGui(const float& deltaTime)
{
	for (auto& b : m_buttons)
	{
		b.second->update(m_mousePosView);
	}

	if (m_buttons["BUY_RED"]->isPressed() && Statistics::getKeys() >= 50 && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		Statistics::decreaseKeys(50);
		m_buttons["BUY_RED"]->setText("Unlocked");
		std::cout << m_buttons["BUY_RED"]->getId() << std::endl;
	}

	if (m_buttons["BUY_BLUE"]->isPressed() && Statistics::getKeys() >= 50 && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		Statistics::decreaseKeys(50);
		m_buttons["BUY_BLUE"]->setText("Unlocked");
		std::cout << m_buttons["BUY_BLUE"]->getId() << std::endl;	
	}

	if (m_buttons["BUY_PURPLE"]->isPressed() && Statistics::getKeys() >= 50 && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		Statistics::decreaseKeys(50);
		m_buttons["BUY_PURPLE"]->setText("Unlocked");
	}

	if (m_buttons["BUY_YELLOW"]->isPressed() && Statistics::getKeys() >= 50 && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		Statistics::decreaseKeys(50);
		m_buttons["BUY_YELLOW"]->setText("Unlocked");
	}

	if (m_buttons["EXIT_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		endState();
	}

	for (auto& list : m_dropDownLists)
	{
		list.second->update(m_mousePosView, deltaTime);
	}

	switch (m_dropDownLists["COLORS"]->getActiveElementId())
	{
	case 0:
	{
		m_playerColor = "Player";
		m_previewPlayer.setTexture(TextureCache::getTexture("Player"));
		break;
	}
	case 1:
	{
		m_playerColor = "PlayerRed";
		m_previewPlayer.setTexture(TextureCache::getTexture("PlayerRed"));
		break;
	}
	case 2:
	{
		m_playerColor = "PlayerBlue";
		m_previewPlayer.setTexture(TextureCache::getTexture("PlayerBlue"));
		break;
	}
	case 3:
	{
		m_playerColor = "PlayerPurple";
		m_previewPlayer.setTexture(TextureCache::getTexture("PlayerPurple"));
		break;
	}
	case 4:
	{
		m_playerColor = "PlayerYellow";
		m_previewPlayer.setTexture(TextureCache::getTexture("PlayerYellow"));
		break;
	}
	default:
		break;
	}

	switch (m_dropDownLists["ENGINES"]->getActiveElementId())
	{
	case 0:
	{
		m_engineColor = "JetEngine2";
		m_previewEngine.setTexture(TextureCache::getTexture("JetEngine2"));
		break;
	}
	case 1:
	{
		m_engineColor = "JetEngine2Red";
		m_previewEngine.setTexture(TextureCache::getTexture("JetEngine2Red"));
		break;
	}
	case 2:
	{
		m_engineColor = "JetEngine2Green";
		m_previewEngine.setTexture(TextureCache::getTexture("JetEngine2Green"));
		break;
	}
	case 3:
	{
		m_engineColor = "JetEngine2Purple";
		m_previewEngine.setTexture(TextureCache::getTexture("JetEngine2Purple"));
		break;
	}
	case 4:
	{
		m_engineColor = "JetEngine2Yellow";
		m_previewEngine.setTexture(TextureCache::getTexture("JetEngine2Yellow"));
		break;
	}
	default:
		break;
	}

	m_keyText.setString("Keys: " + std::to_string(Statistics::getKeys()));

}

void CustomizationState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawGui(*target);
	target->draw(m_titleText);
	target->draw(m_failText);
	target->draw(m_keyText);
	target->draw(m_optionsText);
}

void CustomizationState::drawGui(sf::RenderTarget& target)
{
	for (auto& b : m_buttons)
	{
		b.second->draw(target);
	}
	for (auto& list : m_dropDownLists)
	{
		list.second->draw(target);
	}
	target.draw(m_previewPlayer);
	target.draw(m_previewEngine);
}

std::string CustomizationState::getPlayerColor()
{
	return m_playerColor;
}

std::string CustomizationState::getEngineColor()
{
	return m_engineColor;
}

void CustomizationState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void CustomizationState::initializeGui()
{
	m_buttons["BUY_RED"] = new Button(p2pX(10.f), p2pY(35.f), p2pX(22.f), p2pY(7.f),
		&m_font, "Buy red \n 50 keys", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["BUY_BLUE"] = new Button(p2pX(10.f), p2pY(45.f), p2pX(22.f), p2pY(7.f),
		&m_font, "Buy blue \n 50 keys", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50) , 1
	);

	m_buttons["BUY_PURPLE"] = new Button(p2pX(10.f), p2pY(55.f), p2pX(22.f), p2pY(7.f),
		&m_font, "Buy purple \n 50 keys", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50), 2
	);

	m_buttons["BUY_YELLOW"] = new Button(p2pX(10.f), p2pY(65.f), p2pX(22.f), p2pY(7.f),
		&m_font, "Buy yellow \n 50 keys", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50), 3
	);

	m_buttons["EXIT_STATE"] = new Button(p2pX(40.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Back", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	std::string playerColors[] = { "Default","Red","Blue","Purple","Yellow" };
	m_dropDownLists["COLORS"] = new DropDownList(p2pX(42.f), p2pY(30.f), p2pX(10.f), p2pY(5.f), m_font, playerColors, 5);

	std::string engineColors[] = { "Default","Red","Green","Purple","Yellow" };
	m_dropDownLists["ENGINES"] = new DropDownList(p2pX(52.f), p2pY(30.f), p2pX(10.f), p2pY(5.f), m_font, engineColors, 5);

	initializeBackground();
	initializeText();

}

void CustomizationState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void CustomizationState::initializeText()
{
	m_titleText.setFont(m_font);
	m_titleText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(10.f)));
	m_titleText.setCharacterSize(charSize(60));
	m_titleText.setFillColor(sf::Color(255, 255, 255, 200));
	m_titleText.setString("Customize your ship");

	m_failText.setFont(m_font);
	m_failText.setPosition(sf::Vector2f(p2pX(15.f), p2pY(25.f)));
	m_failText.setCharacterSize(charSize(60));
	m_failText.setFillColor(sf::Color(255, 255, 255, 200));
	m_failText.setString("Shop");

	m_keyText.setFont(m_font);
	m_keyText.setPosition(sf::Vector2f(p2pX(65.f), p2pY(10.f)));
	m_keyText.setCharacterSize(charSize(60));
	m_keyText.setFillColor(sf::Color(255, 255, 255, 200));
	m_keyText.setString("Keys: " + std::to_string(Statistics::getKeys()));

	m_optionsText.setFont(m_font);
	m_optionsText.setPosition(sf::Vector2f(p2pX(43.f), p2pY(25.f)));
	m_optionsText.setCharacterSize(charSize(100));
	m_optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	m_optionsText.setString("Player   Engine");

}

void CustomizationState::initializePreviews()
{
	m_playerRect.width = TextureCache::getTexture("Player")->getSize().x / 2;
	m_playerRect.height = TextureCache::getTexture("Player")->getSize().y / 9;
	m_playerRect.left = 0;
	m_playerRect.top = 0;

	m_engineRect.width = TextureCache::getTexture("JetEngine2")->getSize().x / 8;
	m_engineRect.height = TextureCache::getTexture("JetEngine2")->getSize().y / 4;
	m_engineRect.left = 0;
	m_engineRect.top = 0;

	m_previewPlayer.setSize(sf::Vector2f(p2pX(14), p2pY(15)));
	m_previewPlayer.setOrigin(m_previewPlayer.getSize().x / 2, m_previewPlayer.getSize().y / 2);
	m_previewPlayer.setPosition(p2pX(80), p2pY(35));
	m_previewPlayer.setTexture(TextureCache::getTexture("Player"));
	m_previewPlayer.setTextureRect(m_playerRect);

	m_previewEngine.setSize(sf::Vector2f(p2pX(24), p2pY(25)));
	m_previewEngine.setOrigin(m_previewEngine.getSize().x / 2, m_previewEngine.getSize().y / 2);
	m_previewEngine.setPosition(p2pX(80), p2pY(60));
	m_previewEngine.setTexture(TextureCache::getTexture("JetEngine2"));
	m_previewEngine.setTextureRect(m_engineRect);
}

std::string CustomizationState::m_playerColor = "Player";
std::string CustomizationState::m_engineColor = "JetEngine2";