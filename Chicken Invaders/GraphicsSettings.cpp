#include "GraphicsSettings.h"

GraphicsSettings::GraphicsSettings()
	:m_fullscreen(false), m_vsync(false), m_frameRateLimit(120)
{
	m_title = "UNDEFINED";
	m_resolution = sf::VideoMode::getDesktopMode();
	m_contextSettings.antialiasingLevel = 0;
	m_videoModes = sf::VideoMode::getFullscreenModes();
}

void GraphicsSettings::saveToFile(const std::string path)
{
	std::ofstream output(path);
	if (!output.good())
		//logger->log(LoggingLevel::ERROR, "Failed to open Window.ini");
		std::cerr << "Failed to open Window.ini" << std::endl;
	else
	{
		output << m_title << std::endl;
		output << m_resolution.width << " " << m_resolution.height << std::endl;
		output << m_fullscreen << std::endl;
		output << m_frameRateLimit << "\n" <<  m_vsync << std::endl;
		output << m_contextSettings.antialiasingLevel;
	}
	output.close();
}

void GraphicsSettings::loadFromFile(const std::string path)
{
	std::ifstream input(path);
	if (!input.good())
		//logger->log(LoggingLevel::ERROR, "Failed to open Window.ini");
		std::cerr << "Failed to open Window.ini" << std::endl;
	else
	{
		std::getline(input, m_title);
		input >> m_resolution.width >> m_resolution.height;
		input >> m_fullscreen;
		input >> m_frameRateLimit >> m_vsync;
		input >> m_contextSettings.antialiasingLevel;
	}
	input.close();
}

void GraphicsSettings::restoreDefaults()
{
	m_resolution.width = 1200;
	m_resolution.height = 700;
	m_fullscreen = 0;
	m_frameRateLimit = 144;
	m_vsync = 0;
	m_contextSettings.antialiasingLevel = 0;
}
