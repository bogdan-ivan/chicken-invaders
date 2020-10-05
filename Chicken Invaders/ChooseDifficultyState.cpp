#include "ChooseDifficultyState.h"
#include "Statistics.h"
#include "GameState.h"

ChooseDifficultyState::ChooseDifficultyState(StateData* stateData, std::string profileName, std::pair<std::string, std::string> customization)
	:State(stateData), m_profileName(profileName), m_customization(customization)
{
	initializeFonts();
	initializeGui();
	initializeBackground();
	initializeText();
	initializeDifficulties();
}

ChooseDifficultyState::~ChooseDifficultyState()
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

void ChooseDifficultyState::updateInput(const float& deltaTime)
{
}

void ChooseDifficultyState::update(const float& deltaTime)
{
	updateKeytime(deltaTime);
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void ChooseDifficultyState::updateGui(const float& deltaTime)
{
	for (auto& button : m_buttons)
	{
		button.second->update(m_mousePosView);
	}

	if (m_buttons["GAME_STATE_EASY"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new GameState(m_stateData, &m_difficulties["EASY"], m_profileName, m_customization, m_enableHint, m_enableAssistant));
		AudioCache::stopMusic("MainMenuTheme");
	}

	if (m_buttons["GAME_STATE_MEDIUM"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new GameState(m_stateData, &m_difficulties["MEDIUM"], m_profileName, m_customization, m_enableHint, m_enableAssistant));
		AudioCache::stopMusic("MainMenuTheme");
	}

	if (m_buttons["GAME_STATE_HARD"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new GameState(m_stateData, &m_difficulties["HARD"], m_profileName, m_customization, m_enableHint, m_enableAssistant));
		AudioCache::stopMusic("MainMenuTheme");
	}

	if (m_buttons["GAME_STATE_KING"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		m_states->push(new GameState(m_stateData, &m_difficulties["KING"], m_profileName, m_customization, m_enableHint, m_enableAssistant));
		AudioCache::stopMusic("MainMenuTheme");
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

	m_enableHint = m_dropDownLists["SMART_HINT"]->getActiveElementId();
	m_enableAssistant = m_dropDownLists["SMART_ASSISTANT"]->getActiveElementId();
}

void ChooseDifficultyState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawGui(*target);
	target->draw(m_titleText);
	target->draw(m_optionsText);
}

void ChooseDifficultyState::drawGui(sf::RenderTarget& target)
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

void ChooseDifficultyState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void ChooseDifficultyState::initializeGui()
{
	m_buttons["GAME_STATE_EASY"] = new Button(p2pX(30.f), p2pY(35.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Easy", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["GAME_STATE_MEDIUM"] = new Button(p2pX(30.f), p2pY(45.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Medium", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["GAME_STATE_HARD"] = new Button(p2pX(30.f), p2pY(55.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Hard", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["GAME_STATE_KING"] = new Button(p2pX(30.f), p2pY(65.f), p2pX(20.f), p2pY(6.f),
		&m_font, "CHICKEN KING", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	m_buttons["EXIT_STATE"] = new Button(p2pX(70.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Back", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	std::string toggle[] = { "OFF","ON" };
	m_dropDownLists["SMART_HINT"] = new DropDownList(p2pX(60.f), p2pY(35.f), p2pX(15.f), p2pY(6.f), m_font, toggle, 2);
	m_dropDownLists["SMART_ASSISTANT"] = new DropDownList(p2pX(75.f), p2pY(35.f), p2pX(15.f), p2pY(6.f), m_font, toggle, 2);
}

void ChooseDifficultyState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void ChooseDifficultyState::initializeText()
{
	m_titleText.setFont(m_font);
	m_titleText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(10.f)));
	m_titleText.setCharacterSize(charSize(45));
	m_titleText.setFillColor(sf::Color(255, 255, 255, 200));
	m_titleText.setString("Choose game difficulty");

	m_optionsText.setFont(m_font);
	m_optionsText.setPosition(sf::Vector2f(p2pX(60.f), p2pY(30.f)));
	m_optionsText.setCharacterSize(charSize(100));
	m_optionsText.setFillColor(sf::Color(255, 255, 255, 200));
	m_optionsText.setString("Smart Hint   Smart Assistant");
}

void ChooseDifficultyState::initializeDifficulties()
{
	
	GameDifficulty easy(0.3f, 0.9f, 5.0f, 1, 500, 2, 4, 0, 1000, 10, 5);
	GameDifficulty medium(0.5f, 0.7f, 4.0f, 1, 400, 1, 3, 0, 1000, 7, 4);
	GameDifficulty hard(0.7f, 0.5f, 3.0f, 2, 300, 0, 2, 0, 1000, 7, 3);
	GameDifficulty king(0.9f, 0.3f, 2.0f, 3, 200, 0, 1, 0, 500, 3, 1);

	m_difficulties.insert(std::make_pair("EASY", easy));
	m_difficulties.insert(std::make_pair("MEDIUM", medium));
	m_difficulties.insert(std::make_pair("HARD", hard));
	m_difficulties.insert(std::make_pair("KING", king));
}
