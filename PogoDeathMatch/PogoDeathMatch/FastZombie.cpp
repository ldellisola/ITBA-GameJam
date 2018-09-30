#include "FastZombie.h"



#define FastForce (1)
#define FastMass (1)
#define FastSpeed (1)
#define FastDamp (1)
#define FastSizeCoef (1)


FastZombie::FastZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, FastForce, FastMass, FastSpeed, radius, FastDamp, FastSizeCoef)
{
}

FastZombie::~FastZombie()
{
}
