#include "Enemy.h"
#include <iostream>


Enemy::Enemy(sf::Texture* texture, std::vector<Projectile>* projectiles, std::vector<PowerUp>* powerUps, sf::Vector2u imageCount, 
	int16_t hp, float fireRate, float cooldown, float switchTime, float speed, float x, float y, float w, float h, Pattern pattern, sf::VideoMode& vm,
	int firePower, int shootChance)
	:Entity(texture, imageCount, switchTime, speed), m_hp(hp), m_alive(true),m_touchUpDownBounder(false),
	m_fireRate(fireRate), m_fireCooldown(cooldown), m_projectiles(projectiles), m_powerUps(powerUps),
	enemyWidth(w), enemyHeight(h), m_pattern(pattern), m_firePower(firePower), m_vm(vm), m_shootChance(shootChance)
{
	m_body.setSize(sf::Vector2f(enemyWidth, enemyHeight));
	m_body.setOrigin(enemyWidth / 2, enemyHeight / 2);
	m_body.setPosition(x, y);
	m_body.setTexture(texture);

	m_weapon = new EggGun(*m_projectiles, vm);
}

Enemy::~Enemy()
{
	/*if (m_weapon != nullptr)
		delete m_weapon;*/
}

void Enemy::update(float deltaTime)
{
	if (m_body.getPosition().y > m_vm.height)
		m_alive = false;
	m_fireCooldown += deltaTime;
	if (m_fireCooldown > m_fireRate && Animation::getRandomInt(0, m_shootChance) == 0 && m_pattern != Pattern::DIAGONAL)
		m_weapon->shoot(m_firePower, m_body.getPosition(), m_body.getSize().y);

	if (m_hp <= 0)
		m_alive = false;
	if (!m_alive)
		dropLoot();

	//m_animation.update(m_row, deltaTime);
	m_animation.update(deltaTime);
	m_body.setTextureRect(m_animation.m_uvRect);

	switch (m_pattern)
	{
	case Pattern::HORIZONTAL: horizontalMove();  break;
	case Pattern::ZIGZAG: zigZagMove(); break;
	case Pattern::CRAZY: crazyMove(); break;
	case Pattern::DIAGONAL: diagonalMove(); break;
	default: break;
	}
}

void Enemy::horizontalMove()
{
	sf::Vector2f enemyPos = m_body.getPosition();
	if (m_vm.width - 50 > enemyPos.x && !m_touchLeftRightBounder)
		m_body.move(2.0f * m_speed, 0.0f);
	else
		m_touchLeftRightBounder = true;

	if (enemyPos.x > 50 && m_touchLeftRightBounder)
		m_body.move(-2.0f * m_speed, 0.0f);
	else
		m_touchLeftRightBounder = false;
}

void Enemy::crazyMove()
{
	float movement = Animation::getRandomFloat(0.f, 100.f);
	if (0.f <= movement && movement <= 50.f)
		zigZagMove();
	else if (51.f <= movement && movement <= 100.f)
		horizontalMove();
};

void Enemy::zigZagMove()
{
	sf::Vector2f enemyPos = m_body.getPosition();
	if (m_vm.width - 50 > enemyPos.x && !m_touchLeftRightBounder)
	{
		if (enemyPos.y < 2 * m_vm.height / 3 && !m_touchUpDownBounder)
			m_body.move(1.0f * m_speed, 1.25f);
		else
			m_touchUpDownBounder = true;

		if (enemyPos.y > m_vm.height / 3 - 200 && m_touchUpDownBounder)
			m_body.move(1.0f * m_speed, -1.25f);
		else
			m_touchUpDownBounder = false;
	}
	else
		m_touchLeftRightBounder = true;

	if (enemyPos.x > 50 && m_touchLeftRightBounder)
	{
		if (enemyPos.y < 2 * m_vm.height / 3 && !m_touchUpDownBounder)
			m_body.move(-1.0f * m_speed, 1.25f);
		else
			m_touchUpDownBounder = true;

		if (enemyPos.y > m_vm.height / 3 && m_touchUpDownBounder)
			m_body.move(-1.0f * m_speed, -1.25f);
		else
			m_touchUpDownBounder = false;
	}
	else
		m_touchLeftRightBounder = false;
}

