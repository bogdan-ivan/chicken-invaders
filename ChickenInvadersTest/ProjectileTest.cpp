#include "pch.h"
#include "CppUnitTest.h"
#include "../Chicken Invaders/Projectile.h";



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChickenInvadersTest
{
	TEST_CLASS(ProjectileTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			sf::Texture* texture = new sf::Texture;
			sf::Vector2f projectileStart;
			sf::Vector2u imageCount;
			Projectile projectile(texture, projectileStart, imageCount, 0.4,
				200, Projectile::ProjectileDirection::UP, 1, 0.2, 0.3, Projectile::ProjectileOwner::PLAYER);

			Assert::IsTrue(projectile.getOwner() == Projectile::ProjectileOwner::PLAYER);
			Assert::IsTrue(projectile.getSpeed() == 200);
		}
	};
}