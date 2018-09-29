#include "Zombie.h"

float variateAngle(float angle);

#define Force (1)
#define Mass (1)
#define Speed (0.1)
#define Height  (50)
#define Width (50)
#define Damp (1)
#define SizeCoef (5)


Zombie::Zombie(AllegroSound *jump,AllegroSound * hit,AllegroSprite * sprite,float x, float y)
:BaseCharacter(jump,hit,sprite,x,y,Force,Mass,Speed,Height,Width,Damp,SizeCoef)
{
	this->x = x;
	this->y = y;
	this->angle = 0;
}


Zombie::~Zombie()
{
}

void Zombie::update()
{
	this->angle = directions.front();

	BaseCharacter::update();

	directions.pop();
}

void Zombie::calculateMovement(BaseCharacter * player)
{
	// DEBUG
	//if (directions.size() == 0) {
	//	float tempAngle = atan2f(0 - this->y, 0 - this->x);


	//	for (int i = 0; i < 5; i++) {
	//		this->directions.push(variateAngle(tempAngle));
	//	}
	//}

	if (directions.size() == 0) {
		float tempAngle = atan2f(player->getY() - this->y, player->getX() - this->x);


		for (int i = 0; i < 5; i++) {
			this->directions.push(variateAngle(tempAngle));
		}
	}

}


float variateAngle(float angle) {

	int var = (rand() % 200) - 100;

	return angle + var / 100.0;

}