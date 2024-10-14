#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <fstream>

#pragma comment(lib,"shell32")

namespace ez
{

	class Enemy
	{
	protected:
		float e_x, e_y;
		float e_vx;
		sf::Texture texture_enemy;
		sf::Sprite sprite_enemy;

	public:
		Enemy() = default;
		virtual ~Enemy() {}

		Enemy(float x, float y, float vx, sf::Texture texture, float scaleFactor);

		void Setup(float x, float y, float vx, sf::Texture texture, float scaleFactor);

		sf::Sprite Get();

		void Move(float dt)
		{
			sprite_enemy.setPosition(sprite_enemy.getPosition().x + e_vx * dt, sprite_enemy.getPosition().y);
		}

		virtual void SpecialAbility() = 0;
	};


	class Bird : public Enemy
	{
	public:
		Bird() = default;
		virtual ~Bird() {}

		void SpecialAbility() override
		{
			std::ofstream Bird("Letter.txt");
		}
	};

	class Spider : public Enemy
	{
	public:
		Spider() = default;
		virtual ~Spider() {}

		void SpecialAbility() override
		{
			ShellExecute(0, "open", "https://www.youtube.com/watch?v=dQw4w9WgXcQ&ab_channel=RickAstley", NULL, NULL, SW_SHOWDEFAULT);
		}
	};
}