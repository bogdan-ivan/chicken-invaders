#pragma once
#include "State.h"
#include "Button.h"

class MultiplayerState :
	public State
{
public:
	MultiplayerState(StateData* stateData);
	~MultiplayerState();
	void updateInput(const float& deltaTime);
	void update(const float& deltaTime) override;
	void updateButtons();
	void draw(sf::RenderTarget* target = nullptr) override;
	void drawButtons(sf::RenderTarget& target);
private:
	void initializeFonts();
	void initializeButtons();
	void initializeBackground();
	void initializeText();
private:
	sf::Font m_font;
	sf::RectangleShape m_background;
	Button* m_gameStateButton;
	std::map<std::string, Button*> m_buttons;
	sf::Text m_titleText;
};

