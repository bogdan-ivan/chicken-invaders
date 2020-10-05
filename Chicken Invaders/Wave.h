#pragma once
#include "Enemy.h"
#include <list>

enum class Shape 
{
	RECTANGLE,
	DIAMOND,
	TRIANGLE,
	XSHAPE,
	RANDOM,
	METEORITES
};

enum ENEMY_NUMBER
{
	MIN_RECTANGLE_ENEMY_NUMBER = 20,
	MED_RECTANGLE_ENEMY_NUMBER = 30,
	MAX_RECTANGLE_ENEMY_NUMBER = 40,

	MIN_TRIANGLE_ENEMY_NUMBER = 21,
	MED_TRIANGLE_ENEMY_NUMBER = 28,
	MAX_TRIANGLE_ENEMY_NUMBER = 36,

	DIAMOND_ENEMY_NUMBER = 40,

	SMALL_XSHAPE_ENEMY_NUMBER = 20,
	LARGE_XSHAPE_ENEMY_NUMBER = 40,

	MIN_METEORITES = 50,
	MED_METEORITES = 75,
	MAX_METEORITES = 100
};

class Wave
{
	ENEMY_NUMBER m_enemyNumber;
	Shape m_spawnShape;
	Pattern m_movementPattern;
public:
	Wave(ENEMY_NUMBER enemyNumber, Pattern movementPattern, Shape spawnShape);
public:
	ENEMY_NUMBER getEnemyNumber() const noexcept;
	Shape getShape() const noexcept;
	Pattern getPattern() const noexcept;
}; 

