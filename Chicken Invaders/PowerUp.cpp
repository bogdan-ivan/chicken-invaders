#include "PowerUp.h"

PowerUp::PowerUp(sf::Texture* texture, sf::Vector2f projectileStart, sf::Vector2u imageCount, float switchTime, float speed, PowerUpType type)
	:Entity(texture, imageCount, switchTime, speed), m_type(type), hitBottom(false), bounceDirection(false), bouncingNumber(4),
	m_timerCounter(0.f), m_timerLimit(10.f), m_expired(false)
{
	m_body.setSize(sf::Vector2f(powerUpWidth, powerUpHeight));
	m_body.setOrigin(powerUpWidth / 2, powerUpHeight / 2);
	m_body.setPosition(projectileStart);
	m_body.setTexture(texture);
}

PowerUp::~PowerUp()
{

}

void PowerUp::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	
	movement.y += m_speed * deltaTime;
	
	m_animation.update(m_row, deltaTime);
	m_body.setTextureRect(m_animation.m_uvRect);
	if(m_type != PowerUpType::MEAT ||  m_vm.height == 0)
		m_body.move(movement);
	else if(m_body.getPosition().y < m_vm.height-50 && !hitBottom)
	{
		m_body.move(movement);
	}
	else
	{
		hitBottom = true;
		bounce();
	}

	m_timerCounter += deltaTime;
	if (m_timerCounter > m_timerLimit)
	{
		m_timerCounter = 0;
		m_expired = true;
	}
}

void PowerUp::draw(sf::RenderWindow& window, sf::Shader* shader)
{
	m_vm.width = window.getSize().x;
	m_vm.height = window.getSize().y;
	window.draw(m_body, shader);
}

void PowerUp::setPosition(sf::Vector2f pos)
{
	m_body.setPosition(pos);
}

sf::RectangleShape PowerUp::getBody() const noexcept
{
	return m_body;
}

PowerUpType PowerUp::getType() const noexcept
{
	return m_type;
}

bool PowerUp::getExpired() const noexcept
{
	return m_expired;
}

void PowerUp::bounce()
{
	if (bouncingNumber != 0)
	{
		if (!bounceDirection)
		{
			if (m_body.getPosition().y > m_vm.height - 125 - 10 * bouncingNumber)
			{
				m_body.move(-0.5f, -1.5f);
				return;
			}
			else
			{
				bounceDirection = true;
			}
		}
		else
		{
			if (m_body.getPosition().y < m_vm.height - 50 - 10  *bouncingNumber)
			{
				m_body.move(-0.5f, 1.5f);
				return;
			}
			else
			{
				bounceDirection = false;
				bouncingNumber--;
			}
		}
	}
}
