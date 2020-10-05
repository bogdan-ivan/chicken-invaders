#include "pch.h"
#include "CppUnitTest.h"
#include "../Chicken Invaders/Player.h";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChickenInvadersTest
{
	TEST_CLASS(PlayerTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);

			Assert::IsTrue(player.getSpeed() == 4.0);

		}

		TEST_METHOD(addLife)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);
			player.addLife(); // initial life = 3, and now would be 4

			Assert::IsTrue(player.getLifes() == 4);

		}

		TEST_METHOD(addRocket)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);
			player.addRocket(); // initial rockets = 1, and now would be 2

			Assert::IsTrue(player.getRockets() == 2);

		}

		TEST_METHOD(addMeat)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);
			player.addMeat(); // initial meats = 0, and now would be 1

			Assert::IsTrue(player.getMeats() == 1);

		}

		TEST_METHOD(Hit)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);
	
			player.hit(); // initial life = 3, and now would be 2

			Assert::IsTrue(player.getLifes() == 2);
			Assert::IsTrue(player.getVulnerable() == true);

		}

		TEST_METHOD(Speed)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);

			player.increaseSpeed(); // initial speed = 4.0, and now would be 54

			Assert::IsTrue(player.getSpeed() == 54);

			player.decreaseSpeed(); // -50
			Assert::IsTrue(player.getSpeed() == 4);

		}

		TEST_METHOD(firePower)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);

			player.increaseFirePower(); // initial firePower = 0, and now would be 1
			Assert::IsTrue(player.getFirepower() == 1);

			player.decreaseFirePower(); // -1
			Assert::IsTrue(player.getFirepower() == 0);

		}

		TEST_METHOD(shoot)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);

			player.shoot(); // initial overheat = 0, and now would be 100
			Assert::IsTrue(player.getOverheat() == 100);
			
		}

		TEST_METHOD(shootRocket)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);

			player.shootRocket(); // initial number of rockets  = 1, and now would be 0
			Assert::IsTrue(player.getRockets() == 2);

		}

		TEST_METHOD(fireRate)
		{
			sf::Texture* texture = new sf::Texture;
			std::vector<Projectile> projectiles;
			sf::Vector2u imageCount;
			sf::VideoMode vm;
			Player player(texture, projectiles, imageCount, 3.0, 4.0, vm, "JetEngine2", 3, 0, 1000, 500, 300, 1);

			player.increaseFireRate(); // initial fireRate  = 0.25f, and now would be 0.20f
			Assert::IsTrue(player.getFireRate() == 0.20f);

			player.decreaseFireRate();
			Assert::IsTrue(player.getFireRate() == 0.25f);
		}
	};
}
