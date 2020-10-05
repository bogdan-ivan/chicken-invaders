#pragma once
#include "Weapon.h"

class Weapon;

class EggGun
	: public Weapon
{
public:
	EggGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm);
	~EggGun();
	void shoot(uint16_t firePower, sf::Vector2f position, float playerHeight) override;
private:
};



