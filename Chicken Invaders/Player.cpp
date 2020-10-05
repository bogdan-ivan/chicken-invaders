#include "Player.h"
#include <iostream>

Player::Player(sf::Texture* texture, std::vector<Projectile>& projectiles, sf::Vector2u imageCount, float switchTime, float speed, sf::VideoMode& vm,
	std::string engineTexture, int lifes, uint16_t firePower, uint16_t overheat, uint16_t maxSpeed, uint16_t minSpeed, uint16_t rockets)
	:Entity(texture, imageCount, switchTime, speed), m_fireRate(0.25f), m_fireCooldown(0.0f), 
	 m_lifes(lifes), m_alive(true), m_invulnerable(false), m_meat(0), m_rockets(rockets), m_projectiles(projectiles),
	m_invulnerableDuration(3.f), m_invulnerableCounter(0.f), m_usedRocket(false), m_firePower(firePower),
	m_deathAnimation(TextureCache::getTexture("Explosion1"), sf::Vector2u(10, 11), 0.01f), m_overheat(0),
	m_maxFirePower(11), m_maxOverheat(overheat), m_maxSpeed(500), m_minSpeed(300), m_damage(1), m_vm(vm),
	m_engine(engineTexture, sf::Vector2u(8,4) , 0.05f, speed, vm)
{
	m_body.setSize(sf::Vector2f(Gui::p2pX(5, vm), Gui::p2pY(6, vm)));
	m_body.setOrigin(m_body.getSize().x / 2, m_body.getSize().y / 2);
	m_body.setPosition(Gui::p2pX(50, vm), Gui::p2pY(70, vm));
	m_body.setTexture(texture);
	m_playerHeight = m_body.getSize().y + 10;
	m_weapon = new PulseGun(m_projectiles, vm);
}

Player::~Player()
{
	if (m_weapon != nullptr)
		delete m_weapon;
}

void Player::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	sf::Vector2f engineMovement(0.0f, 0.0f);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= m_speed * deltaTime;
		engineMovement.x -= m_engine.getSpeed() * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += m_speed * deltaTime;
		engineMovement.x += m_engine.getSpeed() * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= m_speed * deltaTime;
		engineMovement.y -= m_engine.getSpeed() * deltaTime;
		//AudioCache::playSound("PlayerMovement");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += m_speed * deltaTime;
		engineMovement.y += m_engine.getSpeed() * deltaTime;
	}
	
	

	if (m_invulnerable)
	{
		m_invulnerableCounter += deltaTime;
		if (m_invulnerableCounter > m_invulnerableDuration)
		{
			m_invulnerableCounter = 0;
			m_invulnerable = false;
			m_alive = true;
			std::swap(m_animation, m_deathAnimation);
			m_body.setTexture(TextureCache::getTexture("Player"));
			m_row = 0;
		}
	}

	m_usedRocket = false;
	m_fireCooldown += deltaTime;

	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_overheat < m_maxOverheat && m_alive)
		shoot();
	if(m_overheat > 0)
		m_overheat -= deltaTime;

	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F) && m_rockets > 0 && m_alive)
		shootRocket();

	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O))
		increaseFireRate();
	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
		decreaseFireRate();
	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K))
		increaseSpeed();
	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::L))
		decreaseSpeed();
	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
		increaseFirePower();
	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
		decreaseFirePower();
	if (m_fireCooldown > m_fireRate && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::J))
		hit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
						{
							if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
							{
								sf::Vector2f projectileStart = m_body.getPosition();
								projectileStart.y -= m_playerHeight;
								m_projectiles.emplace_back(TextureCache::getTexture("badboys"), projectileStart, sf::Vector2u(1, 1), 1, 0,
									Projectile::ProjectileDirection::UP, 0, Gui::p2pX(51, m_vm), Gui::p2pY(51, m_vm));
							}
						}
					}
				}
			}
		}
	}
	
	
	if (m_meat >= 50)
	{
		addRocket();
		m_meat -= 50;
	}

	if (m_alive)
	{
		if (movement.x == 0.0f && movement.y == 0.0f)
		{
			m_row = 0;
		}
		else if (movement.x > 0.0f && movement.y == 0.0f)
		{
			m_row = 1;
		}
		else if (movement.x < 0.0f && movement.y == 0.0f)
		{
			m_row = 2;
		}
		else if (movement.y > 0.0f && movement.x == 0.0f)
		{
			m_row = 3;
		}
		else if (movement.y < 0.0f && movement.x == 0.0f)
		{
			m_row = 4;
		}
		else if (movement.x < 0.0f && movement.y < 0.0f)
		{
			m_row = 5;
		}
		else if (movement.x > 0.0f && movement.y < 0.0f)
		{
			m_row = 6;
		}
		else if (movement.x < 0.0f && movement.y > 0.0f)
		{
			m_row = 7;
		}
		else if (movement.x > 0.0f && movement.y > 0.0f)
		{
			m_row = 8;
		}
	}

	if (m_alive)
	{
		m_animation.update(m_row, deltaTime);
		m_engine.update(deltaTime);
	}
	else
		m_animation.update(deltaTime);

	m_body.setTextureRect(m_animation.m_uvRect);
	
	if (isPlayerInWindow(movement))
	{
		m_body.move(movement);
		m_engine.updateMovement(engineMovement, m_body.getPosition(), deltaTime);
	}
		

}

void Player::draw(sf::RenderWindow& window, sf::Shader* shader)
{
	m_vm.width = window.getSize().x;
	m_vm.height = window.getSize().y;
	if (shader)
	{
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", m_body.getOrigin());
		window.draw(m_body, shader);
		if(m_alive)
			m_engine.draw(window);
	}
	else
	{
		window.draw(m_body);
		if (m_alive)
			m_engine.draw(window);
	}
}

