#include "Game.h"
#include <iostream>
#include <vector>


namespace ez
{
	bool Game::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2)
	{
		if (rect1.left + rect1.width > rect2.left &&
			rect2.left + rect1.width > rect1.left &&
			rect2.top + rect2.height > rect1.top &&
			rect1.top + rect1.height > rect2.top)
			return true;

		return false;
	}
	ez::Game::Game(int wd, int hg, std::string name)
	{
		w_wd = wd;
		w_hg = hg;
		w_name = name;
	}

	void ez::Game::set()
	{
		w_window.create(sf::VideoMode(w_wd, w_hg), w_name);
		w_window.setTitle(w_name);

		//иконка
		icon.loadFromFile("assets\\icon.png");
		w_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

		//задний фон
		texture_background.loadFromFile("assets\\back.jpg");
		sprite_background.setTexture(texture_background);

		//картинка на игроке
		texture_player.loadFromFile("assets\\player.png");

		//картинка на пуле
		texture_bullet.loadFromFile("assets\\bullet.png");

		texture_bird.loadFromFile("assets\\bird.png");

		texture_spider.loadFromFile("assets\\spider.png");
		

		//задание игрока
		int x = 1700;
		int y = 765;
		int vx = 700;
		int vy = 50;
		bool OnGround = true;
		int jump_high = 50;
		pl.Setup(x, y, vx, vy, texture_player, OnGround, jump_high);


		enemy.push_back(new Bird);
		enemy[0]->Setup(100, 765, 500, texture_bird, 0.1f);

		enemy.push_back(new Spider);
		enemy[1]->Setup(-500, 850, 350, texture_spider, 0.2f);

	}

	//жизнь))

	void ez::Game::life()
	{
		std::vector<int> run_framex1;
		std::vector<int> run_framex2;
		std::vector<Bullet> bullets;
		run_framex1.push_back(323);
		run_framex2.push_back(289);
		run_framex1.push_back(635);
		run_framex2.push_back(193);
		run_framex1.push_back(875);
		run_framex2.push_back(253);
		float jump_high = pl.Jump_High();
		float jumphelp1 = -jump_high;
		float jumphelp2 = jump_high;
		float maxFireRate = 0.8;
		double fireRateTimer = 0;
		bool dead = true;
		bool open = true;
		bool sound = true;

		float fps = 100;

		while (w_window.isOpen())
		{
			sf::Event event;
			while (w_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					w_window.close();
				}
			}

			float dt = clock.getElapsedTime().asSeconds();
			if (1 / fps > dt)
			{
				sf::Time t = sf::seconds(1 / fps - dt);
				sf::sleep(t);
			}
			dt = clock.getElapsedTime().asSeconds();
			clock.restart();

			if (dead)
			{
				pl.anim(48, 0, 252, 350);
			}
			

			w_window.clear();

			float x = pl.X();
			float y = pl.Y();
			float vx = pl.P_vx();
			bool OnGround = pl.OnGround();

			if (dead)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					CurrentFrame += 10 * dt;
					if (CurrentFrame > 3)
					{
						CurrentFrame -= 3;
					}
					pl.setVelocityX(vx * dt);
					pl.anim(run_framex1[int(CurrentFrame)], 0, run_framex2[int(CurrentFrame)], 350);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					CurrentFrame += 10 * dt;
					if (CurrentFrame > 3)
					{
						CurrentFrame -= 3;
					}
					pl.setVelocityX(-vx * dt);
					pl.anim(run_framex1[int(CurrentFrame)] + run_framex2[int(CurrentFrame)], 0, -run_framex2[int(CurrentFrame)], 350);
				}

				if (OnGround)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						pl.OnGround(false);
					}
				}
				else
				{
					if (jump_high >= jumphelp1)
					{
						if (jump_high > 0)
						{
							pl.setVelocityY(-(pow(jump_high, 2) / 1.5) * dt);
						}
						else
						{
							pl.setVelocityY((pow(jump_high, 2) / 1.5) * dt);
						}
						jump_high -= 1;
					}
					else
					{
						pl.OnGround(true);
						jump_high = jumphelp2;
						pl.setVelocityY(765 - pl.Y());
					}
				}

				if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
				{
					pl.anim(48, 0, 252, 350);
				}

				fireRateTimer += dt;

				if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && fireRateTimer >= maxFireRate)
				{
					bullets.push_back(Bullet());
					int i = bullets.size() - 1;
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					{
						bullets[i].Setup(pl.X(), pl.Y() + 70, -2000, texture_bullet);
					}
					else
					{
						bullets[i].Setup(pl.X(), pl.Y() + 70, 2000, texture_bullet);
					}
					fireRateTimer = 0;
				}

				for (int i = 0; i < bullets.size(); i++)
				{
					if (bullets[i].Get().getPosition().x >= w_wd + 100 || bullets[i].Get().getPosition().x <= -100)
					{
						bullets.erase(bullets.begin() + i);
					}
					for (int j = 0; j < enemy.size(); j++)
					{
						if (DidRectCollide(bullets[i].Get().getGlobalBounds(), enemy[j]->Get().getGlobalBounds()))
						{
							bullets.erase(bullets.begin() + i);
							enemy.erase(enemy.begin() + j);
						}
					}
				}

				for (int i = 0; i < enemy.size(); i++)
				{
					if (DidRectCollide(pl.Get().getGlobalBounds(), enemy[i]->Get().getGlobalBounds()))
					{
						pl.anim(0, 0, 0, 0);
						dead = false;
					}
				}
			}

			if (pl.X() >= w_wd || pl.X() <= 0)
			{
				for (int i = 0; i < enemy.size(); i++)
				{
					if (open)
					{
						spider.SpecialAbility();
						open = false;
					}
				}
			}

			if (OnGround == false && sound)
			{
				bird.SpecialAbility();
				sound = false;
			}

			pl.Move();

			for (int i = 0; i < bullets.size(); i++)
			{
				bullets[i].Move(dt);
			}
			for (int i = 0; i < enemy.size(); i++)
			{
				enemy[i]->Move(dt);
			}

			w_window.draw(sprite_background);

			for (int i = 0; i < bullets.size(); i++)
			{
				w_window.draw(bullets[i].Get());
			}

			for (int i = 0; i < enemy.size(); i++)
			{
				w_window.draw(enemy[i]->Get());
			}

			w_window.draw(pl.Get());

			w_window.display();
		}
	}
}
