#pragma once
#include "SFML/Graphics.hpp"
#include "Button.h"

class PauseMenu
{
public:
	PauseMenu(sf::VideoMode& vm, sf::Font& font);
	~PauseMenu();

	void update(const sf::Vector2f& mousePos);
	void draw(sf::RenderTarget& target);
	void addButton(const std::string key, const float y, const float width, const float height, const unsigned charSize,
		const std::string text);
	const bool isButtonPressed(const std::string key);

	std::map<std::string, Button*>& getButtons();
private:

private:
	sf::Font& m_font;
	sf::Text m_menuText;
	sf::RectangleShape m_background;
	sf::RectangleShape m_container;
	std::map<std::string, Button*> m_buttons;
};




