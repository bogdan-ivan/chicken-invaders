#pragma once
#include "State.h"
#include "Button.h"
#include "DropDownList.h"

class CreditsState :
	public State
{
public:
	CreditsState(StateData* stateData);
	~CreditsState();
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
	std::map<std::string, DropDownList*> m_dropDownLists;

	sf::Text m_optionsText;
	std::vector<sf::VideoMode> m_modes;
};


