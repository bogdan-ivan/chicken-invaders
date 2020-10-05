#pragma once
#include "Entity.h"

class Engine :
	public Entity
{
public:
	Engine(std::string texture, sf::Vector2u imageCount, float switchTime, float speed, sf::VideoMode& vm);
	~Engine();
	void update(float deltaTime);
	void draw(sf::RenderWindow& window, sf::Shader* shader = nullptr);
	void updateMovement(sf::Vector2f movement, sf::Vector2f playerPosition, float deltaTime);
private:
	sf::VideoMode& m_vm;
};

