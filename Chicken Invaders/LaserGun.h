#pragma once
#include "Weapon.h"

class LaserGun;

class LaserGun
	: public Weapon
{
public:
	LaserGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm);
	~LaserGun();
	void shoot(uint16_t firePower, sf::Vector2f position, float playerHeight) override;
private:
};
