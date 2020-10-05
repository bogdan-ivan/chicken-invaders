#include "GameDifficulty.h"

GameDifficulty::GameDifficulty()
{
}

GameDifficulty::GameDifficulty(float enemySpeed, float enemyFireRate, float enemyFireCooldown, int16_t enemyHp,
	float playerSpeed, uint16_t rockets, uint16_t lifes, uint16_t firePower, uint16_t maxOverheat,
	uint16_t maxSpeed, uint16_t minSpeed)
		: m_enemySpeed(enemySpeed), m_enemyFireRate(enemyFireRate), m_enemyFireCooldown(enemyFireCooldown),
	m_hp(enemyHp), m_playerSpeed(playerSpeed), m_rockets(rockets), m_lifes(lifes), m_maxFirePower(firePower),
	m_maxOverheat(maxOverheat),m_maxSpeed(maxSpeed),m_minSpeed(minSpeed)
{
}

float GameDifficulty::getEnemySpeed() const noexcept
{
	return m_enemySpeed;
}

float GameDifficulty::getEnemyFireRate() const noexcept
{
	return m_enemyFireRate;
}

float GameDifficulty::getEnemyFireCooldown() const noexcept
{
	return m_enemyFireCooldown;
}

int16_t GameDifficulty::getHp() const noexcept
{
	return m_hp;
}

float GameDifficulty::getPlayerSpeed() const noexcept
{
	return m_playerSpeed;
}

uint16_t GameDifficulty::getRockets() const noexcept
{
	return m_rockets;
}

uint16_t GameDifficulty::getLifes() const noexcept
{
	return m_lifes;
}

uint16_t GameDifficulty::getMaxFirePower() const noexcept
{
	return m_maxFirePower;
}

uint16_t GameDifficulty::getMaxOverheat() const noexcept
{
	return m_maxOverheat;
}

uint16_t GameDifficulty::getMaxSpeed() const noexcept
{
	return m_maxSpeed;
}

uint16_t GameDifficulty::getMinSpeed() const noexcept
{
	return m_minSpeed;
}

void GameDifficulty::increaseEnemyHp() noexcept
{
	m_hp++;
}
