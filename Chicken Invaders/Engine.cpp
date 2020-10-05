#include "Engine.h"

Engine::Engine(std::string texture, sf::Vector2u imageCount, float switchTime, float speed, sf::VideoMode& vm)
	:Entity(TextureCache::getTexture(texture), imageCount, switchTime, speed), m_vm(vm)
{
	m_body.setSize(sf::Vector2f(Gui::p2pX(12, vm), Gui::p2pY(12, vm)));
	m_body.setOrigin(sf::Vector2f(Gui::p2pX(12, vm) / 2, Gui::p2pY(12, vm) / 2));
	m_body.setPosition(Gui::p2pX(50, vm), Gui::p2pY(75, vm));
	m_body.setTexture(TextureCache::getTexture(texture));
}

Engine::~Engine()
{
}

void Engine::update(float deltaTime)
{
	m_animation.update(deltaTime);
	m_body.setTextureRect(m_animation.m_uvRect);
}

void Engine::draw(sf::RenderWindow& window, sf::Shader* shader)
{
	window.draw(m_body);
}

void Engine::updateMovement(sf::Vector2f movement, sf::Vector2f playerPosition, float deltaTime)
{
	m_body.move(movement);
	if (m_body.getPosition().x < playerPosition.x)
		m_body.move(sf::Vector2f(m_speed * deltaTime, 0.f));
	if (m_body.getPosition().x > playerPosition.x)
		m_body.move(sf::Vector2f(-(m_speed * deltaTime), 0.f));
	if (m_body.getPosition().y < playerPosition.y + Gui::p2pY(5, m_vm))
		m_body.move(sf::Vector2f(0.f, m_speed * deltaTime));
	if (m_body.getPosition().y > playerPosition.y + Gui::p2pY(5, m_vm))
		m_body.move(sf::Vector2f(0.f, -(m_speed * deltaTime)));
}
