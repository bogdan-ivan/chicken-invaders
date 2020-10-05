#include "PlasmaGun.h"

PlasmaGun::PlasmaGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm)
	:Weapon(projectiles, vm)
{

}

PlasmaGun::~PlasmaGun()
{

}

void PlasmaGun::shoot(uint16_t firePower, sf::Vector2f position, float playerHeight)
{
	sf::Vector2f projectileStart = position;
	projectileStart.y -= playerHeight;
	AudioCache::playSound("Shoot");
	Statistics::increaseShotsFired(firePower);

	switch (firePower)
	{
	case 0:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 1:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 2:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 3:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 4:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 5:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 6:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::THREE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 7:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::THREE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::FOUR, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 8:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::THREE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::FOUR, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::EIGHT, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 9:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::THREE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::FOUR, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::EIGHT, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 10:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::THREE, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::FOUR, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::EIGHT, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	case 11:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::ONE, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::THREE, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::FOUR, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::EIGHT, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 0.3, 300,
			Projectile::ProjectileDirection::UP, 2, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
		break;
	}
	default:
		break;
	}

}


