#include "SlowZombie.h"



#define SlowForce (7)
#define SlowMass (10)
#define SlowSpeed (2)
#define SlowDamp (1)
#define SlowSizeCoef (1)
#define SlowPoints (10)


SlowZombie::SlowZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, SlowForce, SlowMass, SlowSpeed, radius, SlowDamp, SlowSizeCoef)
{
	this->points = SlowPoints;
}

SlowZombie::~SlowZombie()
{
}
