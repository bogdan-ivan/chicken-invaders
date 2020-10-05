#include "Entity.h"

Entity::Entity(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
	:m_animation(texture, imageCount, switchTime), m_row(0), m_speed(speed)
{

}

Entity::~Entity()
{

}

sf::RectangleShape Entity::getBody() const noexcept
{
	return m_body;
}

float Entity::getSpeed() const noexcept
{
	return m_speed;
}

void Entity::setAnimation(Animation animation)
{
	m_animation = animation;
}
