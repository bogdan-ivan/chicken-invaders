#include "Wave.h"

Wave::Wave(ENEMY_NUMBER enemiesNumber, Pattern movementPattern, Shape spawnShape):
	m_enemyNumber(enemiesNumber),m_spawnShape(spawnShape),m_movementPattern(movementPattern)
{
}


ENEMY_NUMBER Wave::getEnemyNumber() const noexcept
{
	return m_enemyNumber;
}

Shape Wave::getShape() const noexcept
{
	return m_spawnShape;
}

Pattern Wave::getPattern() const noexcept
{
	return m_movementPattern;
}
