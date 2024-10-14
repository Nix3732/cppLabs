#pragma once
#include <SFML/Graphics.hpp>

namespace ez
{

	class Bullet
	{
		float b_x, b_y;
		float b_vx;
		sf::Texture texture_bullet;
		sf::Sprite sprite_bullet;

	public:
		Bullet() = default;

		Bullet(float x, float y, float vx, sf::Texture bullet);

		void Setup(float x, float y, float vx, sf::Texture bullet);

		sf::Sprite Get();

		void setVelocityX(float dv);
		float X();
		float Y();
		float B_vx();
		void B_vx(float vx);
		void Move(double dt);
	};
}