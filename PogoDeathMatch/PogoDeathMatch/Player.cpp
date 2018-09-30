#include "Player.h"
#include "Front.h"
#include <math.h>

#ifdef OtherDisplay
#define Force (50)
#define Speed (15)
#endif
#ifdef AlanDisplay
#define Force (50)
#define Speed (10)
#endif 




#define Mass (10)

#define Radius (charSquare)
#define Damp (1)
#define SizeCoef (7)


Player::Player(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y)
	: BaseCharacter(jump, death, sprite, x, y, Force, Mass, Speed, Radius, Damp, SizeCoef)
{
	this->x = x;
	this->y = y;
}

Player::~Player()
{
}

void Player::update()
{

	this->updateTick();
	if (left)
		this->rotateLeft();
	if (right)
		this->rotateRight();

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

void Player::setRotation(Rotation rot, bool on)
{
	if (rot == Rotation::Left)
		this->left = on;
	else
		this->right = on;

}

void Player::rotateLeft()
{
	float a = 15 *(float)PI / 180.0;
	this->angle =  this->angle -a;
}

void Player::rotateRight()
{
	this->angle += 15*PI / 180.0;
}

void Player::setCoords(float coordX, float coordY)
{
	this->x = coordX;
	this->y = coordY;
}
