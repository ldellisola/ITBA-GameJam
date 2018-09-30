#include "FastZombie.h"



#define FastForce (2)
#define FastMass (10)
#define FastSpeed (5)
#define FastDamp (0)
#define FastSizeCoef (0)
#define FastPoints (20)


FastZombie::FastZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, FastForce, FastMass, FastSpeed, radius, FastDamp, FastSizeCoef)
{
	this->points = FastPoints;
}

FastZombie::~FastZombie()
{
}
