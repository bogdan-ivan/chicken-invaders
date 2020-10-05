#pragma once
#include "Weapon.h"

class Weapon;

class UtensilGun
	: public Weapon
{
public:
	UtensilGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm);
	~UtensilGun();
	void shoot(uint16_t firePower, sf::Vector2f position, float playerHeight) override;
private:
};

