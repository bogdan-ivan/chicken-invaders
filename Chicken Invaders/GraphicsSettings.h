#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class GraphicsSettings
{
public:
	GraphicsSettings();
	void saveToFile(const std::string path);
	void loadFromFile(const std::string path);
	void restoreDefaults();
	std::string m_title;
	sf::VideoMode m_resolution;
	bool m_fullscreen;
	bool m_vsync;
	uint16_t m_frameRateLimit;
	sf::ContextSettings m_contextSettings;
	std::vector<sf::VideoMode> m_videoModes;
};

