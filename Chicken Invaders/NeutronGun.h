#pragma once
#include "Weapon.h"

class Weapon;

class NeutronGun
	: public Weapon
{
public:
	NeutronGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm);
	~NeutronGun();
	void shoot(uint16_t firePower, sf::Vector2f position, float playerHeight) override;
private:
};

