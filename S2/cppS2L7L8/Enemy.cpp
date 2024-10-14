#include "Enemy.h"

namespace ez
{
	Enemy::Enemy(float x, float y, float vx, sf::Texture texture, float scaleFactor)
	{
		Setup(x, y, vx, texture, scaleFactor);
	}

	void Enemy::Setup(float x, float y, float vx, sf::Texture texture, float scaleFactor)
	{
		e_x = x;
		e_y = y;
		e_vx = vx;
		texture_enemy = texture;
		sprite_enemy.setTexture(texture_enemy);
		sprite_enemy.setScale(scaleFactor, scaleFactor);
		sprite_enemy.setPosition(e_x, e_y);
	}
	sf::Sprite Enemy::Get()
	{
		return sprite_enemy;
	}

}