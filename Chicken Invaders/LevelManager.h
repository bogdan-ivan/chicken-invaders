#pragma once
#include "Level.h"

class LevelManager
{
public:
	LevelManager(uint16_t numberOfLevels, std::vector<Enemy>& enemies, std::vector<Projectile>* projectiles, std::vector<PowerUp>* powerUps,
		GameDifficulty* difficulty, sf::VideoMode& vm);
	void update();
	bool nextLevel();
	bool isGameComplete() const noexcept;
	bool isLevelComplete() const noexcept;
	uint16_t getNumberOfLevels() const noexcept;
public:
	uint16_t m_numberOfLevels;
	uint16_t m_currentLevel;
	std::vector<Level> m_levels;
private:
	void generateLevels(std::vector<Enemy>& enemies, std::vector<Projectile>* projectiles, std::vector<PowerUp>* powerUps, GameDifficulty* difficulty,
		sf::VideoMode& vm);
};

