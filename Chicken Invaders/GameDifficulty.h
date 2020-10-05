#pragma once
#include <iostream>

class GameDifficulty
{
	float m_enemySpeed;
	float m_enemyFireRate;
	float m_enemyFireCooldown;
	int16_t m_hp;

	float m_playerSpeed;
	uint16_t m_rockets;
	uint16_t m_lifes;
	uint16_t m_maxFirePower;
	uint16_t m_maxOverheat;
	uint16_t m_maxSpeed;
	uint16_t m_minSpeed;
public:
	GameDifficulty();
	GameDifficulty(float enemySpeed, float enemyFireRate, float enemyFireCooldown, int16_t enemyHp,
		float playerSpeed, uint16_t rockets, uint16_t lifes, uint16_t firePower, uint16_t maxOverheat,
		uint16_t maxSpeed, uint16_t minSpeed);

	float getEnemySpeed() const noexcept;
	float getEnemyFireRate() const noexcept;
	float getEnemyFireCooldown() const noexcept;
	int16_t getHp() const noexcept;

	float getPlayerSpeed() const noexcept;
	uint16_t getRockets() const noexcept;
	uint16_t getLifes() const noexcept;
	uint16_t getMaxFirePower() const noexcept;
	uint16_t getMaxOverheat() const noexcept;
	uint16_t getMaxSpeed() const noexcept;
	uint16_t getMinSpeed() const noexcept;
	
	void increaseEnemyHp() noexcept;
};

