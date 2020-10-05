#pragma once
#include <string>

class Statistics
{
public:
	Statistics();
	~Statistics();
	static void saveToFile();
	static void loadFromFile();
	static void increaseShotsFired(int shots);
	static void increaseShotsHit();
	static void increaseEnemiesKilled();
	static void increaseDeaths();
	static void increaseRocketsUsed();
	static void increasePowerUpsCollected();
	static void increaseKeys(int key = 1);
	static int getShotsFired();
	static int getShotsHit();
	static float getAccuracy();
	static int getEnemiesKilled();
	static int getDeaths();
	static int getRocketsUsed();
	static int getPowerUpsCollected();
	static int getKeys();
	static int getNumberOfPowersUps();
	static void setProfileName(const std::string& profileName);
	static void decreaseKeys(int key = 1);
private:
	static int m_numberOfPowerUps;
	static int m_shotsFired;
	static int m_shotsHit;
	static float m_accuracy;
	static int m_enemiesKilled;
	static int m_deaths;
	static int m_rocketsUsed;
	static int m_powerUpsCollected;
	static int m_keys;
	static std::string m_profileName;
};

