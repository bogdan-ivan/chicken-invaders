#pragma once
#include "Entity.h"
#include "Projectile.h"
#include "PowerUp.h"
#include <vector>
#include "EggGun.h"

enum class Pattern
{
	HORIZONTAL,
	CRAZY,
	ZIGZAG,
	DIAGONAL
};

class Enemy : public Entity
{
public:
	Enemy(sf::Texture* texture, std::vector<Projectile>* projectiles, std::vector<PowerUp>* powerUps, sf::Vector2u imageCount, int16_t hp,
		float fireRate, float cooldown, float switchTime, float speed, float x, float y, float w, float h, Pattern pattern, sf::VideoMode& vm,
		int firePower = 0, int shootChance = 2000);
	~Enemy();
	Enemy(const Enemy& other) = default;
	Enemy& operator=(const Enemy& other) = default;
	Enemy(Enemy&& other) noexcept = default;
	Enemy& operator=(Enemy&& other) noexcept = default;
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window, sf::Shader* shader = nullptr) override;
	sf::Vector2f getPosition() const noexcept;
	bool getAlive() const noexcept;
	void setAlive(bool alive);
	void hit();
	void setHp(uint16_t hp) noexcept;
	int16_t getHp() const noexcept;
	void setSpeed(float speed) noexcept;
	void setPosition(sf::Vector2f pos);
	void setFirePower(int firePower);
	Pattern getPattern() const noexcept;
	bool isBoss() const noexcept;
private:
	void shoot();
	void dropLoot();
	void dropMeat();
	void dropLife();
	void dropRocket();
	void dropKey();
	void dropFirePower();
	void dropFireRate();
	void dropMovementSpeed();
	void dropPulseGun();
	void dropNeutronGun();
	void dropPlasmaGun();
	void dropUtensilGun();
	void dropLaserGun();
	void dropHyperGun();

	void horizontalMove();
	void crazyMove();
	void zigZagMove();
	void diagonalMove();
private:
	std::vector<Projectile>* m_projectiles;
	std::vector<PowerUp>* m_powerUps;
	int16_t m_hp;
	Pattern m_pattern;
	bool m_alive;
	float m_fireRate;
	float m_fireCooldown;
	sf::VideoMode m_vm;
	static bool m_touchLeftRightBounder;
	bool m_touchUpDownBounder;
	int m_firePower;
	EggGun* m_weapon;
	int m_shootChance;
public:
	float enemyWidth;
	float enemyHeight;
};

