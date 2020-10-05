#include "State.h"

State::State(StateData* stateData)
	:m_window(stateData->m_window), m_quit(false), m_paused(false), m_states(stateData->m_states),
	m_keytime(0.f), m_keytimeMax(10.f), m_stateData(stateData)
{
	
}

State::~State()
{

}

void State::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition();
	m_mousePosWindow = sf::Mouse::getPosition(*m_window);
	m_mousePosView = m_window->mapPixelToCoords(sf::Mouse::getPosition(*m_window));
}

void State::updateKeytime(const float& deltaTime)
{
	if (m_keytime < m_keytimeMax)
	{
		m_keytime += 50.f * deltaTime;
	}
}

void State::endState()
{
	m_quit = true;
}

void State::pauseState()
{
	m_paused = true;
}

void State::unpauseState()
{
	m_paused = false;
}

const bool& State::getQuit() const noexcept
{
	return m_quit;
}

const bool State::getKeytime()
{
	if (m_keytime >= m_keytimeMax)
	{
		m_keytime = 0.f;
		return true;
	}
	return false;
}

const unsigned State::charSize(const unsigned modifier) const noexcept
{
	return static_cast<unsigned>((m_stateData->m_gfxSettings->m_resolution.width +
		m_stateData->m_gfxSettings->m_resolution.height) / modifier);
}

const float State::p2pX(const float perc) const noexcept
{
	return std::floor(static_cast<float>(m_stateData->m_gfxSettings->m_resolution.width) * (perc / 100.f));
}

const float State::p2pY(const float perc) const noexcept
{
	return std::floor(static_cast<float>(m_stateData->m_gfxSettings->m_resolution.height) * (perc / 100.f));
}
