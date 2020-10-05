#pragma once
#include "Weapon.h"

class Weapon;

class PlasmaGun
	: public Weapon
{
public:
	PlasmaGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm);
	~PlasmaGun();
	void shoot(uint16_t firePower, sf::Vector2f position, float playerHeight) override;
private:
};


