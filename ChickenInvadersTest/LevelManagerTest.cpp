#include "pch.h"
#include "CppUnitTest.h"
#include "../Chicken Invaders/LevelManager.h";



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChickenInvadersTest
{
	TEST_CLASS(LevelManagerTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			std::vector<Enemy> enemies;
			std::vector<Projectile>* projectiles = new std::vector<Projectile>;
			std::vector<PowerUp>* powerUps = new std::vector<PowerUp>;
			GameDifficulty* difficulty = new GameDifficulty;
			sf::VideoMode vm;
			LevelManager levelManager (2, enemies, projectiles, powerUps, difficulty, vm);

			Assert::IsTrue(levelManager.getNumberOfLevels() == 2);
		}

		
	};
}