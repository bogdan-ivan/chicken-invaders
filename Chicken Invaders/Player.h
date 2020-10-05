#pragma once
#include "Entity.h"
#include "Projectile.h"
#include <vector>
#include "Statistics.h"
#include "PulseGun.h"
#include "PlasmaGun.h"
#include "NeutronGun.h"
#include "UtensilGun.h"
#include "HyperGun.h"
#include "Engine.h"

class Player : public Entity
{
public:
	Player(sf::Texture* texture, std::vector<Projectile>& projectiles, sf::Vector2u imageCount, float switchTime, float speed, sf::VideoMode& vm,
		std::string engineTexture, int lifes, uint16_t firePower, uint16_t overheat, uint16_t maxSpeed, uint16_t minSpeed, uint16_t rockets);
	~Player();
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window, sf::Shader* shader = nullptr) override;
	sf::Vector2f getPosition() const noexcept;
	
	void hit();

	int getLifes() const noexcept;
	int getMeats() const noexcept;
	int getRockets() const noexcept;
	uint16_t getFirepower() const noexcept;
	uint16_t getFireRate() const noexcept;
	uint16_t getOverheat() const noexcept;
	uint16_t getMaxOverheat() const noexcept;
	std::vector<Projectile>& getProjectiles();
	sf::VideoMode& getVm() noexcept;
	bool getVulnerable() const noexcept;
	bool hasLifes() const noexcept;

	void setVulnerable(bool vulnerability);

	bool usedRocket() const noexcept;
	void resetFireCooldown();

	void addLife() noexcept;
	void addRocket() noexcept;
	void addMeat() noexcept;

	void increaseFireRate() noexcept;
	void decreaseFireRate() noexcept;
	void increaseSpeed() noexcept;
	void decreaseSpeed() noexcept;
	void increaseFirePower() noexcept;
	void decreaseFirePower() noexcept;

	void equipPulseGun();
	void equipNeutronGun();
	void equipPlasmaGun();
	void equipUtensilGun();
	void equipLaserGun();
	void equipHyperGun();

	bool isPlayerInWindow(sf::Vector2f movement);
	bool isAlive() const noexcept;
	void shoot();
	void shootRocket();
private:
	
	
private:
	Engine m_engine;
	sf::VideoMode& m_vm;
	std::vector<Projectile>& m_projectiles;
	uint16_t m_lifes;
	bool m_alive;
	bool m_invulnerable;
	bool m_usedRocket;
	uint16_t m_meat;
	uint16_t m_rockets;
	uint16_t m_firePower;
	float m_fireRate;
	float m_fireCooldown;
	float m_invulnerableDuration;
	float m_invulnerableCounter;
	float m_playerHeight;
	Animation m_deathAnimation;
	uint16_t m_overheat;
	uint16_t m_maxFirePower;
	uint16_t m_maxOverheat;
	uint16_t m_maxSpeed;
	uint16_t m_minSpeed;
	uint16_t m_damage;
	Weapon* m_weapon;
};

