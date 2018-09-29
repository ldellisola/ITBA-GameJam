#include "Player.h"
#include <math.h>

#define force (1)
#define mass (1)
#define speed (50)
#define height (50)
#define width (50)
#define damp (1)
#define sizeCoef (10)


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
	
	BaseCharacter::update();
	//if (moving) {
	//	
	//}
}

void Player::setMoving(bool moving_)
{
	this->moving = moving_;
}

void Player::setAngle(float x_, float y_)
{
	this->angle = atan2f(y_ - y, x_ - x);
}