void Enemy::diagonalMove()
{
	m_body.move(5.0f * m_speed, 5.0f * m_speed);
}

void Enemy::draw(sf::RenderWindow& window, sf::Shader* shader)
{
	m_vm.width = window.getSize().x;
	m_vm.height = window.getSize().y;
	window.draw(m_body, shader);
}

void Enemy::setPosition(sf::Vector2f pos)
{
	m_body.setPosition(pos);
}

void Enemy::setFirePower(int firePower)
{
	m_firePower = firePower;
}

Pattern Enemy::getPattern() const noexcept
{
	return m_pattern;
}

bool Enemy::isBoss() const noexcept
{
	return m_body.getSize().x > 100;
}

void Enemy::shoot()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_projectiles->emplace_back(TextureCache::getTexture("Egg1"), projectileStart, sf::Vector2u(1, 1), 0.3, 200,
		Projectile::ProjectileDirection::DOWN, 1, Gui::p2pX(1, m_vm), Gui::p2pY(1, m_vm), Projectile::ProjectileOwner::ENEMY);
	m_fireCooldown = 0;
}

void Enemy::dropLoot()
{
	int roll = Animation::getRandomInt(0, 200);
	int type;
	if (roll < 10)
	{
		type = Animation::getRandomInt(0, 5);
		if (type == 1)
			dropFireRate();
		if (type == 2)
			dropFirePower();
		if (type == 3)
			dropMovementSpeed();
		if (type == 4)
			dropRocket();
		if (type == 5)
			dropLife();
	}
	else if (roll == 194)
		dropHyperGun();
	else if (roll == 195)
		dropPulseGun();
	else if (roll == 196)
		dropNeutronGun();
	else if (roll == 197)
		dropPlasmaGun();
	else if (roll == 198)
		dropUtensilGun();
	else if (roll == 199)
		dropLaserGun();
	else if (roll == 200)
		dropKey();
	else if(m_pattern != Pattern::DIAGONAL)
		dropMeat();
}

void Enemy::dropMeat()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("MeatIcon"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::MEAT);
}

void Enemy::dropLife()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("LifesIcon"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::LIFE);
}

void Enemy::dropRocket()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("RocketIcon"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::ROCKET);
}

void Enemy::dropKey()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("Key"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::KEY);
}

void Enemy::dropFirePower()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("FireIcon"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::FIRE_POWER);
}

void Enemy::dropFireRate()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("FireIcon"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::FIRE_RATE);
}

void Enemy::dropMovementSpeed()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("MovementIcon"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::MOVEMENT_SPEED);
}

void Enemy::dropPulseGun()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("GIFTPulseGun"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::PULSEGUN);
}

void Enemy::dropNeutronGun()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("GIFTNeutronGun"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::NEUTRONGUN);
}

void Enemy::dropPlasmaGun()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("GIFTPlasmaGun"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::PLASMAGUN);
}

void Enemy::dropUtensilGun()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("GIFTUtensilGun"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::UTENSILGUN);
}

void Enemy::dropLaserGun()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("GIFTLaserGun"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::LASERGUN);
}

void Enemy::dropHyperGun()
{
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y += enemyHeight;
	m_powerUps->emplace_back(TextureCache::getTexture("GIFTHyperGun"), projectileStart, sf::Vector2u(1, 1), 0.3, 200, PowerUpType::HYPERGUN);
}

bool Enemy::getAlive() const noexcept
{
	return m_alive;
}

void Enemy::setAlive(bool alive)
{
	m_alive = alive;
}

void Enemy::hit()
{
	m_hp -= 1;
}

void Enemy::setHp(uint16_t hp) noexcept
{
	m_hp = hp;
}

int16_t Enemy::getHp() const noexcept
{
	return m_hp;
}

void Enemy::setSpeed(float speed) noexcept
{
	m_speed = speed;
}

sf::Vector2f Enemy::getPosition() const noexcept
{
	return m_body.getPosition();
}

bool Enemy::m_touchLeftRightBounder = false;
