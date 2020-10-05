#pragma once
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Score
{
public:
	Score(sf::Font& font, float x, float y, unsigned charSize);
	~Score();
	void update();
	void draw(sf::RenderWindow& window);
	void addScore(int points);
	uint64_t getScore() const noexcept;
private:
	uint64_t m_score;
	std::string m_stringScore;
	sf::Font& m_font;
	sf::Text m_text; 
};

 

