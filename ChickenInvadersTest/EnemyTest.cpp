#include "pch.h"
#include "CppUnitTest.h"
#include "../Chicken Invaders/Enemy.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChickenInvadersTest
{
	TEST_CLASS(EnemyTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile>* projectiles = new std::vector<Projectile>;
			std::vector<PowerUp>* powerUps = new std::vector<PowerUp>;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Enemy enemy(texture, projectiles, powerUps, imageCount, 10, 0.1, 0.2, 0.3, 200.0, 
				0.5, 0.6, 0.7, 0.8, Pattern::CRAZY, vm, 0, 2000);

			Assert::IsTrue(enemy.getHp() == 10);
			Assert::IsTrue(enemy.getPattern() == Pattern::CRAZY);
			Assert::IsTrue(enemy.getSpeed() == 200);
		

		}

		TEST_METHOD(Hit)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile>* projectiles = new std::vector<Projectile>;
			std::vector<PowerUp>* powerUps = new std::vector<PowerUp>;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Enemy enemy(texture, projectiles, powerUps, imageCount, 10, 0.1, 0.2, 0.3, 200.0,
				0.5, 0.6, 0.7, 0.8, Pattern::CRAZY, vm, 0, 2000);

			enemy.hit(); //enemy hit was 10, and now would be 9
			Assert::IsTrue(enemy.getHp() == 9);

		}
	};
}
