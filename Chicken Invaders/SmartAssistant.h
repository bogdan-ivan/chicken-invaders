#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "Weapon.h"

class SmartAssistant :
	public Entity
{
public:
	SmartAssistant(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, std::vector<Enemy>& enemies,
		std::vector<Projectile>& projectiles, sf::RenderWindow* window, sf::VideoMode& vm);
	~SmartAssistant();
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window, sf::Shader* shader = nullptr) override;
	void printTiles() noexcept;
	void hit();
private:
	void clearTiles();
	void updateTiles();
	void findOptimalPosition();
	int findSafePosition(int localTile);
private:
	std::vector<Enemy>& m_enemies;
	std::vector<Projectile>& m_projectiles;
	sf::RenderWindow* m_window;
	std::map<int, int> m_tilesEnemy;
	std::map<int, int> m_tilesProjectiles;
	int m_x;
	int m_y;
	int m_hint;
	std::unique_ptr<Weapon> m_weapon;
	sf::VideoMode& m_vm;
	int m_firePower;
	float m_fireRate;
	float m_fireCooldown;
	int m_accuracyEnemy;
	int m_accuracyProjectiles;
	bool m_alive;
	bool m_invulnerable;
	float m_invulnerableDuration;
	float m_invulnerableCounter;
	Animation m_deathAnimation;
	bool m_needToShoot;
};



