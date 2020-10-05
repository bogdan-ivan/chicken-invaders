#pragma once
#include "State.h"
#include "Button.h"
#include "DropDownList.h"

class MainMenuState :
	public State
{
public:
	MainMenuState(StateData* stateData, sf::Event& event);
	~MainMenuState();
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
	void initializeProfiles();
	void resetGui();
	void saveToFile(const std::string path);
	void loadFromFile(const std::string path);
	void refreshProfiles();
	void deleteProfile();
private:
	sf::Font m_font;
	sf::RectangleShape m_background;
	Button* m_gameStateButton;
	std::map<std::string, Button*> m_buttons;
	std::map<std::string, DropDownList*> m_dropDownLists;
	sf::Text m_titleText;
	std::vector<std::string> m_profiles;
	bool m_addProfile;
	std::string m_playerInput;
	sf::Text m_playerText;
	sf::Event& m_event;
};

