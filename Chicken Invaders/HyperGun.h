#pragma once
#include "Weapon.h"

class Weapon;

class HyperGun
	: public Weapon
{
public:
	HyperGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm);
	~HyperGun();
	void shoot(uint16_t firePower, sf::Vector2f position, float playerHeight) override;
private:
};

