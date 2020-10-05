#include "DropDownList.h"

DropDownList::DropDownList(float x, float y, float width, float height,
	sf::Font& font, std::string list[],
	unsigned nrOfElements, unsigned default_index)
	: m_font(font), m_showList(false), m_keytimeMax(1.f), m_keytime(0.f)
{
	
	m_activeElement = new Button(
		x, y, width, height,
		&this->m_font, list[default_index], 14,
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);

	for (unsigned i = 0; i < nrOfElements; i++)
	{
		m_list.push_back(
			new Button(
				x, y + ((i + 1) * height), width, height,
				&this->m_font, list[i], 14,
				sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
				sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 200), sf::Color(20, 20, 20, 200),
				sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(20, 20, 20, 0),
				i
			)
		);
	}
}

DropDownList::~DropDownList()
{
	delete m_activeElement;
	for (size_t i = 0; i < this->m_list.size(); i++)
	{
		delete m_list[i];
	}
}

const bool DropDownList::getKeytime()
{
	if (m_keytime >= m_keytimeMax)
	{
		m_keytime = 0.f;
		return true;
	}

	return false;
}

const unsigned short& DropDownList::getActiveElementId() const
{
	return m_activeElement->getId();
}

void DropDownList::setActiveElementId(unsigned id)
{
	m_activeElement->setId(id);
	m_activeElement->setText(m_list[id]->getText());
}

void DropDownList::updateKeytime(const float& deltaTime)
{
	if (m_keytime < m_keytimeMax)
		m_keytime += 10.f * deltaTime;
}

void DropDownList::update(const sf::Vector2f& mousePosWindow, const float& deltaTime)
{
	updateKeytime(deltaTime);

	m_activeElement->update(mousePosWindow);

	if (m_activeElement->isPressed() && getKeytime())
	{
		if (m_showList)
			m_showList = false;
		else
			m_showList = true;
	}

	if (this->m_showList)
	{
		for (auto& i : m_list)
		{
			i->update(mousePosWindow);

			if (i->isPressed() && getKeytime())
			{
				m_showList = false;
				m_activeElement->setText(i->getText());
				m_activeElement->setId(i->getId());
			}
		}
	}
}

void DropDownList::draw(sf::RenderTarget& target)
{
	m_activeElement->draw(target);

	if (m_showList)
	{
		for (auto& i : m_list)
		{
			i->draw(target);
		}
	}
}