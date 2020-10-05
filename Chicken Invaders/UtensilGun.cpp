#include "UtensilGun.h"

UtensilGun::UtensilGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm)
	:Weapon(projectiles, vm)
{

}

UtensilGun::~UtensilGun()
{

}

void UtensilGun::shoot(uint16_t firePower, sf::Vector2f position, float playerHeight)
{
	float projectileX = position.x;
	float projectileY = position.y - playerHeight;
	Statistics::increaseShotsFired(firePower);
	AudioCache::playSound("Shoot");

	switch (firePower)
	{
	case 0:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX, projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 1:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 2:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 3:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 4:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(1, m_vm), Gui::p2pY(6, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 5:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 6:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(1, m_vm), Gui::p2pY(6, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 7:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(6, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 8:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(1, m_vm), Gui::p2pY(6, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 9:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX - Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 3, Gui::p2pX(1, m_vm), Gui::p2pY(6, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX + Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 10:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX - Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(1, m_vm), Gui::p2pY(6, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX + Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 11:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX - Gui::p2pX(2.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX - Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX - Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ELEVEN, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX, projectileY - Gui::p2pY(0.8, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::UP, 5, Gui::p2pX(1, m_vm), Gui::p2pY(6, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX + Gui::p2pX(0.7, m_vm), projectileY),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunCarving"), sf::Vector2f(projectileX + Gui::p2pX(1.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 5, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("UtensilGunFork"), sf::Vector2f(projectileX + Gui::p2pX(2.5, m_vm), projectileY + Gui::p2pY(0.5, m_vm)),
			sf::Vector2u(1, 1), 0.3, 400, Projectile::ProjectileDirection::ONE, 3, Gui::p2pX(1, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	default:
		break;
	}
}
