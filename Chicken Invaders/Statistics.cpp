#include "Statistics.h"
#include <fstream>
#include <iostream>

Statistics::Statistics()
{
	
}

Statistics::~Statistics()
{
	
}

void Statistics::saveToFile()
{
	std::string path("..//Profiles//" + m_profileName + ".ini");
	std::ofstream output(path);
	if (!output.good())
		//logger->log(LoggingLevel::ERROR, "Failed to open Window.ini");
		std::cerr << "Failed to open" + m_profileName + ".ini" << std::endl;
	else
	{
		output << m_shotsFired << std::endl;
		output << m_shotsHit << std::endl;
		output << getAccuracy() << std::endl;
		output << m_enemiesKilled << std::endl;
		output << m_deaths << std::endl;
		output << m_rocketsUsed << std::endl;
		output << m_powerUpsCollected << std::endl;
		output << m_keys << std::endl;
	}
	output.close();
}

void Statistics::loadFromFile()
{
	std::string path("..//Profiles//" + m_profileName + ".ini");
	std::ifstream input(path);
	if (!input.good())
		//logger->log(LoggingLevel::ERROR, "Failed to open Window.ini");
		std::cerr << "Failed to open" + m_profileName + ".ini" << std::endl;
	else
	{
		input >> m_shotsFired >> m_shotsHit;
		input >> m_accuracy >> m_enemiesKilled;
		input >> m_deaths >> m_rocketsUsed >> m_powerUpsCollected;
		input >> m_keys;
	}
	input.close();
}

void Statistics::increaseShotsFired(int shots)
{
	m_shotsFired += shots + 1;
}

void Statistics::increaseShotsHit()
{
	++m_shotsHit;
}

void Statistics::increaseEnemiesKilled()
{
	++m_enemiesKilled;
}

void Statistics::increaseDeaths()
{
	++m_deaths;
}

void Statistics::increaseRocketsUsed()
{
	++m_rocketsUsed;
}

void Statistics::increasePowerUpsCollected()
{
	++m_powerUpsCollected;
}

void Statistics::increaseKeys(int key)
{
	m_keys += key;
}

int Statistics::getShotsFired()
{
	return m_shotsFired;
}

int Statistics::getShotsHit()
{
	return m_shotsHit;
}

float Statistics::getAccuracy()
{
	if (m_shotsFired != 0)
		return (static_cast<float>(m_shotsHit) / static_cast<float>(m_shotsFired)) * 100;
	else
		return 0;
}

int Statistics::getEnemiesKilled()
{
	return m_enemiesKilled;
}

int Statistics::getDeaths()
{
	return m_deaths;
}

int Statistics::getRocketsUsed()
{
	return m_rocketsUsed;
}

int Statistics::getPowerUpsCollected()
{
	return m_powerUpsCollected;
}

int Statistics::getKeys()
{
	return m_keys;
}

int Statistics::getNumberOfPowersUps()
{
	return m_numberOfPowerUps;
}

void Statistics::setProfileName(const std::string& profileName)
{
	m_profileName = profileName;
}

void Statistics::decreaseKeys(int key)
{
	m_keys -= key;
}

int Statistics::m_numberOfPowerUps = 8;
int Statistics::m_shotsFired;
int Statistics::m_shotsHit;
float Statistics::m_accuracy;
int Statistics::m_enemiesKilled;
int Statistics::m_deaths;
int Statistics::m_rocketsUsed;
int Statistics::m_powerUpsCollected;
int Statistics::m_keys;
std::string Statistics::m_profileName;
