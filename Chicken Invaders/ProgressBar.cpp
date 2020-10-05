#include "ProgressBar.h"
#include "Gui.h"

ProgressBar::ProgressBar(float _x, float _y, float _width, float _height, int max_value,
	sf::Color inner_color, unsigned character_size,
	sf::VideoMode& vm, sf::Font* font)
{
	float width = Gui::p2pX(_width, vm);
	float height = Gui::p2pY(_height, vm);
	float x = Gui::p2pX(_x, vm);
	float y = Gui::p2pY(_y, vm);

	m_maxWidth = width;
	m_maxValue = max_value;

	m_back.setSize(sf::Vector2f(width, height));
	m_back.setFillColor(sf::Color(50, 50, 50, 200));
	m_back.setPosition(x, y);

	m_inner.setSize(sf::Vector2f(width, height));
	m_inner.setFillColor(inner_color);
	m_inner.setPosition(m_back.getPosition());

	if (font)
	{
		m_text.setFont(*font);
		m_text.setCharacterSize(Gui::charSize(character_size, vm));
		m_text.setPosition(
			m_inner.getPosition().x + Gui::p2pX(0.53f, vm),
			m_inner.getPosition().y + Gui::p2pY(0.5f, vm)
		);
	}
}

ProgressBar::~ProgressBar()
{

}

void ProgressBar::update(const int current_value)
{
	float percent = static_cast<float>(current_value) / static_cast<float>(m_maxValue);

	m_inner.setSize(
		sf::Vector2f(
			static_cast<float>(std::floor(m_maxWidth * percent)),
			m_inner.getSize().y
		)
	);

	m_barString = std::to_string(current_value) + " / " + std::to_string(m_maxValue);
	m_text.setString(m_barString);
}

void ProgressBar::draw(sf::RenderTarget& target)
{
	target.draw(m_back);
	target.draw(m_inner);
	target.draw(m_text);
}