#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <vector>


namespace ez
{
	class Game
	{
		int w_wd;
		int w_hg;
		std::string w_name;
		sf::RenderWindow w_window;
		ez::Player pl; 
		ez::Bullet bl;
		ez::Bird bird;
		ez::Spider spider;

		sf::Texture texture_background;
		sf::Sprite sprite_background;

		sf::Texture texture_player;

		sf::Texture texture_bullet;

		sf::Texture texture_bird;

		sf::Texture texture_spider;

		sf::Image icon;

		float CurrentFrame = 0;
		sf::Clock clock;

		std::vector<Enemy*> enemy;

	public:
		Game(int wd, int hg, std::string name);
		~Game()
		{
			for (int i = 0; i < enemy.size(); i++)
				delete enemy[i];
		}
		void set();

		//жизнь))
		void life();
		bool DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2);
	};
}