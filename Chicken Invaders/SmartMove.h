#pragma once
#include "Entity.h"
#include "Enemy.h"

class SmartMove :
	public Entity
{
public:
	SmartMove(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed , std::vector<Enemy>& enemies,
		sf::RenderWindow* window);
	~SmartMove();
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window, sf::Shader* shader = nullptr) override;
	void printTiles() noexcept;
	static constexpr float hintWidth = 50.0f;
	static constexpr float hintHeight = 50.0f;
private:
	void clearTiles();
	void updateTiles();
	void findOptimalPosition();
private:
	std::vector<Enemy>& m_enemies;
	sf::RenderWindow* m_window;
	std::map<int, int> m_tiles;
	int m_x;
	int m_y;
	int m_hint;
};

