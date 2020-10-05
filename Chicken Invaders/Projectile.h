#pragma once
#include "Entity.h"

class Projectile : public Entity
{
public:
	enum class ProjectileDirection
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		ELEVEN,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		DOWNFIVE,
		DOWNSEVEN,
		DOWNFOUR,
		DOWNEIGHT,
	};
	enum class ProjectileOwner
	{
		PLAYER,
		ENEMY
	};
public:
	Projectile(sf::Texture* texture, sf::Vector2f projectileStart, sf::Vector2u imageCount, float switchTime, float speed, ProjectileDirection direction,
		uint16_t damage, float width, float height , ProjectileOwner owner = ProjectileOwner::PLAYER);
	~Projectile();
	Projectile(const Projectile& other) = default;
	Projectile& operator=(const Projectile& other) = default;
	Projectile(Projectile&& other) noexcept = default;
	Projectile& operator=(Projectile&& other) noexcept = default;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window, sf::Shader* shader = nullptr) override;

	sf::Vector2f getPosition() const noexcept;
	void setPosition(sf::Vector2f pos);
	sf::RectangleShape getBody() const noexcept;
	ProjectileOwner getOwner() const noexcept;
private:
	uint16_t m_damage;
	float m_projectileWidth;
	float m_projectileHeight;
	ProjectileDirection m_direction;
	ProjectileOwner m_owner;
};

