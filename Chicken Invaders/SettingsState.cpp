#include "SettingsState.h"
#include <sstream>

SettingsState::SettingsState(StateData* stateData)
	:State(stateData)
{
	initializeFonts();
	initializeGui();
}

SettingsState::~SettingsState()
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

void SettingsState::updateInput(const float& deltaTime)
{

}

void SettingsState::update(const float& deltaTime)
{
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void SettingsState::updateGui(const float& deltaTime)
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

	if (m_buttons["APPLY"]->isPressed())
	{
		AudioCache::playSound("ButtonClick");
		m_stateData->m_gfxSettings->m_resolution = m_modes[m_dropDownLists["RESOLUTION"]->getActiveElementId()];
		m_stateData->m_gfxSettings->m_fullscreen = m_dropDownLists["FULLSCREEN"]->getActiveElementId();
		m_stateData->m_gfxSettings->m_vsync = m_dropDownLists["VSYNC"]->getActiveElementId();
		m_stateData->m_gfxSettings->m_contextSettings.antialiasingLevel = m_dropDownLists["ANTIALIASING"]->getActiveElementId();
		int fpsOption = m_dropDownLists["FPS LIMIT"]->getActiveElementId();
		switch (fpsOption)
		{
		case 0:
			m_stateData->m_gfxSettings->m_frameRateLimit = 60;
			break;
		case 1:
			m_stateData->m_gfxSettings->m_frameRateLimit = 120;
			break;
		case 2:
			m_stateData->m_gfxSettings->m_frameRateLimit = 144;
			break;
		default:
			break;
		}

		applySettings();
		resetGui();
	}

	if (m_buttons["DEFAULT"]->isPressed())
	{
		AudioCache::playSound("ButtonClick");
		m_stateData->m_gfxSettings->restoreDefaults();
		applySettings();
	}

	for (auto& list : m_dropDownLists)
	{
		list.second->update(m_mousePosView, deltaTime);
	}
}

void SettingsState::draw(sf::RenderTarget* target)
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

void SettingsState::drawGui(sf::RenderTarget& target)
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

void SettingsState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void SettingsState::initializeGui()
{
	m_modes = sf::VideoMode::getFullscreenModes();

	m_buttons["BACK"] = new Button(p2pX(70.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Back", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["APPLY"] = new Button(p2pX(40.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Apply", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["DEFAULT"] = new Button(p2pX(10.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Default", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	std::vector<std::string> modes_str;
	for (auto& mode : m_modes)
	{
		modes_str.push_back(std::to_string(mode.width) + 'x' +
			std::to_string(mode.height));
	}
	std::string toggle[] = { "OFF","ON" };
	std::string level[] = { "0","1","2" };
	std::string fps[] = { "60","120","144" };
	m_dropDownLists["RESOLUTION"] = new DropDownList(p2pX(45.f), p2pY(15.f), p2pX(15.f), p2pY(6.f), m_font, modes_str.data(), modes_str.size());
	m_dropDownLists["FULLSCREEN"] = new DropDownList(p2pX(45.f), p2pY(25.f), p2pX(15.f), p2pY(6.f), m_font, toggle, 2);
	m_dropDownLists["VSYNC"] = new DropDownList(p2pX(45.f), p2pY(35.f), p2pX(15.f), p2pY(6.f), m_font, toggle, 2);
	m_dropDownLists["ANTIALIASING"] = new DropDownList(p2pX(45.f), p2pY(45.f), p2pX(15.f), p2pY(6.f), m_font, level, 3);
	m_dropDownLists["FPS LIMIT"] = new DropDownList(p2pX(45.f), p2pY(55.f), p2pX(15.f), p2pY(6.f), m_font, fps, 3);

	initializeBackground();
	initializeText();

}

void SettingsState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void SettingsState::initializeText()
{
	m_optionsText.setFont(m_font);
	m_optionsText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(15.f)));
	m_optionsText.setCharacterSize(charSize(70));
	m_optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	m_optionsText.setString(
		"Resolution \n\n\nFullscreen \n\n\nVsync \n\n\nAntialaising \n\n\nFPS Limit");
}

void SettingsState::applySettings()
{
	if (m_stateData->m_gfxSettings->m_fullscreen)
		m_window->create(m_stateData->m_gfxSettings->m_resolution, m_stateData->m_gfxSettings->m_title, sf::Style::Fullscreen,
			m_stateData->m_gfxSettings->m_contextSettings);
	else
		m_window->create(m_stateData->m_gfxSettings->m_resolution, m_stateData->m_gfxSettings->m_title, sf::Style::Default,
			m_stateData->m_gfxSettings->m_contextSettings);

	m_window->setFramerateLimit(m_stateData->m_gfxSettings->m_frameRateLimit);
	m_window->setVerticalSyncEnabled(m_stateData->m_gfxSettings->m_vsync);

	m_stateData->m_gfxSettings->saveToFile("..//Config//Window.ini");
}

void SettingsState::resetGui()
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
