#pragma once
#include "State.h"
#include "Button.h"
#include "DropDownList.h"
#include "ProgressBar.h"

class AchievementsState :
	public State
{
public:
	AchievementsState(StateData* stateData);
	~AchievementsState();
	void updateInput(const float& deltaTime);
	void update(const float& deltaTime) override;
	void updateGui(const float& deltaTime);
	void draw(sf::RenderTarget* target = nullptr) override;
	void drawGui(sf::RenderTarget& target);
private:
	void initializeFonts();
	void initializeGui();
	void initializeBackground();
	void initializeText();

	int getAchievementGoal(const std::vector<int>& goals, int stat);
private:
	sf::Font m_font;
	sf::RectangleShape m_background;
	Button* m_gameStateButton;
	std::map<std::string, Button*> m_buttons;
	std::map<std::string, DropDownList*> m_dropDownLists;
	std::map<std::string, ProgressBar*> m_progressBars;
	sf::Text m_titleText;
	sf::Text m_descriptionText;
	sf::Text m_achievementNumberText;
	int m_numberOfAchievements;

	std::vector<int> m_killAchievements{ 100,500,1000,2000,5000,7500,10000,12500,15000 };
	std::vector<int> m_keyAchievements{ 5,25,50,100,200,300,400 };
	std::vector<int> m_dieAchievements{ 1,5,10,20,50,100,200,300,400 };
};

