#pragma once
#include "Button.h"

class DropDownList
{
public:
	DropDownList(float x, float y, float width, float height,
		sf::Font& font, std::string list[],
		unsigned nrOfElements, unsigned default_index = 0);
	~DropDownList();

	const unsigned short& getActiveElementId() const;
	void setActiveElementId(unsigned id);

	const bool getKeytime();
	void updateKeytime(const float& deltaTime);
	void update(const sf::Vector2f& mousePosWindow, const float& deltaTime);
	void draw(sf::RenderTarget& target);

private:
	float m_keytime;
	float m_keytimeMax;

	sf::Font& m_font;
	Button* m_activeElement;
	std::vector<Button*> m_list;
	bool m_showList;
};