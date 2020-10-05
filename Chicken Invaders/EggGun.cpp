#include "EggGun.h"

EggGun::EggGun(std::vector<Projectile>& projectiles, sf::VideoMode& vm)
	:Weapon(projectiles, vm)
{

}

EggGun::~EggGun()
{

}

void EggGun::shoot(uint16_t firePower, sf::Vector2f position, float playerHeight)
{
	sf::Vector2f projectileStart = position;
	//projectileStart.y += playerHeight;
	/*AudioCache::playSound("Shoot");
	Statistics::increaseShotsFired(firePower);*/

	switch (firePower)
	{
	case 0:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		break;
	}
	case 1:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNSEVEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		break;
	}
	case 2:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNSEVEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNFIVE, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		break;
	}
	case 3:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNSEVEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNFIVE, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		break;
	}
	case 4:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNSEVEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNFIVE, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		break;
	}
	case 5:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNSEVEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNFIVE, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		break;
	}
	case 6:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNSEVEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNFIVE, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Egg2"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::THREE, 1, Gui::p2pX(0.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		break;
	}
	case 7:
	{
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNSEVEN, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNFIVE, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNEIGHT, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::DOWNFOUR, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TEN, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::TWO, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::NINE, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::THREE, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::ELEVEN, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		m_projectiles.emplace_back(TextureCache::getTexture("Knife"), projectileStart, sf::Vector2u(1, 1), 0.3, 300,
			Projectile::ProjectileDirection::FOUR, 1, Gui::p2pX(1.5, m_vm), Gui::p2pY(2, m_vm), Projectile::ProjectileOwner::ENEMY);
		break;
	}
	default:
		break;
	}

}


