#pragma once

#include "SFML/Graphics.hpp"

class ProgressBar
{
public:
	ProgressBar(float x, float y, float width, float height, int max_value,
		sf::Color inner_color, unsigned characterSize,
		sf::VideoMode& vm, sf::Font* font = NULL);
	~ProgressBar();
	void update(const int current_value);
	void draw(sf::RenderTarget& target);
private:
	std::string m_barString;
	sf::Text m_text;
	float m_maxWidth;
	int m_maxValue;
	sf::RectangleShape m_back;
	sf::RectangleShape m_inner;
};
