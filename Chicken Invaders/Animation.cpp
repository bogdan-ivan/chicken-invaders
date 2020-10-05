#include "Animation.h"
#include <random>

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
	:m_imageCount(imageCount), m_switchTime(switchTime), m_totalTime(0.0f)
{
	m_currentImage.x = 0;
	m_currentImage.y = 0;
	m_uvRect.width = texture->getSize().x / static_cast<float>(imageCount.x);
	m_uvRect.height = texture->getSize().y / static_cast<float>(imageCount.y);
}

Animation::~Animation()
{
	
}

void Animation::update(int row, float deltaTime)
{
	m_currentImage.y = row;
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;
		if (m_currentImage.x >= m_imageCount.x)
		{
			m_currentImage.x = 0;
		}
	}
	m_uvRect.left = m_currentImage.x * m_uvRect.width;
	m_uvRect.top = m_currentImage.y * m_uvRect.height;
}

void Animation::update(float deltaTime)
{
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;
		if (m_currentImage.x >= m_imageCount.x)
		{
			m_currentImage.x = 0;
			if (m_currentImage.y < m_imageCount.y)
			{
				m_currentImage.y++;
			}
			if (m_currentImage.y >= m_imageCount.y)
				m_currentImage.y = 0;
		}
	}
	m_uvRect.left = m_currentImage.x * m_uvRect.width;
	m_uvRect.top = m_currentImage.y * m_uvRect.height;
}

float Animation::getRandomFloat(float min, float max)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<float> dist(min, max);
	return dist(eng);
}

int Animation::getRandomInt(int min, int max)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<int> dist(min, max);
	return dist(eng);
}
