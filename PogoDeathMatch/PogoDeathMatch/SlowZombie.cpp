#include "SlowZombie.h"



#define SlowForce (6)
#define SlowMass (15)
#define SlowSpeed (4)
#define SlowDamp (1)
#define SlowSizeCoef (20)
#define SlowPoints (10)


SlowZombie::SlowZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, SlowForce, SlowMass, SlowSpeed, radius, SlowDamp, SlowSizeCoef)
{
	this->points = SlowPoints;
}

SlowZombie::~SlowZombie()
{
}
