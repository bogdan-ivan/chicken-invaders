#pragma once
#include <vector>
#include <string>
#include "Wave.h"
#include "TextureCache.h"
#include "GameDifficulty.h"

float constexpr defaultEnemySize = 60.0f;

class Level
{
	std::vector<Enemy> m_allEnemies;
	uint16_t m_numberOfWaves;
	uint16_t m_currentWave;
	std::vector<Wave> m_wavesLogic;
	std::vector<Projectile>* m_projectiles;
	std::vector<PowerUp>* m_powerUps;
	bool m_levelComplete;
	std::vector<Enemy>& m_enemies;
	GameDifficulty* m_difficulty;
public:
	Level(uint16_t numberOfWaves, std::vector<Enemy>& enemies, std::vector<Projectile>* projectiles, std::vector<PowerUp>* powerUps,
		GameDifficulty* difficulty, sf::VideoMode& vm);
	uint16_t getNumberOfWaves() const noexcept;
	uint16_t getCurrentWave() const noexcept;
	bool isWaveComplete() const noexcept;
	bool nextWave() noexcept;
	void addWave(Wave wave);
	void addBoss(Wave wave, char nr);
private:
	sf::VideoMode& m_vm;
	void generateEnemies(Wave wave);
	void rectangleSpawn(Wave wave);
	void diamondSpawn(Wave wave);
	void triangleSpawn(Wave wave);
	void xshapeSpawn(Wave wave);
	void randomSpawn(Wave wave);
};

