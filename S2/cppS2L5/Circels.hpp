#pragma once
#include <SFML/Graphics.hpp>

namespace ez
{
	const float pi = acos(-1);

	class Circle
	{
		float e_r;
		float e_x, e_y;
		float e_angel;
		float e_vx, e_vy;
		sf::CircleShape c_shape;
		sf::Texture c_texture;


	public:
		Circle() = default;

		Circle(float x, float y, float r, float angel, float vx, float vy, sf::Texture texture)
		{
			Setup(x, y, r, angel, vx, vy, texture);
		}


		void Setup(float x, float y, float r, float angel, float vx, float vy, sf::Texture texture)
		{
			e_x = x;
			e_y = y;
			e_r = r;
			e_vx = vx;
			e_vy = vy;
			e_angel = angel;
			c_texture = texture;
			int e_red = rand() % 256;
			int e_green = rand() % 256;
			int e_blue = rand() % 256;
			c_shape.setOrigin(e_r, e_r);
			c_shape.setRadius(e_r);
			c_shape.setPosition(e_x, e_y);
			c_shape.setOutlineThickness(-10.f);
			c_shape.setOutlineColor(sf::Color::Color(e_red, e_green, e_blue));
			c_shape.setFillColor(sf::Color::Color(e_red, e_green, e_blue, 0)); //если картинка -1
			c_shape.setTexture(&c_texture);
			
		}

		sf::CircleShape Get()
		{
			return c_shape;
		}

		float X()
		{
			return e_x;
		}
		float Y()
		{
			return e_y;
		}
		float R()
		{
			return e_r;
		}
		float Angel()
		{
			return e_angel;
		}
		float E_vx()
		{
			return e_vx;
		}
		void R(float r)
		{
			e_r = r;
		}
		void E_vx(float vx)
		{
			e_vx = vx;
		}
		void E_vy(float vy)
		{
			e_vy = vy;
		}
		float E_vy()
		{
			return e_vy;
		}
		void Angel(float angel)
		{
			e_angel = angel;
		}

		void Move(float dt)
		{
			e_x += e_vx * dt;
			e_y += e_vy * dt;
			c_shape.setPosition(e_x, e_y);
		}
	};
}