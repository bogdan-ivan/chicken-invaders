#include "MainMenuState.h"
#include "LeaderBoardState.h"
#include "PreGameState.h"
#include "SettingsState.h"
#include "CreditsState.h"
#include "Statistics.h"
#include <iostream>

MainMenuState::MainMenuState(StateData* stateData, sf::Event& event)
	:State(stateData), m_addProfile(false), m_event(event)
{
	initializeFonts();
	initializeProfiles();
	initializeGui();
	resetGui();
	AudioCache::playMusic("MainMenuTheme");
}

MainMenuState::~MainMenuState()
{
	for (auto& b : m_buttons)
	{
		delete b.second;
	}
	for (auto& list : m_dropDownLists)
	{
		delete list.second;
	}
	saveToFile("..//Config//Profiles.ini");
}

void MainMenuState::updateInput(const float& deltaTime)
{
	
	if (m_addProfile)
	{
		if (m_event.type == sf::Event::TextEntered)
		{
			std::cout << m_event.text.unicode << std::endl;
			if (m_event.text.unicode == 8)
			{
				if (!m_playerInput.empty() && getKeytime())
				{
					m_playerInput.pop_back();
				}
			}
			else if (m_event.text.unicode == 13 )
			{
				m_addProfile = false;
				m_profiles.pop_back();
				m_profiles.push_back(m_playerInput);
				m_profiles.push_back("New_Profile");
				refreshProfiles();
				std::ofstream ofile("..//Profiles//" + m_playerInput + ".ini");
				for (int i = 0; i < Statistics::getNumberOfPowersUps(); ++i)
					ofile << 0 << std::endl;
			}
			else if(getKeytime())
				m_playerInput += m_event.text.unicode;
			m_playerText.setString(m_playerInput);
		}
	}
}

void MainMenuState::update(const float& deltaTime)
{
	updateKeytime(deltaTime);
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void MainMenuState::updateGui(const float& deltaTime)
{
	for (auto& b : m_buttons)
	{
		b.second->update(m_mousePosView);
	}

	if (m_buttons["PRE_GAME_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new PreGameState(m_stateData, m_profiles[m_dropDownLists["PROFILES"]->getActiveElementId()]));
	}

	if (m_buttons["LEADERBOARD_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new LeaderBoardState(m_stateData));
	}

	if (m_buttons["SETTINGS_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new SettingsState(m_stateData));
	}

	if (m_buttons["CREDITS_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new CreditsState(m_stateData));
	}

	if (m_buttons["DELETE_PROFILE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		deleteProfile();
	}

	if (m_buttons["EXIT_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		endState();
		AudioCache::stopMusic("BlindingLights");
	}

	for (auto& list : m_dropDownLists)
	{
		list.second->update(m_mousePosView, deltaTime);
	}

	if (m_dropDownLists["PROFILES"]->getActiveElementId() == m_profiles.size() - 1)
	{
		m_addProfile = true;
	}
	else
		m_addProfile = false;

}

void MainMenuState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawGui(*target);
	target->draw(m_titleText);
	if(m_addProfile)
		target->draw(m_playerText);
}

void MainMenuState::drawGui(sf::RenderTarget& target)
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

void MainMenuState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void MainMenuState::initializeGui()
{
	m_buttons["PRE_GAME_STATE"] = new Button(p2pX(40.f), p2pY(42.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Play", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["LEADERBOARD_STATE"] = new Button(p2pX(40.f), p2pY(52.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Leaderboards", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["SETTINGS_STATE"] = new Button(p2pX(40.f), p2pY(62.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Settings", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["CREDITS_STATE"] = new Button(p2pX(40.f), p2pY(72.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Credits", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["DELETE_PROFILE"] = new Button(p2pX(60.f), p2pY(24.f), p2pX(10.f), p2pY(3.f),
		&m_font, "Delete", charSize(130),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["EXIT_STATE"] = new Button(p2pX(40.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Quit", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	
	std::string* profilesPointer = new std::string[m_profiles.size()];
	for (int i = 0; i < m_profiles.size(); ++i)
		profilesPointer[i] = m_profiles[i];
	m_dropDownLists["PROFILES"] = new DropDownList(p2pX(42.f), p2pY(24.f), p2pX(15.f), p2pY(6.f), m_font, profilesPointer, m_profiles.size());
	
	initializeBackground();
	initializeText();

}

void MainMenuState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void MainMenuState::initializeText()
{
	m_titleText.setFont(m_font);
	m_titleText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(10.f)));
	m_titleText.setCharacterSize(charSize(60));
	m_titleText.setFillColor(sf::Color(255, 255, 255, 200));
	m_titleText.setString(m_stateData->m_gfxSettings->m_title + "\n\n\n           Hello ");

	m_playerText.setFont(m_font);
	m_playerText.setPosition(sf::Vector2f(p2pX(50.f), p2pY(50.f)));
	m_playerText.setCharacterSize(charSize(60));
	m_playerText.setFillColor(sf::Color(255, 255, 255, 200));
	m_playerText.setString("");
}

void MainMenuState::initializeProfiles()
{
	loadFromFile("..//Config//Profiles.ini");
}

void MainMenuState::resetGui()
{
	auto it = m_buttons.begin();
	for (it = m_buttons.begin(); it != m_buttons.end(); ++it)
	{
		delete it->second;
	}
	m_buttons.clear();

	auto it2 = m_dropDownLists.begin();
	for (it2 = m_dropDownLists.begin(); it2 != m_dropDownLists.end(); ++it2)
	{
		delete it2->second;
	}
	m_dropDownLists.clear();

	initializeGui();
}

void MainMenuState::saveToFile(const std::string path)
{
	std::ofstream output(path);
	if (!output.good())
		//logger->log(LoggingLevel::ERROR, "Failed to open Window.ini");
		std::cerr << "Failed to open Profiles.ini" << std::endl;
	else
	{
		output << m_profiles.size() << std::endl;
		for (auto& profile : m_profiles)
		{
			output << profile << std::endl;
		}
	}
	output.close();
}

void MainMenuState::loadFromFile(const std::string path)
{
	std::ifstream input(path);
	int numberOfProfiles = 0;
	if (!input.good())
		//logger->log(LoggingLevel::ERROR, "Failed to open Window.ini");
		std::cerr << "Failed to open Profiles.ini" << std::endl;
	else
	{
		input >> numberOfProfiles;
		std::string buffer;
		for (int i = 0; i < numberOfProfiles; ++i)
		{
			input >> buffer;
			m_profiles.push_back(std::move(buffer));
		}
	}
	input.close();
}

void MainMenuState::refreshProfiles()
{
	std::string* profilesPointer = new std::string[m_profiles.size()];
	for (int i = 0; i < m_profiles.size(); ++i)
		profilesPointer[i] = m_profiles[i];
	m_dropDownLists["PROFILES"] = new DropDownList(p2pX(42.f), p2pY(20.f), p2pX(15.f), p2pY(6.f), m_font, profilesPointer, m_profiles.size());
	m_dropDownLists["PROFILES"]->setActiveElementId(0);
}

void MainMenuState::deleteProfile()
{
	if (m_profiles.size() > 1 && m_dropDownLists["PROFILES"]->getActiveElementId() != m_profiles.size() - 1)
	{
		auto toDelete = m_dropDownLists["PROFILES"]->getActiveElementId();
		m_profiles.erase(m_profiles.begin() + toDelete);
		refreshProfiles();
	}
}
