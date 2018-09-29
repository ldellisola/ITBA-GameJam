#include "Player.h"



Player::Player(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y)
	: BaseCharacter(jump, hit, sprite, x, y, force, mass, speed, height, width, damp, sizeCoef)
{
	this->x = x;
	this->y = y;
}

Player::~Player()
{
}

void Player::update()
{
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
