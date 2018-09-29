#include "Player.h"
#include <math.h>

#define force (1)
#define mass (1)
#define speed (1)
#define height (1)
#define width (1)
#define damp (1)
#define sizeCoef (1)


Player::Player(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y)
	: BaseCharacter(jump, hit, sprite, x, y, force, mass, speed, height, width, damp, sizeCoef)
{
	this->x = x;
	this->y = y;
}

Player::~Player()
{
}

void Player::update(float x_, float y_)
{
	setAngle(x_, y_);

	if (moving) {
		BaseCharacter::update();
	}
}

void Player::setMoving(bool moving_)
{
	this->moving = moving_;
}

void Player::setAngle(float x_, float y_)
{
	this->angle = atan2f(y_ - y, x_ - x);
}
