#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Circels.hpp"
#include <thread>
#include <vector>


namespace ez
{
	class Game1
	{
		int w_wd;
		int w_hg;
		int w_n;
		std::string w_name;
		sf::RenderWindow w_window;
		ez::Circle *c_crcl;
		sf::Texture back;
		sf::Texture texture;
		sf::Sprite background;
		sf::Image icon;

	public:
		Game1(int wd, int hg, std::string name)
		{
			w_wd = wd;
			w_hg = hg;
			w_name = name;
		}

		void set(int n)
		{
			w_window.create(sf::VideoMode(w_wd, w_hg), w_name);
			w_window.setTitle(w_name);

			//иконка
			icon.loadFromFile("assets\\1.jpg");
			w_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


			//массив шаров
			w_n = n;
			c_crcl = new ez::Circle[w_n];
			
			//задний фон
			/*back.loadFromFile("assets\\back.jpg");
			background.setTexture(back);*/

			//картинка на шаре
			texture.loadFromFile("assets\\1.jpg");

			//задание круга
			srand(time(0));
			std::vector<int> all_x;
			std::vector<int> all_y;
			std::vector<int> all_r;

			int i = 0;
			while (i < w_n)
			{
				int r = rand() % 100 + 60;
				all_r.push_back(r);

				int x = rand() % (1600 - 2 * r) + r;
				all_x.push_back(x);

				int y = rand() % (900 - 2 * r) + r;
				all_y.push_back(y);

				if (i != 0)
				{
					for (int j = 0; j < i; j++)
					{
						float Dx = all_x[i] - all_x[j];
						float Dy = all_y[i] - all_y[j];
						float D = sqrt(Dx * Dx + Dy * Dy);
						if (D <= all_r[i] + all_r[j])
						{
							all_r.pop_back();
							all_x.pop_back();
							all_y.pop_back();
							i--;
							break;
						}
					}
				}
				i++;
			}

			for (int i = 0; i < w_n; i++)
			{
				int vx = rand() % 140 - 70;
				int vy = rand() % 140 - 70;
				float angel = rand() % 7;
				c_crcl[i].Setup(all_x[i], all_y[i], all_r[i], angel, vx, vy, texture);
			}
		}

		//столкновение с границами
		void border(Circle& c)
		{
			float x = c.X();
			float y = c.Y();
			float r = c.R();
			float ex = c.E_vx();
			float ey = c.E_vy();

			if ((x - r <= 0 ) || (x + r >= w_wd))
			{	
				c.E_vx(-ex);
			}

			if ((y - r <= 0) || (y + r >= w_hg))
			{
				c.E_vy(-ey);
			}
		}

		//столкновения между шарами
		void globalbounce(Circle& c1, Circle& c2)
		{
			float x1 = c1.X();
			float x2 = c2.X();
			float y1 = c1.Y();
			float y2 = c2.Y();
			float r1 = c1.R();
			float r2 = c2.R();
			float dx1 = c1.E_vx();
			float dy1 = c1.E_vy();
			float dx2 = c2.E_vx();
			float dy2 = c2.E_vy();
			float Dx = x1 - x2;
			float Dy = y1 - y2;
			float D = sqrt(Dx*Dx + Dy*Dy);
			float s = Dx / D;
			float c = Dy / D;
			if (D == 0)
			{
				D = 0.001;
			}
			if (D <= r1 + r2 - 0.01)
			{
				float Vn1 = dx2 * s + dy2 * c;
				float Vn2 = dx1 * s + dy1 * c;
				float Vt1 = -dx2 * c + dy2 * s;
				float Vt2 = -dx1 * c + dy1 * s;

				float tmp = Vn2;
				Vn2 = Vn1;
				Vn1 = tmp;

				dx1 = Vn2 * s - Vt2 * c;
				dy1 = Vn2 * c + Vt2 * s;
				dx2 = Vn1 * s - Vt1 * c;
				dy2 = Vn1 * c + Vt1 * s;

				c1.E_vx(dx1);
				c1.E_vy(dy1);
				c2.E_vx(dx2);
				c2.E_vy(dy2);
			}
		}

		//жизнь))
		void life()
		{
			sf::Clock clock;

			while(w_window.isOpen())
			{
				sf::Event event;
				while(w_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						w_window.close();
					}
				}

				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();


				for (int i = 0; i < w_n; i++)
				{	
					border(c_crcl[i]);
				}

				for (int i = 0; i < w_n; i++)
				{
					for (int j = i + 1; j < w_n; j++)
					{
						globalbounce(c_crcl[i], c_crcl[j]);
					}
				}
				
				for (int i = 0; i < w_n; i++)
				{
					c_crcl[i].Move(dt);
				}

				w_window.clear();
				
				w_window.draw(background);
				for (int i = 0; i < w_n; i++)
				{
					w_window.draw(c_crcl[i].Get());
				}
				w_window.display();
			}
		}
	};
}