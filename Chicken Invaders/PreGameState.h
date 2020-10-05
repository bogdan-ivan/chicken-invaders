#pragma once
#include "State.h"
#include "Button.h"

class PreGameState :
	public State
{
public:
	PreGameState(StateData* stateData, std::string profileName);
	~PreGameState();
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
	std::string m_profileName;
};

