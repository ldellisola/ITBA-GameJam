#include "FatZombie.h"



#define FatForce ()
#define FatMass ()
#define FatSpeed ()
#define FatDamp ()
#define FatSizeCoef ()
#define FatPoints ()

FatZombie::FatZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, FatForce, FatMass, FatSpeed, radius, FatDamp, FatSizeCoef)
{
	this->points = FatPoints;
}

FatZombie::~FatZombie()
{
}
