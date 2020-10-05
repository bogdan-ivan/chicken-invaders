#include "IntroState.h"
#include "MainMenuState.h"
#include <iostream>

IntroState::IntroState(StateData* stateData, sf::Event& event)
	:State(stateData), m_timer(0.f), m_event(event), m_soundPlaying(false), m_soundPlaying2(false)
{
	initializeFonts();
	initializeGui();
	resetGui();
	//AudioCache::playMusic("BlindingLights");
}

IntroState::~IntroState()
{
	
}

void IntroState::updateInput(const float& deltaTime)
{

	
}

void IntroState::update(const float& deltaTime)
{
	updateKeytime(deltaTime);
	updateMousePositions();
	updateInput(deltaTime);
	updateGui(deltaTime);
}

void IntroState::updateGui(const float& deltaTime)
{
	m_timer += deltaTime;
	std::cout << m_timer << std::endl;
	
	if (m_timer > 6.f && m_timer < 8.f)
	{
		m_sparklesAnimation->update(deltaTime);
		m_sparkles.setTextureRect(m_sparklesAnimation->m_uvRect);
		if (m_soundPlaying == false)
		{
			AudioCache::playSound("Fireball");
			m_soundPlaying = true;
		}
	}
	if (m_timer > 8.f)
	{
		m_crowAnimation->update(deltaTime);
		m_crow.setTextureRect(m_crowAnimation->m_uvRect);
	}
	if (m_timer > 10.f && m_timer < 15.f)
	{
		m_crow.move(70*deltaTime, 0);
		if (m_soundPlaying2 == false)
		{
			AudioCache::playSound("Crow");
			m_soundPlaying2 = true;
		}
		m_titleText.setFillColor(sf::Color(50 + m_timer * 10, 0 , 0, 70 + m_timer * 10));
	}
	if (m_timer > 15.f && m_timer < 15.018f)
	{
		m_states->push(new MainMenuState(m_stateData, m_event));
	}
	if (m_timer > 15.f)
		endState();
	
}

void IntroState::draw(sf::RenderTarget* target)
{
	target->draw(m_background);
	drawGui(*target);
}

void IntroState::drawGui(sf::RenderTarget& target)
{
	if (m_timer > 6.f && m_timer < 8.f)
	{
		target.draw(m_sparkles);
	}
	if (m_timer > 8.f)
	{
		target.draw(m_crow);
	}
	if (m_timer > 10.f)
	{
		target.draw(m_titleText);
	}

}

void IntroState::initializeFonts()
{
	if (!m_font.loadFromFile("..\\Fonts\\batmfa__.ttf"))
	{
		std::cout << "ERROR" << std::endl;
	}
}

void IntroState::initializeGui()
{
	initializeBackground();
	initializeSparkles();
	initializeCrow();
	initializeText();
}

void IntroState::initializeBackground()
{
	m_background.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_background.setTexture(TextureCache::getTexture("MainMenu"));
}

void IntroState::initializeSparkles()
{
	m_sparkles.setSize(sf::Vector2f(m_window->getSize().x, m_window->getSize().y));
	m_sparkles.setTexture(TextureCache::getTexture("SparklingAnim"));
	m_sparklesAnimation = std::make_unique<Animation>(TextureCache::getTexture("SparklingAnim"), sf::Vector2u(8, 7), 0.05f);
}

void IntroState::initializeCrow()
{
	m_crow.setSize(sf::Vector2f(m_window->getSize().x / 1.5, m_window->getSize().y / 1.5));
	m_crow.setPosition(p2pX(10.f), p2pY(10.f));
	m_crow.setTexture(TextureCache::getTexture("CrowAnim"));
	m_crowAnimation = std::make_unique<Animation>(TextureCache::getTexture("CrowAnim"), sf::Vector2u(5, 5), 0.05f);
}

void IntroState::initializeText()
{
	m_titleText.setFont(m_font);
	m_titleText.setPosition(sf::Vector2f(p2pX(25.f), p2pY(60.f)));
	m_titleText.setCharacterSize(charSize(30));
	m_titleText.setFillColor(sf::Color(255, 255, 255, 100));
	m_titleText.setString("Ivoruz Games");
}

void IntroState::resetGui()
{
	initializeGui();
}
