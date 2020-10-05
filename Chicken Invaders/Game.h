#pragma once
#include "Logger.h"
#include "MainMenuState.h"
#include "IntroState.h"

class Game
{
public:
	Game();
	~Game();
	void start();
	void loop();
	void handleEvents();
	void update();
	void draw();
private:
	void initializeWindow();
	void initializeView();
	void initializeStates();
	void initializeGraphicsSettings();
	void initializeStateData();
	void resizeView(const sf::RenderWindow& window, sf::View& view);
	void updateDeltaTime();
	void endApplication();
private:
	std::stack<State*> m_states;
	float m_deltaTime;
	sf::Clock m_deltaTimeClock;
	sf::RenderWindow* m_window;
	GraphicsSettings m_gfxSettings;
	StateData m_stateData;
	sf::View* m_view;
	sf::Event m_event;
	std::shared_ptr<Logger> logger;

};

