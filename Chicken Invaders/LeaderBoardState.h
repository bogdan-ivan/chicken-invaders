#pragma once
#include "State.h"
#include "Button.h"
#include "DropDownList.h"
#include "HighScoreBoard.h"

class LeaderBoardState :
	public State
{
public:
	LeaderBoardState(StateData* stateData);
	~LeaderBoardState();
	void updateInput(const float& deltaTime);
	void update(const float& deltaTime) override;
	void updateGui(const float& deltaTime);
	void draw(sf::RenderTarget* target = nullptr) override;
	void drawGui(sf::RenderTarget& target);
private:
	void initFonts();
	void initGui();
	void initializeText();
	void initializeLeaderboard();
private:
	sf::Font m_font;
	sf::RectangleShape m_background;
	Button* m_gameStateButton;
	std::map<std::string, Button*> m_buttons;
	std::map<std::string, DropDownList*> m_dropDownLists;
	sf::Text m_optionsText;
	HighScoreBoard* m_highScoreBoard;
};


