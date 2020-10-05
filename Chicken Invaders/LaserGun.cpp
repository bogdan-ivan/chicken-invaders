#include "LaserGun.h"

LaserGun::LaserGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm)
	:Weapon(projectiles, vm)
{

}

LaserGun::~LaserGun()
{

}

void LaserGun::shoot(uint16_t firePower, sf::Vector2f position, float playerHeight)
{
	float projectileX = position.x;
	float projectileY = position.y - playerHeight;
	Statistics::increaseShotsFired(firePower);
	AudioCache::playSound("Shoot");

	switch (firePower)
	{
	case 0:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunWeak"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 1:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 2:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunWeak"), sf::Vector2f(projectileX - Gui::p2pX(0.5, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunWeak"), sf::Vector2f(projectileX + Gui::p2pX(0.5, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 3:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunWeak"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunWeak"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 4:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunWeak"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 5:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 6:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 7:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		break;
	}
	case 8:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunWeak"), sf::Vector2f(projectileX - Gui::p2pX(1.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunWeak"), sf::Vector2f(projectileX + Gui::p2pX(1.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 2, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 9:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX - Gui::p2pX(1.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX + Gui::p2pX(1.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 10:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX - Gui::p2pX(1.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunMedium"), sf::Vector2f(projectileX + Gui::p2pX(1.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1.5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 11:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX - Gui::p2pX(1.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(1.f, m_vm)),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("NeutronGunStrong"), sf::Vector2f(projectileX + Gui::p2pX(1.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 300, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(2, m_vm), Gui::p2pY(7, m_vm));
		break;
	}
	default:
		break;
	}
}
