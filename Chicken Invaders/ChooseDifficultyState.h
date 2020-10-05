#pragma once
#include <map>
#include <string>
#include "State.h"
#include "Button.h"
#include "DropDownList.h"
#include "GameDifficulty.h"

class ChooseDifficultyState 
	: public State
{
public:
	ChooseDifficultyState(StateData* stateData, std::string profileName, std::pair<std::string,std::string> customization);
	~ChooseDifficultyState();
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
	void initializeDifficulties();
private:
	sf::Font m_font;
	sf::RectangleShape m_background;
	std::map<std::string, Button*> m_buttons;
	std::map<std::string, DropDownList*> m_dropDownLists;
	sf::Text m_titleText;
	sf::Text m_optionsText;
	std::map <std::string, GameDifficulty> m_difficulties;
	std::string m_profileName;
	std::pair<std::string, std::string> m_customization;
	bool m_enableHint;
	bool m_enableAssistant;
};

