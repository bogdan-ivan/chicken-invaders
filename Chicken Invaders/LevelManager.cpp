#include "LevelManager.h"

using EN = ENEMY_NUMBER;

LevelManager::LevelManager(uint16_t numberOfLevels, std::vector<Enemy>& enemies, std::vector<Projectile>* projectiles, std::vector<PowerUp>* powerUps,
	GameDifficulty* difficulty, sf::VideoMode& vm) :
	m_currentLevel(0), m_numberOfLevels(numberOfLevels)
{
	generateLevels(enemies, projectiles, powerUps, difficulty, vm);
}

uint16_t LevelManager::getNumberOfLevels() const noexcept
{
	return m_numberOfLevels;
}

void LevelManager::update()
{
	m_levels.at(m_currentLevel).nextWave();
}

bool LevelManager::nextLevel()
{
	if (isGameComplete())
		return false;
	m_currentLevel++;
	return true;
}

void LevelManager::generateLevels(std::vector<Enemy>& enemies, std::vector<Projectile>* projectiles, std::vector<PowerUp>* powerUps,
	GameDifficulty* difficulty, sf::VideoMode& vm)
{
	Wave wave1_1(EN::LARGE_XSHAPE_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::XSHAPE);
	Wave wave1_2(EN::MIN_METEORITES , Pattern::DIAGONAL, Shape::METEORITES);
	Wave wave1_3(EN::MED_RECTANGLE_ENEMY_NUMBER, Pattern::CRAZY, Shape::RECTANGLE);
	Level level1(3, enemies, projectiles, powerUps, difficulty, vm);
	level1.addWave(wave1_1);
	level1.addWave(wave1_2);
	level1.addWave(wave1_3);
	m_levels.emplace_back(level1);

	Wave wave2_1(EN::DIAMOND_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::DIAMOND);
	Wave wave2_2(EN::MED_RECTANGLE_ENEMY_NUMBER, Pattern::HORIZONTAL, Shape::RECTANGLE);
	Wave wave2_3(EN::MED_TRIANGLE_ENEMY_NUMBER, Pattern::CRAZY, Shape::TRIANGLE);
	Level level2(3, enemies, projectiles, powerUps, difficulty, vm);
	level2.addWave(wave2_1);
	level2.addWave(wave2_2);
	level2.addWave(wave2_3);
	m_levels.emplace_back(level2);

	Wave wave3_1(EN::SMALL_XSHAPE_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::XSHAPE);
	Wave wave3_2(EN::MED_RECTANGLE_ENEMY_NUMBER, Pattern::HORIZONTAL, Shape::RECTANGLE);
	Wave wave3_3(EN::MED_TRIANGLE_ENEMY_NUMBER, Pattern::HORIZONTAL, Shape::TRIANGLE);
	Wave wave3_BOSS(EN::MAX_RECTANGLE_ENEMY_NUMBER, Pattern::CRAZY, Shape::RECTANGLE);
	Level level3(4, enemies, projectiles, powerUps, difficulty, vm);
	level3.addWave(wave3_1);
	level3.addWave(wave3_2);
	level3.addWave(wave3_3);
	level3.addBoss(wave3_BOSS, '1');
	m_levels.emplace_back(level3);

	Wave wave4_1(EN::MED_METEORITES, Pattern::DIAGONAL, Shape::METEORITES);
	Wave wave4_2(EN::MED_TRIANGLE_ENEMY_NUMBER, Pattern::HORIZONTAL, Shape::TRIANGLE);
	Wave wave4_3(EN::MAX_TRIANGLE_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::TRIANGLE);
	Level level4(3, enemies, projectiles, powerUps, difficulty, vm);
	level4.addWave(wave4_1);
	level4.addWave(wave4_2);
	level4.addWave(wave4_3);
	m_levels.emplace_back(level4);

	Wave wave5_1(EN::MAX_TRIANGLE_ENEMY_NUMBER, Pattern::CRAZY, Shape::TRIANGLE);
	Wave wave5_2(EN::DIAMOND_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::DIAMOND);
	Wave wave5_3(EN::MED_METEORITES, Pattern::DIAGONAL, Shape::METEORITES);
	Level level5(3, enemies, projectiles, powerUps, difficulty, vm);
	level5.addWave(wave5_1);
	level5.addWave(wave5_2);
	level5.addWave(wave5_3);
	m_levels.emplace_back(level5);

	Wave wave6_1(EN::LARGE_XSHAPE_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::XSHAPE);
	Wave wave6_2(EN::MAX_RECTANGLE_ENEMY_NUMBER, Pattern::CRAZY, Shape::RECTANGLE);
	Wave wave6_3(EN::LARGE_XSHAPE_ENEMY_NUMBER, Pattern::CRAZY, Shape::XSHAPE);
	Wave wave6_BOSS(EN::MAX_RECTANGLE_ENEMY_NUMBER, Pattern::CRAZY, Shape::RECTANGLE);
	Level level6(4, enemies, projectiles, powerUps, difficulty, vm);
	level6.addWave(wave6_1);
	level6.addWave(wave6_2);
	level6.addWave(wave6_3);
	level6.addBoss(wave6_BOSS, '2');
	m_levels.emplace_back(level6);

	Wave wave7_1(EN::DIAMOND_ENEMY_NUMBER, Pattern::HORIZONTAL, Shape::DIAMOND);
	Wave wave7_2(EN::MAX_METEORITES, Pattern::DIAGONAL, Shape::METEORITES);
	Wave wave7_3(EN::MAX_RECTANGLE_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::RANDOM);
	Level level7(3, enemies, projectiles, powerUps, difficulty, vm);
	level7.addWave(wave7_1);
	level7.addWave(wave7_2);
	level7.addWave(wave7_3);
	m_levels.emplace_back(level7);

	Wave wave8_1(EN::MED_TRIANGLE_ENEMY_NUMBER, Pattern::HORIZONTAL, Shape::RANDOM);
	Wave wave8_2(EN::MAX_METEORITES, Pattern::DIAGONAL, Shape::METEORITES);
	Wave wave8_3(EN::MED_RECTANGLE_ENEMY_NUMBER, Pattern::CRAZY, Shape::RECTANGLE);
	Level level8(3, enemies, projectiles, powerUps, difficulty, vm);
	level8.addWave(wave8_1);
	level8.addWave(wave8_2);
	level8.addWave(wave8_3);
	m_levels.emplace_back(level8);

	Wave wave9_1(EN::MAX_TRIANGLE_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::TRIANGLE);
	Wave wave9_2(EN::MAX_METEORITES, Pattern::DIAGONAL, Shape::RECTANGLE);
	Wave wave9_3(EN::MED_TRIANGLE_ENEMY_NUMBER, Pattern::CRAZY, Shape::RANDOM);
	Level level9(3, enemies, projectiles, powerUps, difficulty, vm);
	level9.addWave(wave9_1);
	level9.addWave(wave9_2);
	level9.addWave(wave9_3);
	m_levels.emplace_back(level9);

	Wave wave10_1(EN::MAX_TRIANGLE_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::TRIANGLE);
	Wave wave10_2(EN::MAX_RECTANGLE_ENEMY_NUMBER, Pattern::ZIGZAG, Shape::RECTANGLE);
	Wave wave10_3(EN::MAX_METEORITES, Pattern::DIAGONAL, Shape::METEORITES);
	Wave wave10_BOSS(EN::MAX_METEORITES, Pattern::CRAZY, Shape::RANDOM);
	Level level10(4, enemies, projectiles, powerUps, difficulty, vm);
	level10.addWave(wave10_1);
	level10.addWave(wave10_2);
	level10.addWave(wave10_3);
	level10.addBoss(wave10_BOSS, '3');
	m_levels.emplace_back(level10);

}

bool LevelManager::isGameComplete() const noexcept
{
	return m_numberOfLevels - 1 == m_currentLevel;
}

bool LevelManager::isLevelComplete() const noexcept
{
	return m_levels.at(m_currentLevel).getCurrentWave() == (m_levels.at(m_currentLevel).getNumberOfWaves() - 1);
}
