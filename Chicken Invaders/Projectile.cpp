#include "Projectile.h"

Projectile::Projectile(sf::Texture* texture, sf::Vector2f projectileStart, sf::Vector2u imageCount, float switchTime, float speed,
	ProjectileDirection direction, uint16_t damage, float width, float height, ProjectileOwner owner)
	:Entity(texture, imageCount, switchTime, speed), m_direction(direction), m_damage(damage), m_projectileWidth(width), m_projectileHeight(height),
	m_owner(owner)
{
	m_body.setSize(sf::Vector2f(m_projectileWidth, m_projectileHeight));
	m_body.setOrigin(m_projectileWidth / 2, m_projectileHeight / 2);
	m_body.setPosition(projectileStart);
	m_body.setTexture(texture);
}

Projectile::~Projectile()
{

}

void Projectile::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if(m_direction == ProjectileDirection::UP)
		movement.y -= m_speed * deltaTime;
	if (m_direction == ProjectileDirection::DOWN)
		movement.y += m_speed * deltaTime;
	if (m_direction == ProjectileDirection::LEFT)
		movement.x -= m_speed * deltaTime;
	if (m_direction == ProjectileDirection::RIGHT)
		movement.x += m_speed * deltaTime;

	if (m_direction == ProjectileDirection::SEVEN)
	{
		movement.y -= m_speed * deltaTime;
		movement.x -= m_speed * deltaTime;
	}
	if (m_direction == ProjectileDirection::EIGHT)
	{
		movement.y -= m_speed * deltaTime;
		movement.x -= m_speed / 1.5 * deltaTime;
	}
	if (m_direction == ProjectileDirection::NINE)
	{
		movement.y -= m_speed * deltaTime;
		movement.x -= m_speed / 2 * deltaTime;
	}
	if (m_direction == ProjectileDirection::TEN)
	{
		movement.y -= m_speed * deltaTime;
		movement.x -= m_speed / 4 * deltaTime;
	}
	if (m_direction == ProjectileDirection::ELEVEN)
	{
		movement.y -= m_speed * deltaTime;
		movement.x -= m_speed / 8 * deltaTime;
	}
	if (m_direction == ProjectileDirection::ONE)
	{
		movement.y -= m_speed * deltaTime;
		movement.x += m_speed / 8 * deltaTime;
	}
	if (m_direction == ProjectileDirection::TWO)
	{
		movement.y -= m_speed * deltaTime;
		movement.x += m_speed / 4 * deltaTime;
	}
	if (m_direction == ProjectileDirection::THREE)
	{
		movement.y -= m_speed * deltaTime;
		movement.x += m_speed / 2 * deltaTime;
	}
	if (m_direction == ProjectileDirection::FOUR)
	{
		movement.y -= m_speed * deltaTime;
		movement.x += m_speed / 1.5 * deltaTime;
	}
	if (m_direction == ProjectileDirection::FIVE)
	{
		movement.y -= m_speed * deltaTime;
		movement.x += m_speed * deltaTime;
	}

	if (m_direction == ProjectileDirection::DOWNFOUR)
	{
		movement.y += m_speed * deltaTime;
		movement.x += m_speed / 1.5 * deltaTime;
	}
	if (m_direction == ProjectileDirection::DOWNFIVE)
	{
		movement.y += m_speed * deltaTime;
		movement.x += m_speed * deltaTime;
	}
	if (m_direction == ProjectileDirection::DOWNSEVEN)
	{
		movement.y += m_speed * deltaTime;
		movement.x -= m_speed * deltaTime;
	}
	if (m_direction == ProjectileDirection::DOWNEIGHT)
	{
		movement.y += m_speed * deltaTime;
		movement.x -= m_speed / 1.5 * deltaTime;
	}

	m_animation.update(m_row, deltaTime);
	m_body.setTextureRect(m_animation.m_uvRect);
	m_body.move(movement);
}

void Projectile::draw(sf::RenderWindow& window, sf::Shader* shader)
{
	window.draw(m_body, shader);
}

sf::Vector2f Projectile::getPosition() const noexcept
{
	return m_body.getPosition();
}

void Projectile::setPosition(sf::Vector2f pos)
{
	m_body.setPosition(pos);
}

sf::RectangleShape Projectile::getBody() const noexcept
{
	return m_body;
}

Projectile::ProjectileOwner Projectile::getOwner() const noexcept
{
	return m_owner;
}
