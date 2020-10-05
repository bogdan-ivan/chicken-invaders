#include "SmartAssistant.h"
#include <iostream>
#include "PulseGun.h"

SmartAssistant::SmartAssistant(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, std::vector<Enemy>& enemies,
	std::vector<Projectile>& projectiles, sf::RenderWindow* window, sf::VideoMode& vm)
	:Entity(texture, imageCount, switchTime, speed), m_enemies(enemies), m_projectiles(projectiles), m_window(window),
	m_x(0), m_y(0), m_hint(0), m_vm(vm), m_firePower(2), m_fireRate(0.95f), m_fireCooldown(0.0f), m_accuracyEnemy(80), m_accuracyProjectiles(80),
	m_deathAnimation(TextureCache::getTexture("Explosion1"), sf::Vector2u(10, 11), 0.01f),
	m_alive(true), m_invulnerable(false), m_invulnerableDuration(3.f), m_invulnerableCounter(0.f), m_needToShoot(false)
{
	m_body.setSize(sf::Vector2f(Gui::p2pX(5, vm), Gui::p2pY(6, vm)));
	m_body.setOrigin(m_body.getSize().x / 2, m_body.getSize().y / 2);
	m_body.setPosition(500, m_window->getSize().y - Gui::p2pY(6, vm));
	m_body.setTexture(texture);
	clearTiles();

	m_weapon = std::make_unique<PulseGun>(m_projectiles, vm);
}

SmartAssistant::~SmartAssistant()
{

}

void SmartAssistant::update(float deltaTime)
{
	m_x = m_window->getSize().x;
	m_y = m_window->getSize().y;
	updateTiles();
	findOptimalPosition();

	sf::Vector2f movement(0.0f, 0.0f);
	if (m_body.getPosition().x < m_hint)
		movement.x += m_speed * deltaTime;
	else
		movement.x -= m_speed * deltaTime;


	if (m_invulnerable)
	{
		m_invulnerableCounter += deltaTime;
		if (m_invulnerableCounter > m_invulnerableDuration)
		{
			m_invulnerableCounter = 0;
			m_invulnerable = false;
			m_alive = true;
			std::swap(m_animation, m_deathAnimation);
			m_body.setTexture(TextureCache::getTexture("PlayerYellow"));
			m_row = 0;
		}
	}


	if (movement.x == 0.0f && movement.y == 0.0f)
	{
		m_row = 0;
	}
	else if (movement.x > 0.0f && movement.y == 0.0f)
	{
		m_row = 1;
	}
	else if (movement.x < 0.0f && movement.y == 0.0f)
	{
		m_row = 2;
	}

	m_fireCooldown += deltaTime;
	if (m_fireCooldown > m_fireRate && m_needToShoot)
	{
		m_weapon->shoot(m_firePower, m_body.getPosition(), m_body.getSize().y);
		m_fireCooldown = 0.f;
	}

	m_animation.update(m_row, deltaTime);
	m_body.setTextureRect(m_animation.m_uvRect);
	m_body.move(movement);
}

void SmartAssistant::draw(sf::RenderWindow & window, sf::Shader * shader)
{
	window.draw(m_body, shader);
}

void SmartAssistant::printTiles() noexcept
{
	for (int i = m_accuracyEnemy; i <= m_x; i += m_accuracyEnemy)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = m_accuracyEnemy; i <= m_x; i += m_accuracyEnemy)
	{
		std::cout << m_tilesEnemy[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "I am intelligent, go to: " << m_hint + 50 << std::endl;
}

void SmartAssistant::hit()
{
	std::swap(m_animation, m_deathAnimation);
	m_body.setTexture(TextureCache::getTexture("Explosion1"));

	if (m_invulnerable)
		return;

	m_invulnerable = true;
	m_alive = false;
	m_row = 0;
}

void SmartAssistant::clearTiles()
{
	for (int i = m_accuracyEnemy; i <= m_x; i += m_accuracyEnemy)
	{
		m_tilesEnemy[i] = 0;
	}
	for (int i = m_accuracyProjectiles; i <= m_x; i += m_accuracyProjectiles)
	{
		m_tilesProjectiles[i] = 0;
	}
}

void SmartAssistant::updateTiles()
{
	clearTiles();
	for (auto& enemy : m_enemies)
	{
		for (int i = m_accuracyEnemy; i <= m_x; i += m_accuracyEnemy)
		{
			if (enemy.getPosition().x < i && enemy.getPosition().x > i - m_accuracyEnemy)
				++m_tilesEnemy[i];
		}
	}
	for (auto& projectile : m_projectiles)
	{
		for (int i = m_accuracyProjectiles; i <= m_x; i += m_accuracyProjectiles)
		{
			if (projectile.getPosition().x < i && projectile.getPosition().x > i - m_accuracyProjectiles && projectile.getOwner() == Projectile::ProjectileOwner::ENEMY)
				++m_tilesProjectiles[i];
		}
	}
}

void SmartAssistant::findOptimalPosition()
{
	int localTile = 0;
	int localMax = 0;
	for (auto& pos : m_tilesEnemy)
	{
		if (pos.second > localMax)
		{
			localMax = pos.second;
			localTile = pos.first;
		}
	}
	if (m_tilesProjectiles[localTile] == 0)
	{
		m_hint = localTile;
		m_needToShoot = true;
	}
	else
	{
		m_hint = findSafePosition(localTile);
		m_needToShoot = false;
	}
}

int SmartAssistant::findSafePosition(int localTile)
{
	int result = m_body.getPosition().x;
	int maxEggs = 100;
	auto position = m_body.getPosition();
	for (auto& pos : m_tilesProjectiles)
	{
		if (pos.second < maxEggs && std::abs(pos.first - localTile) < 300)
		{
			maxEggs = pos.second;
			result = pos.first;
		}
	}
	return result;
}

