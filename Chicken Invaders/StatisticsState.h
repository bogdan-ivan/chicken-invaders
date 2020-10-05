#pragma once
#include "State.h"
#include "Button.h"
#include "Statistics.h"

class StatisticsState :
	public State
{
public:
	StatisticsState(StateData* stateData);
	~StatisticsState();
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
private:
	sf::Font m_font;
	sf::RectangleShape m_background;
	Button* m_gameStateButton;
	std::map<std::string, Button*> m_buttons;
	sf::Text m_titleText;
	sf::Text m_optionsText;
	sf::Text m_valuesText;
};

