#include "Entity.h"

enum class PowerUpType 
{
	KEY,
	FIRE_RATE,
	FIRE_POWER,
	MOVEMENT_SPEED,
	ROCKET,
	LIFE,
	PULSEGUN,
	NEUTRONGUN,
	PLASMAGUN,
	UTENSILGUN,
	LASERGUN,
	HYPERGUN,
	MEAT
};

class PowerUp : public Entity
{
public:
	PowerUp(sf::Texture* texture, sf::Vector2f projectileStart, sf::Vector2u imageCount, float switchTime, float speed, PowerUpType type);
	~PowerUp();

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window, sf::Shader* shader = nullptr) override;

	void setPosition(sf::Vector2f pos);
	sf::RectangleShape getBody() const noexcept;
	PowerUpType getType() const noexcept;
	bool getExpired() const noexcept;

	static constexpr float powerUpWidth = 30.0f;
	static constexpr float powerUpHeight = 30.0f;
private:
	PowerUpType m_type;
	sf::VideoMode m_vm;
	bool hitBottom;
private:
	void bounce();
	bool bounceDirection;
	uint8_t bouncingNumber;
	float m_timerCounter;
	float m_timerLimit;
	bool m_expired;
};

