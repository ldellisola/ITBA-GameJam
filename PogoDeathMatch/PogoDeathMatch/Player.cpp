#include "Player.h"
#include <math.h>

#define Force (1)
#define Mass (1)
#define Speed (0.5)
#define Height (50)
#define Width (50)
#define Damp (1)
#define SizeCoef (10)


Player::Player(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y)
	: BaseCharacter(jump, hit, sprite, x, y, Force, Mass, Speed, Height, Width, Damp, SizeCoef)
{
	this->x = x;
	this->y = y;
}

Player::~Player()
{
}

void Player::update()
{
	switch (rotation)
	{
	case Rotation::Left:
		this->rotateLeft();
		break;
		case Rotation::Right:
		this->rotateRight();
		break;
	}
	if (moving)
		BaseCharacter::update();



}

void Player::setMoving(bool moving_)
{
	this->moving = moving_;
	if (moving)
		this->speed = baseSpeed;
	else
		this->speed = 0;
}

void Player::setAngle(float x_, float y_)
{
	this->angle = atan2f(y_ - y, x_ - x);
}

void Player::setRotation(Rotation rot)
{
	this->rotation = rot;
}

void Player::rotateLeft()
{
	float a = 0.3 *(float)PI / 180.0;
	this->angle =  this->angle -a;
}

void Player::rotateRight()
{
	this->angle += 0.3*PI / 180.0;
}
