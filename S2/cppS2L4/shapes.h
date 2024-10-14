#pragma once
#include <SFML/Graphics.hpp>

namespace ez
{

	class Circle
	{
		float e_r;
		float e_x, e_y;
		int e_red, e_green, e_blue;
		sf::CircleShape c_shape;
	public:
		Circle() = default;

		Circle(float x, float y, float r, int red, int green, int blue)
		{
			Setup(x, y, r, red, green, blue);
		}

		void Setup(float x, float y, float r, int red, int green, int blue)
		{
			e_x = x;
			e_y = y;
			e_r = r;
			e_red = red;
			e_green = green;
			e_blue = blue;
			c_shape.setRadius(e_r);
			c_shape.setPosition(e_x, e_y);
			c_shape.setFillColor(sf::Color::Color(e_red, e_green, e_blue));
		}

		sf::CircleShape Get()
		{
			return c_shape;
		}
	};


	class Triangel
	{
		float t_r, t_angel;
		float t_x, t_y;
		int t_red, t_green, t_blue;
		sf::CircleShape t_shape;
	public:
		Triangel() = default;

		Triangel(float x, float y, float r, float angel, int red, int green, int blue)
		{
			Setup(x, y, r, angel, red, green, blue);
		}

		void Setup(float x, float y, float r, float angel, int red, int green, int blue)
		{
			t_x = x;
			t_y = y;
			t_r = r;
			t_angel = angel;
			t_red = red;
			t_green = green;
			t_blue = blue;
			t_shape.setRadius(t_r);
			t_shape.setPosition(t_x, t_y);
			t_shape.setRotation(t_angel);
			t_shape.setFillColor(sf::Color::Color(t_red, t_green, t_blue));
			t_shape.setPointCount(3);
		}

		sf::CircleShape Get()
		{
			return t_shape;
		}
	};


	class Rectangel
	{
		float r_x, r_y, r_angel, r_w, r_h;
		int r_red, r_green, r_blue;

		sf::RectangleShape r_shape;

	public:

		Rectangel() = default;

		Rectangel(float x, float y, float angel, float w, float h, int red, int green, int blue)
		{
			Setup(x, y, angel, w, h, red, green, blue);
		}

		void Setup(float x, float y, float angel, float w, float h, int red, int green, int blue)
		{
			r_x = x;
			r_y = y;
			r_angel = angel;
			r_w = w;
			r_h = h;
			r_red = red;
			r_green = green;
			r_blue = blue;
			r_shape.setPosition(r_x, r_y);
			r_shape.setRotation(r_angel);
			r_shape.setSize(sf::Vector2f(r_w, r_h));
			r_shape.setFillColor(sf::Color::Color(r_red, r_green, r_blue));
		}

		sf::RectangleShape Get()
		{
			return r_shape;
		}
	};


	class Line
	{
		float l_x, l_y, l_angel, l_len;
		int l_red, l_green, l_blue;

		sf::RectangleShape l_shape;

	public:

		Line() = default;

		Line(float x, float y, float angel, float len, int red, int green, int blue) 
		{
			Setup(x, y, angel, len, red, green, blue);
		}

		void Setup(float x, float y, float angel, float len, int red, int green, int blue)
		{
			l_x = x;
			l_y = y;
			l_angel = angel;
			l_len = len;
			l_red = red;
			l_green = green;
			l_blue = blue;
			l_shape.setPosition(l_x, l_y);
			l_shape.setRotation(l_angel);
			l_shape.setSize(sf::Vector2f(l_len, 10));
			l_shape.setFillColor(sf::Color::Color(l_red, l_green, l_blue));
		}

		sf::RectangleShape Get()
		{
			return l_shape;
		}
	};
}