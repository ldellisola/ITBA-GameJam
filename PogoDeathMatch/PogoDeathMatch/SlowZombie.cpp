#include "SlowZombie.h"



#define SlowForce (1)
#define SlowMass (1)
#define SlowSpeed (1)
#define SlowDamp (1)
#define SlowSizeCoef (1)
#define SlowPoints (1)


SlowZombie::SlowZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, SlowForce, SlowMass, SlowSpeed, radius, SlowDamp, SlowSizeCoef)
{
	this->points = SlowPoints;
}

SlowZombie::~SlowZombie()
{
}
