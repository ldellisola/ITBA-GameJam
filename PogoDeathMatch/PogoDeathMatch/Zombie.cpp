#include "Zombie.h"

float variateAngle(float angle);

#define Force (1)
#define Mass (1)
#define Speed (0.1)
#define Height  (50)
#define Width (50)
#define Damp (1)
#define SizeCoef (15)


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

	this->updateTick();

	BaseCharacter::update();

	directions.pop();
}

void Zombie::calculateMovement(BaseCharacter * player)
{
	if (directions.size() == 0) {
		for (int j = 0; j < 3; j++) {
			float tempAngle = atan2f(player->getY() - this->y, player->getX() - this->x);
			tempAngle = variateAngle(tempAngle);
			for (int i = 0; i < 400; i++) {
				this->directions.push(tempAngle);
			}
		}
	}
}


float variateAngle(float angle) {
	int var = (rand() % 100) - 50;
	return angle + (var / 180.0) * PI;
}
