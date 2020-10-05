#include "PulseGun.h"


PulseGun::PulseGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm)
	:Weapon(projectiles, vm)
{
	
}

PulseGun::~PulseGun()
{

}

void PulseGun::shoot(uint16_t firePower, sf::Vector2f position, float playerHeight)
{
	
	float projectileX = position.x;
	float projectileY = position.y - playerHeight;
	Statistics::increaseShotsFired(firePower);
	AudioCache::playSound("Shoot");

	switch (firePower)
	{
	case 0:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 1:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.5, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.5, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 2:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 3:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 4:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 5:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 6:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 7:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 8:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX - Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX + Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 9:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TEN, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunSingle"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 1, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TWO, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 10:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TEN, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TWO, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 11:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(1.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::NINE, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TEN, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ELEVEN, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::ONE, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(0.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::TWO, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("PulseGunDouble"), sf::Vector2f(projectileX + Gui::p2pX(1.9, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 600, Projectile::ProjectileDirection::THREE, 2, Gui::p2pX(2, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	default:
		break;
	}
		

}