sf::Vector2f Player::getPosition() const noexcept
{
	return m_body.getPosition();
}

void Player::hit()
{
	//m_animation = m_deathAnimation;
	std::swap(m_animation, m_deathAnimation);
	m_body.setTexture(TextureCache::getTexture("Explosion1"));

	if (m_invulnerable)
		return;

	--m_lifes;
	decreaseFirePower();
	decreaseSpeed();
	decreaseFireRate();
	m_invulnerable = true;
	m_alive = false;
	m_row = 0;
}

int Player::getLifes() const noexcept
{
	return m_lifes;
}

int Player::getMeats() const noexcept
{
	return m_meat;
}

int Player::getRockets() const noexcept
{
	return m_rockets;
}

uint16_t Player::getFirepower() const noexcept
{
	return m_firePower;
}

uint16_t Player::getFireRate() const noexcept
{
	return m_fireRate;
}

uint16_t Player::getOverheat() const noexcept
{
	return m_overheat;
}

uint16_t Player::getMaxOverheat() const noexcept
{
	return m_maxOverheat;
}

std::vector<Projectile>& Player::getProjectiles()
{
	return m_projectiles;
}

sf::VideoMode& Player::getVm() noexcept
{
	return m_vm;
}

bool Player::getVulnerable() const noexcept
{
	return !m_invulnerable;
}

void Player::setVulnerable(bool vulnerability)
{
	m_invulnerable = !vulnerability;
}

bool Player::hasLifes() const noexcept
{
	return m_lifes > 0;
}

bool Player::usedRocket() const noexcept
{
	return m_usedRocket;
}

void Player::resetFireCooldown()
{
	m_fireCooldown = 0.0f;
}

void Player::addLife() noexcept
{
	++m_lifes;
}

void Player::addRocket() noexcept
{
	++m_rockets;
}

void Player::addMeat() noexcept
{
	++m_meat;
}

void Player::increaseFireRate() noexcept
{
	m_fireCooldown = 0;
	if(m_fireRate > 0.15f)
		m_fireRate -= 0.05f;
}

void Player::decreaseFireRate() noexcept
{
	m_fireCooldown = 0;
	if (m_fireRate < 0.50f)
		m_fireRate += 0.05f;
}

void Player::increaseSpeed() noexcept
{
	m_fireCooldown = 0;
	if (m_speed < m_maxSpeed)
		m_speed += 50;
}

void Player::decreaseSpeed() noexcept
{
	m_fireCooldown = 0;
	if (m_speed > m_minSpeed)
		m_speed -= 50;
}

void Player::increaseFirePower() noexcept
{
	m_fireCooldown = 0;
	if (m_firePower < m_maxFirePower)
		++m_firePower;
}

void Player::decreaseFirePower() noexcept
{
	m_fireCooldown = 0;
	if (m_firePower > 0)
		--m_firePower;
}

void Player::equipPulseGun()
{
	if (dynamic_cast<PulseGun*>(m_weapon))
		increaseFirePower();
	else
	{
		delete m_weapon;
		m_weapon = new PulseGun(m_projectiles, m_vm);
	}
}

void Player::equipNeutronGun()
{
	if (dynamic_cast<NeutronGun*>(m_weapon))
		increaseFirePower();
	else
	{
		delete m_weapon;
		m_weapon = new NeutronGun(m_projectiles, m_vm);
	}
}

void Player::equipPlasmaGun()
{
	if (dynamic_cast<PlasmaGun*>(m_weapon))
		increaseFirePower();
	else
	{
		delete m_weapon;
		m_weapon = new PlasmaGun(m_projectiles, m_vm);
	}
}

void Player::equipUtensilGun()
{
	if (dynamic_cast<UtensilGun*>(m_weapon))
		increaseFirePower();
	else
	{
		delete m_weapon;
		m_weapon = new UtensilGun(m_projectiles, m_vm);
	}
}

void Player::equipLaserGun()
{
	if (dynamic_cast<UtensilGun*>(m_weapon))
		increaseFirePower();
	else
	{
		delete m_weapon;
		m_weapon = new UtensilGun(m_projectiles, m_vm);
	}
}

void Player::equipHyperGun()
{
	if (dynamic_cast<HyperGun*>(m_weapon))
		increaseFirePower();
	else
	{
		delete m_weapon;
		m_weapon = new HyperGun(m_projectiles, m_vm);
	}
}

bool Player::isPlayerInWindow(sf::Vector2f movement)
{
	if (m_body.getPosition().x + movement.x <= 0 || m_body.getPosition().y + movement.y <= 0 || 
		m_body.getPosition().x + movement.x >= m_vm.width || m_body.getPosition().y + movement.y >= m_vm.height)
		return false;
	return true;
}

bool Player::isAlive() const noexcept
{
	return m_alive;
}

void Player::shoot()
{
	m_overheat += 100;
	m_weapon->shoot(m_firePower, m_body.getPosition(), m_playerHeight);
	m_fireCooldown = 0;
}

void Player::shootRocket()
{
	Statistics::increaseRocketsUsed();
	AudioCache::playSound("Nuke");
	sf::Vector2f projectileStart = m_body.getPosition();
	projectileStart.y -= m_playerHeight;
	m_projectiles.emplace_back(TextureCache::getTexture("Projectile"), projectileStart, sf::Vector2u(2, 1), 1, 300,
		Projectile::ProjectileDirection::UP, 1, Gui::p2pX(5, m_vm), Gui::p2pY(5, m_vm));
	m_fireCooldown = 0;
	--m_rockets;
	m_usedRocket = true;
}
