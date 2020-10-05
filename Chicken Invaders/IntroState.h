#pragma once
#include "State.h"
#include "Animation.h"

class IntroState :
	public State
{
public:
	IntroState(StateData* stateData, sf::Event& event);
	~IntroState();
	void updateInput(const float& deltaTime);
	void update(const float& deltaTime) override;
	void updateGui(const float& deltaTime);
	void draw(sf::RenderTarget* target = nullptr) override;
	void drawGui(sf::RenderTarget& target);
private:
	void initializeFonts();
	void initializeGui();
	void initializeBackground();
	void initializeSparkles();
	void initializeCrow();
	void initializeText();
	void resetGui();
private:
	sf::Font m_font;
	sf::RectangleShape m_background;
	sf::RectangleShape m_sparkles;
	sf::RectangleShape m_crow;
	sf::Text m_titleText;
	sf::Event& m_event;
	float m_timer;
	bool m_soundPlaying;
	bool m_soundPlaying2;
	std::unique_ptr<Animation> m_sparklesAnimation;
	std::unique_ptr<Animation> m_crowAnimation;
};

