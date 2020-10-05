#include "Game.h"
#include <iostream>
#include <fstream>
#include "TextureCache.h"
#include "AudioCache.h"

Game::Game()
{
	TextureCache::loadTextures("loadt.txt");
	AudioCache::loadSounds("loada.txt");
	initializeGraphicsSettings();
	initializeWindow();
	initializeStateData();
	initializeView();
	initializeStates();
	logger = Logger::getInstance();
	logger->startLogging("Logging.txt");
}

Game::~Game()
{
	logger->log(LoggingLevel::INFO, "Game quit");
	logger->stopLogging();
	delete m_window;
	delete m_view;
	while (!m_states.empty())
	{
		delete m_states.top();
		m_states.pop();
	}
	TextureCache::clearCache();
	AudioCache::clearCache();
}

void Game::start()
{
	logger->log(LoggingLevel::INFO, "Game started");
}

void Game::loop()
{
	while (m_window->isOpen())
	{
		if (m_deltaTime > 0.08)
			logger->log(LoggingLevel::WARNING, "Game is running slow");

		updateDeltaTime();
		handleEvents();
		update();
		draw();
	}
}

void Game::handleEvents()
{
	while (m_window->pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)
			m_window->close();
		if (m_event.type == sf::Event::Resized)
			resizeView(*m_window, *m_view);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			m_window->close();
		

	}
}

void Game::update()
{
	resizeView(*m_window, *m_view);
	if (!m_states.empty())
	{
		m_states.top()->update(m_deltaTime);
		if (m_states.top()->getQuit())
		{
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_states.top()->endState();
				delete m_states.top();
				m_states.pop();
			}
		}
	}
	else
	{
		endApplication();
	}

}

void Game::draw()
{
	m_window->clear(sf::Color(246, 246, 246));
	m_window->setView(*m_view);


	if (!m_states.empty())
	{
		m_states.top()->draw(m_window);
	}

	m_window->display();
}

void Game::initializeWindow()
{
	if(m_gfxSettings.m_fullscreen)
		m_window = new sf::RenderWindow(
			m_gfxSettings.m_resolution,
			m_gfxSettings.m_title, 
			sf::Style::Fullscreen,
			m_gfxSettings.m_contextSettings);
	else
		m_window = new sf::RenderWindow(
			m_gfxSettings.m_resolution,
			m_gfxSettings.m_title,
			sf::Style::Titlebar | sf::Style::Close,
			m_gfxSettings.m_contextSettings);

	m_window->setFramerateLimit(m_gfxSettings.m_frameRateLimit);
	m_window->setVerticalSyncEnabled(m_gfxSettings.m_vsync);

}

void Game::initializeView()
{
	 m_view = new sf::View(sf::Vector2f(m_stateData.m_gfxSettings->m_resolution.width / 2, m_stateData.m_gfxSettings->m_resolution.height / 2),
		 sf::Vector2f(m_stateData.m_gfxSettings->m_resolution.width, m_stateData.m_gfxSettings->m_resolution.height));
	 //view.setCenter(player1.getPosition());
}

void Game::initializeStates()
{
	//m_states.push(new MainMenuState(&m_stateData, m_event));
	m_states.push(new IntroState(&m_stateData, m_event));
}

void Game::initializeGraphicsSettings()
{
	m_gfxSettings.loadFromFile("..//Config//Window.ini");
}

void Game::initializeStateData()
{
	m_stateData.m_window = m_window;
	m_stateData.m_gfxSettings = &this->m_gfxSettings;
	//m_stateData.m_supportedKeys = &this->supportedKeys;
	m_stateData.m_states = &this->m_states;
}

void Game::resizeView(const sf::RenderWindow& window, sf::View& view)
{
	/*float aspectRatio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
	view.setSize(m_stateData.m_gfxSettings->m_resolution.height * aspectRatio, m_stateData.m_gfxSettings->m_resolution.height);*/
	view.setSize(m_stateData.m_gfxSettings->m_resolution.width, m_stateData.m_gfxSettings->m_resolution.height);
	view.setCenter(m_stateData.m_gfxSettings->m_resolution.width / 2, m_stateData.m_gfxSettings->m_resolution.height / 2);
}

void Game::updateDeltaTime()
{
	m_deltaTime = m_deltaTimeClock.restart().asSeconds();
}

void Game::endApplication()
{
	m_window->close();
}




