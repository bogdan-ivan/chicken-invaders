#include "pch.h"
#include "CppUnitTest.h"
#include "../Chicken Invaders/Level.h";



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChickenInvadersTest
{
	TEST_CLASS(LevelTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			std::vector<Enemy> enemies;
			std::vector<Projectile>* projectiles = new std::vector<Projectile>;
			std::vector<PowerUp>* powerUps = new std::vector<PowerUp> ;
			GameDifficulty* difficulty= new GameDifficulty;
			sf::VideoMode vm;
			Level level(3, enemies , projectiles, powerUps, difficulty, vm);

			Assert::IsTrue(level.getNumberOfWaves() == 3);
			
		}
	};
}