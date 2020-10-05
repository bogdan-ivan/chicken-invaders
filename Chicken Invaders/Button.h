#pragma once

#include "SFML/Graphics.hpp"

enum class ButtonStates
{
	ButtonIdle,
	ButtonHover,
	ButtonActive
};

class Button
{
public:
	Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned character_size,
		sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
		sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, 
		sf::Color outline_active_color = sf::Color::Transparent,
		short unsigned id = 0);
	~Button();

	void update(const sf::Vector2f& mousePos);
	void draw(sf::RenderTarget& target);

	const bool isPressed() const;
	const std::string getText() const;
	const short unsigned& getId() const;

	void setText(const std::string text);
	void setId(const short unsigned id);

private:
	ButtonStates m_buttonState;
	uint16_t m_id;

	sf::RectangleShape m_shape;
	sf::Font* m_font;
	sf::Text m_text;

	sf::Color m_textIdleColor;
	sf::Color m_textHoverColor;
	sf::Color m_textActiveColor;

	sf::Color m_idleColor;
	sf::Color m_hoverColor;
	sf::Color m_activeColor;

	sf::Color m_outlineIdleColor;
	sf::Color m_outlineHoverColor;
	sf::Color m_outlineActiveColor;
};




