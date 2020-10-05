#include "SmartMove.h"
#include <iostream>

SmartMove::SmartMove(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, std::vector<Enemy>& enemies,
	sf::RenderWindow* window)
	:Entity(texture, imageCount, switchTime, speed), m_enemies(enemies), m_window(window), m_x(0), m_y(0), m_hint(0)
{
	m_body.setSize(sf::Vector2f(hintWidth, hintHeight));
	m_body.setOrigin(hintWidth / 2, hintHeight / 2);
	m_body.setPosition(100, m_window->getSize().y - hintHeight);
	m_body.setTexture(texture);
	clearTiles();
}

SmartMove::~SmartMove()
{

}

void SmartMove::update(float deltaTime)
{
	m_x = m_window->getSize().x;
	m_y = m_window->getSize().y;
	updateTiles();
	findOptimalPosition();

	sf::Vector2f movement(0.0f, 0.0f);
	if(m_body.getPosition().x < m_hint)
		movement.x += m_speed * deltaTime;
	else
		movement.x -= m_speed * deltaTime;

	m_animation.update(deltaTime);
	m_body.setTextureRect(m_animation.m_uvRect);
	m_body.move(movement);
}

void SmartMove::draw(sf::RenderWindow& window, sf::Shader* shader)
{
	window.draw(m_body, shader);
}

void SmartMove::printTiles() noexcept
{
	for (int i = 100; i <= m_x; i += 100)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = 100; i <= m_x; i += 100)
	{
		std::cout << m_tiles[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "I am intelligent, go to: " << m_hint + 50 << std::endl;
}

void SmartMove::clearTiles()
{
	for (int i = 100; i <= m_x; i += 100)
	{
		m_tiles[i] = 0;
	}
}

void SmartMove::updateTiles()
{
	clearTiles();
	for (auto& enemy : m_enemies)
	{
		for (int i = 100; i <= m_x; i += 100)
		{
			if (enemy.getPosition().x < i && enemy.getPosition().x > i - 100)
				++m_tiles[i];
		}
	}
}

void SmartMove::findOptimalPosition()
{
	int localTile = 0;
	int localMax = 0;
	for (auto& pos : m_tiles)
	{
		if (pos.second > localMax)
		{
			localMax = pos.second;
			localTile = pos.first;
		}
	}
	m_hint = localTile;
}
