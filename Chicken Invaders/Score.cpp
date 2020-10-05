#include "Score.h"


Score::Score(sf::Font& font, float x, float y, unsigned charSize)
	:m_score(0), m_stringScore(""), m_font(font)
{
	m_text.setFont(font);
	m_text.setString(m_stringScore);
	m_text.setCharacterSize(charSize);
	m_text.setFillColor(sf::Color::Red);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	m_text.setPosition(sf::Vector2f(x, y));
}

Score::~Score()
{

}

void Score::update()
{
	++m_score;
	m_stringScore = std::to_string(m_score);
	m_text.setString(m_stringScore);
}

void Score::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
}

void Score::addScore(int points)
{
	m_score += points;
}

uint64_t Score::getScore() const noexcept
{
	return m_score;
}

