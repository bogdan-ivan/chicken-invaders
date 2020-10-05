#pragma once
#include "Weapon.h"

class Weapon;

class PulseGun 
	: public Weapon
{
public:
	PulseGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm);
	~PulseGun();
	void shoot(uint16_t firePower, sf::Vector2f position, float playerHeight) override;
private:
};

