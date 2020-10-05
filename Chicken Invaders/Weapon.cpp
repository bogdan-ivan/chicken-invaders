#include "Weapon.h"

Weapon::Weapon(std::vector<Projectile>& projectiles, sf::VideoMode& vm)
	:m_projectiles(projectiles), m_vm(vm)
{

}

Weapon::~Weapon()
{
	
}

