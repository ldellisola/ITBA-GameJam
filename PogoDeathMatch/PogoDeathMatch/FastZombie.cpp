#include "FastZombie.h"



#define FastForce (5)
#define FastMass (10)
#define FastSpeed (15)
#define FastDamp (1)
#define FastSizeCoef (5)
#define FastPoints (20)


FastZombie::FastZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, FastForce, FastMass, FastSpeed, radius, FastDamp, FastSizeCoef)
{
	this->points = FastPoints;
}

FastZombie::~FastZombie()
{
}
