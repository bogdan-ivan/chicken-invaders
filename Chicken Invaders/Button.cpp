#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor,
	sf::Color outline_idle_color, sf::Color outline_hover_color, sf::Color outline_active_color,
	short unsigned id)
	:m_textIdleColor(text_idle_color), m_textHoverColor(text_hover_color), m_textActiveColor(text_active_color),
	m_font(font), m_idleColor(idleColor), m_hoverColor(hoverColor), m_activeColor(activeColor),
	m_outlineIdleColor(outline_idle_color), m_outlineHoverColor(outline_hover_color), m_outlineActiveColor(outline_active_color), m_id(id)
{
	m_buttonState = ButtonStates::ButtonIdle;

	m_shape.setPosition(sf::Vector2f(x, y));
	m_shape.setSize(sf::Vector2f(width, height));
	m_shape.setOutlineThickness(1.f);
	m_shape.setOutlineColor(m_outlineIdleColor);

	m_text.setFont(*m_font);
	m_text.setString(text);
	m_text.setFillColor(sf::Color::White);
	m_text.setCharacterSize(character_size);
	m_text.setPosition(
		m_shape.getPosition().x + (m_shape.getGlobalBounds().width / 2.f) - m_text.getGlobalBounds().width / 2.f,
		m_shape.getPosition().y + (m_shape.getGlobalBounds().height / 2.f) - m_text.getGlobalBounds().height / 2.f
	);

	m_shape.setFillColor(m_idleColor);
}

Button::~Button()
{

}

void Button::update(const sf::Vector2f& mousePos)
{
	m_buttonState = ButtonStates::ButtonIdle;

	if (m_shape.getGlobalBounds().contains(mousePos))
	{
		m_buttonState = ButtonStates::ButtonHover;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_buttonState = ButtonStates::ButtonActive;
		}
	}

	switch (m_buttonState)
	{
	case ButtonStates::ButtonIdle:
		m_shape.setFillColor(m_idleColor);
		m_text.setFillColor(m_textIdleColor);
		m_shape.setOutlineColor(m_outlineIdleColor);
		break;
	case ButtonStates::ButtonHover:
		m_shape.setFillColor(m_hoverColor);
		m_text.setFillColor(m_textHoverColor);
		m_shape.setOutlineColor(m_outlineHoverColor);
		break;
	case ButtonStates::ButtonActive:
		m_shape.setFillColor(m_activeColor);
		m_text.setFillColor(m_textActiveColor);
		m_shape.setOutlineColor(m_outlineActiveColor);
		break;
	default:
		m_shape.setFillColor(sf::Color::Red);
		m_text.setFillColor(sf::Color::Blue);
		m_shape.setOutlineColor(sf::Color::Green);
		break;
	}
}

void Button::draw(sf::RenderTarget& target)
{
	target.draw(m_shape);
	target.draw(m_text);
}

const bool Button::isPressed() const
{
	if (m_buttonState == ButtonStates::ButtonActive)
		return true;

	return false;
}

const std::string Button::getText() const
{
	return m_text.getString();
}

const short unsigned& Button::getId() const
{
	return m_id;
}

//Modifiers
void Button::setText(const std::string text)
{
	m_text.setString(text);
}

void Button::setId(const short unsigned id)
{
	m_id = id;
}