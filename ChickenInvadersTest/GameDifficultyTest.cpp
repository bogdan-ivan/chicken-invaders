#include "pch.h"
#include "CppUnitTest.h"
#include "../Chicken Invaders/GameDifficulty.h";



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChickenInvadersTest
{
	TEST_CLASS(GameDifficultyTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			GameDifficulty gameDifficulty( 3.0 , 4.0, 5.0, 10, 6.0, 15, 4 , 5 , 6 , 7, 9);
			Assert::IsTrue(gameDifficulty.getEnemySpeed() == 3.0);
			Assert::IsTrue(gameDifficulty.getEnemyFireRate() == 4.0);
			Assert::IsTrue(gameDifficulty.getEnemyFireCooldown() == 5.0);
			Assert::IsTrue(gameDifficulty.getHp() == 10);
			Assert::IsTrue(gameDifficulty.getPlayerSpeed() == 6.0);
			Assert::IsTrue(gameDifficulty.getRockets() == 15);
			Assert::IsTrue(gameDifficulty.getLifes() == 4);
			Assert::IsTrue(gameDifficulty.getMaxFirePower() == 5);
			Assert::IsTrue(gameDifficulty.getMaxOverheat() == 6);
			Assert::IsTrue(gameDifficulty.getMaxSpeed() == 7);
			Assert::IsTrue(gameDifficulty.getMinSpeed() == 9);
		

		}
	};
}