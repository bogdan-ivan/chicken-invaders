#include "AchievementsState.h"
#include <iostream>
#include "Statistics.h"

AchievementsState::AchievementsState(StateData* stateData)
	:State(stateData), m_numberOfAchievements(0)
{
	initializeFonts();
	initializeGui();
}

AchievementsState::~AchievementsState()
{
	for (auto& b : m_buttons)
	{
		delete b.second;
	}
	for (auto& list : m_dropDownLists)
	{
		delete list.second;
	}
	for (auto& bar : m_progressBars)
	{
		delete bar.second;
	}
}

void AchievementsState::updateInput(const float& deltaTime)
{

}

void AchievementsState::update(const float& deltaTime)
{
	updateKeytime(deltaTime);
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void AchievementsState::updateGui(const float& deltaTime)
{
	for (auto& b : m_buttons)
	{
		b.second->update(m_mousePosView);
	}

	/*if (m_buttons["GAME_STATE"]->isPressed())
	{
		AudioCache::playSound("ButtonClick");
	}*/

	if (m_buttons["EXIT_STATE"]->isPressed() && getKeytime())
	{
		AudioCache::playSound("ButtonClick");
		endState();
	}

	for (auto& list : m_dropDownLists)
	{
		list.second->update(m_mousePosView, deltaTime);
	}

	/*for (auto& bar : m_progressBars)
	{
		bar.second->update(500);
	}*/

	m_progressBars["KILL"]->update(Statistics::getEnemiesKilled());
	m_progressBars["MEAT"]->update(Statistics::getPowerUpsCollected());
	m_progressBars["KEY"]->update(Statistics::getKeys());
	m_progressBars["DIE"]->update(Statistics::getDeaths());

}

void AchievementsState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawGui(*target);
	target->draw(m_titleText);
	target->draw(m_descriptionText);
	target->draw(m_achievementNumberText);
}

void AchievementsState::drawGui(sf::RenderTarget& target)
{
	for (auto& b : m_buttons)
	{
		b.second->draw(target);
	}
	for (auto& list : m_dropDownLists)
	{
		list.second->draw(target);
	}
	for (auto& bar : m_progressBars)
	{
		bar.second->draw(target);
	}
}

void AchievementsState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void AchievementsState::initializeGui()
{
	/*m_buttons["GAME_STATE"] = new Button(p2pX(10.f), p2pY(35.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Play", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);*/

	m_buttons["EXIT_STATE"] = new Button(p2pX(40.f), p2pY(85.f), p2pX(20.f), p2pY(6.f),
		&m_font, "Back", charSize(100),
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	/*std::string profiles[] = { "Bogdan","Radu","Dinu" };
	m_dropDownLists["PROFILES"] = new DropDownList(p2pX(42.f), p2pY(20.f), p2pX(15.f), p2pY(6.f), m_font, profiles, 3);*/

	m_progressBars["KILL"] = new ProgressBar(
		40.f, 35.f, 30.f, 8.f,
		getAchievementGoal(m_killAchievements, Statistics::getEnemiesKilled()),
		sf::Color::Blue, 220,
		m_stateData->m_gfxSettings->m_resolution, &m_font);

	m_progressBars["MEAT"] = new ProgressBar(
		40.f, 45.f, 30.f, 8.f,
		getAchievementGoal(m_killAchievements, Statistics::getPowerUpsCollected()),
		sf::Color::Blue, 220,
		m_stateData->m_gfxSettings->m_resolution, &m_font);

	m_progressBars["KEY"] = new ProgressBar(
		40.f, 55.f, 30.f, 8.f,
		getAchievementGoal(m_keyAchievements, Statistics::getKeys()),
		sf::Color::Blue, 220,
		m_stateData->m_gfxSettings->m_resolution, &m_font);

	m_progressBars["DIE"] = new ProgressBar(
		40.f, 65.f, 30.f, 8.f,
		getAchievementGoal(m_dieAchievements, Statistics::getDeaths()),
		sf::Color::Blue, 220,
		m_stateData->m_gfxSettings->m_resolution, &m_font);

	initializeBackground();
	initializeText();

}

void AchievementsState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void AchievementsState::initializeText()
{
	m_titleText.setFont(m_font);
	m_titleText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(10.f)));
	m_titleText.setCharacterSize(charSize(50));
	m_titleText.setFillColor(sf::Color(255, 255, 255, 200));
	m_titleText.setString("Achievements");

	m_descriptionText.setFont(m_font);
	m_descriptionText.setPosition(sf::Vector2f(p2pX(10.f), p2pY(30.f)));
	m_descriptionText.setCharacterSize(charSize(47));
	m_descriptionText.setFillColor(sf::Color(255, 255, 255, 200));
	m_descriptionText.setString("Kill \n\nMeat \n\nKey \n\nDie");

	m_achievementNumberText.setFont(m_font);
	m_achievementNumberText.setPosition(sf::Vector2f(p2pX(50.f), p2pY(10.f)));
	m_achievementNumberText.setCharacterSize(charSize(47));
	m_achievementNumberText.setFillColor(sf::Color(255, 255, 255, 200));
	m_achievementNumberText.setString("Total: " + std::to_string(m_numberOfAchievements));
}

int AchievementsState::getAchievementGoal(const std::vector<int>& goals, int stat)
{
	int goal = 0;
	for (int i = 0; i < goals.size(); ++i)
	{
		if (goals[i] <= stat)
			++goal;
	}
	m_numberOfAchievements += goal;
	return goals[goal];
}

