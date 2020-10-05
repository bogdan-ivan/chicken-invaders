#pragma once
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>
#include <memory>
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Score.h"
#include "TextureCache.h"
#include "AudioCache.h"
#include "GraphicsSettings.h"

class State;

class StateData
{
public:
	StateData() {};
	sf::RenderWindow* m_window;
	GraphicsSettings* m_gfxSettings;
	//std::map<std::string, int>* m_supportedKeys;
	std::stack<State*>* m_states;
};

class State
{
public:
	StateData* m_stateData;
	std::stack<State*>* m_states;
	State(StateData* stateData);
	virtual ~State();

	virtual void updateInput(const float& deltaTime) = 0;
	virtual void update(const float& deltaTime) = 0;
	virtual void draw(sf::RenderTarget* target = nullptr) = 0;
	virtual void updateMousePositions();
	virtual void updateKeytime(const float& deltaTime);

	void endState();
	void pauseState();
	void unpauseState();

	const bool& getQuit() const noexcept;
	const bool getKeytime();

	const float p2pX(const float perc) const noexcept;
	const float p2pY(const float perc) const noexcept;
	const unsigned charSize(const unsigned modifier) const noexcept;
protected:
	sf::RenderWindow* m_window;
	bool m_quit;
	bool m_paused;
	sf::Vector2i m_mousePosScreen;
	sf::Vector2i m_mousePosWindow;
	sf::Vector2f m_mousePosView;
	float m_keytime;
	float m_keytimeMax;
};



