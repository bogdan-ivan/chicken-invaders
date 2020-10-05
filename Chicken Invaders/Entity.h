#pragma once
#include "Animation.h"
#include "TextureCache.h"
#include "AudioCache.h"
#include "Gui.h"

class Entity
{
public:
	Entity(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	virtual ~Entity();
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window, sf::Shader* shader) = 0;
	sf::RectangleShape getBody() const noexcept;
	float getSpeed() const noexcept;
	void setAnimation(Animation animation);
protected:
	sf::RectangleShape m_body;
	Animation m_animation;
	uint16_t m_row;
	float m_speed;
};



