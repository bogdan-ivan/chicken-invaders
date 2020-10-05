#include "pch.h"
#include "CppUnitTest.h"
#include "../Chicken Invaders/Score.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChickenInvadersTest
{
	TEST_CLASS(ScoreTest)
	{
	public:

		TEST_METHOD(addScore)
		{
			sf::Font font;
			Score score(font, 0.1, 0.2, 4);

			score.addScore(100);
			Assert::IsTrue(score.getScore() == 100);

		}
	};
}
