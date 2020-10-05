#pragma once
#include "State.h"
#include "Button.h"
#include "DropDownList.h"

class CustomizationState :
	public State
{
public:
	CustomizationState(StateData* stateData);
	~CustomizationState();
	void updateInput(const float& deltaTime);
	void update(const float& deltaTime) override;
	void updateGui(const float& deltaTime);
	void draw(sf::RenderTarget* target = nullptr) override;
	void drawGui(sf::RenderTarget& target);
	static std::string getPlayerColor();
	static std::string getEngineColor();
private:
	void initializeFonts();
	void initializeGui();
	void initializeBackground();
	void initializeText();
	void initializePreviews();
private:
	sf::Font m_font;
	sf::RectangleShape m_background;
	Button* m_gameStateButton;
	std::map<std::string, Button*> m_buttons;
	std::map<std::string, DropDownList*> m_dropDownLists;
	sf::Text m_titleText;
	sf::Text m_failText;
	sf::Text m_keyText;
	sf::Text m_optionsText;
	
	sf::RectangleShape m_previewPlayer;
	sf::RectangleShape m_previewEngine;
	sf::IntRect m_playerRect;
	sf::IntRect m_engineRect;
	static std::string m_playerColor;
	static std::string m_engineColor;

	std::vector<bool> m_unlocks{ false,false,false,false };
};

