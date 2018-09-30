#include "Zombie.h"

float variateAngle(float angle);
#include "Front.h"


#define Radius (charSquare)

#define Force (10)
#define Speed (3)
#define Mass (15)
#define Damp (1)
#define SizeCoef (10)


Zombie::Zombie(AllegroSound *jump,AllegroSound * death,AllegroSprite * sprite,float x, float y,
	float force,float mass, float speed, float radius,float damp,float sizeCoef)
:BaseCharacter(jump,death,sprite,x,y, force, mass, speed, radius, damp, sizeCoef)
{
	this->x = x;
	this->y = y;
}


Zombie::~Zombie()
{
}

void Zombie::update()
{
	this->moving;
	this->angle = directions.front();

	this->updateTick();

	BaseCharacter::update();

	directions.pop();
}

void Zombie::calculateMovement(BaseCharacter * player)
{
	const float dt = 10;
	float difference;
	if (directions.size() == 0) {
		for (int j = 0; j < 3; j++) {
			float tempAngle = atan2f(player->getY() - this->y, player->getX() - this->x);
			difference = variateAngle(tempAngle);
			for (int i = 0; i < dt; i++) {
				this->directions.push(tempAngle + (difference/dt) * i);
			}
		}
	}
}


float variateAngle(float angle) {
	int var = (rand() % 80) - 40;
	return (var / 180.0) * PI;
}
