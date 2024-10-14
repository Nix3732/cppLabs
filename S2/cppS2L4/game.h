#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "shapes.h"
namespace ez
{
	class Game1
	{
		int c_wd;
		int c_hg;
		int c_n;
		std::string c_name;
		sf::RenderWindow c_window;
		ez::Circle *c_crcl;

	public:
		Game1(int wd, int hg, std::string name)
		{
			c_wd = wd;
			c_hg = hg;
			c_name = name;
		}

		void set(int n)
		{
			c_window.create(sf::VideoMode(c_wd, c_hg), c_name);
			c_window.setTitle(c_name);

			c_n = n;
			c_crcl = new ez::Circle[c_n];

			
			srand(time(0));
			for (int i = 0; i < c_n; i++)
			{
				int x = rand() % 841;
				int y = rand() % 321;
				int r = rand() % 191 + 10;
				int red = rand() % 256;
				int green = rand() % 256;
				int blue = rand() % 256;
				c_crcl[i].Setup(x, y, r, red, green, blue);
			}
		}

		void life()
		{
			while(c_window.isOpen())
			{
				sf::Event event;
				while(c_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						c_window.close();
					}
				}

				c_window.clear();
				for (int i = 0; i < c_n; i++)
				{
					c_window.draw(c_crcl[i].Get());
				}
				c_window.display();
			}
		}
	};


	class Game2
	{
		int t_wd;
		int t_hg;
		int t_n;
		std::string t_name;
		sf::RenderWindow t_window;
		ez::Triangel* t_trngl;

	public:
		Game2(int wd, int hg, std::string name)
		{
			t_wd = wd;
			t_hg = hg;
			t_name = name;
		}

		void set(int n)
		{
			t_window.create(sf::VideoMode(t_wd, t_hg), t_name);
			t_window.setTitle(t_name);

			t_n = n;
			t_trngl = new ez::Triangel[t_n];


			srand(time(0));
			for (int i = 0; i < t_n; i++)
			{
				int x = rand() % 841;
				int y = rand() % 321;
				int r = rand() % 191 + 10;
				int angel = rand() % 360;
				int red = rand() % 256;
				int green = rand() % 256;
				int blue = rand() % 256;
				t_trngl[i].Setup(x, y, r, angel, red, green, blue);
			}
		}

		void life()
		{
			while (t_window.isOpen())
			{
				sf::Event event;
				while (t_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						t_window.close();
					}
				}

				t_window.clear();
				for (int i = 0; i < t_n; i++)
				{
					t_window.draw(t_trngl[i].Get());
				}
				t_window.display();
			}
		}
	};


	class Game3
	{
		int r_wd;
		int r_hg;
		int r_n;
		std::string r_name;
		sf::RenderWindow r_window;
		ez::Rectangel* r_rect;

	public:
		Game3(int wd, int hg, std::string name)
		{
			r_wd = wd;
			r_hg = hg;
			r_name = name;
		}

		void set(int n)
		{
			r_window.create(sf::VideoMode(r_wd, r_hg), r_name);
			r_window.setTitle(r_name);

			r_n = n;
			r_rect = new ez::Rectangel[r_n];


			srand(time(0));
			for (int i = 0; i < r_n; i++)
			{
				int x = rand() % 1040;
				int y = rand() % 520;
				int angel = rand() % 191 + 10;
				int w = rand() % 700 + 20;
				int h = rand() % 700 + 20;
				int red = rand() % 256;
				int green = rand() % 256;
				int blue = rand() % 256;
				r_rect[i].Setup(x, y, angel, w, h, red, green, blue);
			}
		}

		void life()
		{
			while (r_window.isOpen())
			{
				sf::Event event;
				while (r_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						r_window.close();
					}
				}

				r_window.clear();
				for (int i = 0; i < r_n; i++)
				{
					r_window.draw(r_rect[i].Get());
				}
				r_window.display();
			}
		}
	};



	class Game4 
	{
		int l_wd;
		int l_hg;
		int l_n;
		std::string l_name;
		sf::RenderWindow l_window;
		ez::Line* l_line;

	public:
		Game4(int wd, int hg, std::string name)
		{
			l_wd = wd;
			l_hg = hg;
			l_name = name;
		}

		void set(int n)
		{
			l_window.create(sf::VideoMode(l_wd, l_hg), l_name);
			l_window.setTitle(l_name);

			l_n = n;
			l_line = new ez::Line[l_n];

			srand(time(0));

			for (int i = 0; i < l_n; i++)
			{
				int x = rand() % 1040;
				int y = rand() % 520;
				int angel = rand() % 360;
				int len = rand() % 1000 + 30;
				int red = rand() % 256;
				int green = rand() % 256;
				int blue = rand() % 256;
				l_line[i].Setup(x, y, angel, len, red, green, blue);
			}
		}
		
		void life()
		{
			while (l_window.isOpen())
			{
				sf::Event event;
				while (l_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						l_window.close();
					}
				}

				l_window.clear();
				for (int i = 0; i < l_n; i++)
				{
					l_window.draw(l_line[i].Get());
				}
				l_window.display();
			}
		}
	};
}