#include "Bullet.h"

namespace ez
{
	sf::Sprite sprite_bullet;

	Bullet::Bullet(float x, float y, float vx, sf::Texture bullet)
	{
		Setup(x, y, vx, bullet);
	}

	void Bullet::Setup(float x, float y, float vx, sf::Texture bullet)
	{
		b_x = x;
		b_y = y;
		b_vx = vx;
		texture_bullet = bullet;
		sprite_bullet.setTexture(texture_bullet);
		sprite_bullet.setPosition(b_x, b_y);
		sprite_bullet.setScale(0.1f, 0.1f);
	}

	sf::Sprite Bullet::Get()
	{
		return sprite_bullet;
	}

	void Bullet::setVelocityX(float dv)
	{
		b_x += dv;
	}
	float Bullet::X()
	{
		return b_x;
	}
	float Bullet::Y()
	{
		return b_y;
	}
	float Bullet::B_vx()
	{
		return b_vx;
	}
	void Bullet::B_vx(float vx)
	{
		b_vx = vx;
	}
	void Bullet::Move(double dt)
	{
		sprite_bullet.setPosition(sprite_bullet.getPosition().x + b_vx * dt, sprite_bullet.getPosition().y);
	}
}