#include "PauseMenu.h"
#include "Gui.h"

PauseMenu::PauseMenu(sf::VideoMode& vm, sf::Font& font)
	:m_font(font)
{
	m_background.setSize(sf::Vector2f(vm.width, vm.height));
	m_background.setFillColor(sf::Color(20, 20, 20, 100));

	m_container.setSize(sf::Vector2f(vm.width / 4.f, vm.height));
	m_container.setFillColor(sf::Color(20, 20, 20, 200));
	m_container.setPosition(vm.width / 2.f - m_container.getSize().x / 2.f, 0.0f);

	m_menuText.setFont(m_font);
	m_menuText.setFillColor(sf::Color(255, 255, 255, 200));
	m_menuText.setCharacterSize(Gui::charSize(80, vm));
	m_menuText.setString("PAUSED");
	m_menuText.setPosition(m_container.getPosition().x +
		m_container.getSize().x / 2.0f -
		m_menuText.getGlobalBounds().width / 2.0f,
		m_container.getPosition().y + Gui::p2pY(4.f, vm));
}

PauseMenu::~PauseMenu()
{
	for (auto& b : m_buttons)
	{
		delete b.second;
	}
}

void PauseMenu::update(const sf::Vector2f& mousePos)
{
	for (auto& b : m_buttons)
	{
		b.second->update(mousePos);
	}
}

void PauseMenu::draw(sf::RenderTarget& target)
{
	target.draw(m_background);
	target.draw(m_container);

	for (auto& b : m_buttons)
	{
		b.second->draw(target);
	}

	target.draw(m_menuText);
}

void PauseMenu::addButton(const std::string key, const float y, const float width, const float height, const unsigned charSize, const std::string text)
{
	float x = m_container.getPosition().x + m_container.getSize().x / 2.f - width / 2.f;
	m_buttons[key] = new Button(x, y, width, height,
		&m_font, text, charSize,
		sf::Color(255, 255, 255, 150), sf::Color(255, 255, 255, 200), sf::Color(20, 20, 20, 50),
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200),
		sf::Color(255, 255, 255, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50)
	);
}

const bool PauseMenu::isButtonPressed(const std::string key)
{
	return m_buttons[key]->isPressed();
}

std::map<std::string, Button*>& PauseMenu::getButtons()
{
	return m_buttons;
}
