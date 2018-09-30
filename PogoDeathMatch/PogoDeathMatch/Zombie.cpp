#include "Zombie.h"

float variateAngle(float angle);
#include "Front.h"


#define Radius (charSquare)

#ifdef OtherDisplay
#define Force (1)
#define Speed (1)
#endif
#ifdef AlanDisplay
#define Force (50)
#define Speed (10)
#endif 



#define Mass (10)

#define Damp (1)
#define SizeCoef (7)


Zombie::Zombie(AllegroSound *jump,AllegroSound * death,AllegroSprite * sprite,float x, float y)
:BaseCharacter(jump,death,sprite,x,y,Force,Mass,Speed,Radius,Damp,SizeCoef)
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
