#pragma once
#include <cstdint>
#include <vector>
#include "SFML/Graphics/RenderWindow.hpp"
#include "Gui.h"
#include "Statistics.h"
#include "AudioCache.h"
#include "TextureCache.h"
#include "Projectile.h"

class Projectile;

class Weapon
{
public:
	Weapon(std::vector<Projectile>& projectiles, sf::VideoMode& vm);
	virtual ~Weapon();
	virtual void shoot(uint16_t firePower, sf::Vector2f position, float playerHeight) = 0;
protected:
	std::vector<Projectile>& m_projectiles;
	sf::VideoMode& m_vm;
};

