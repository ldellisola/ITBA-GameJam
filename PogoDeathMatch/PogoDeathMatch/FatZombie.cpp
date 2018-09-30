#include "FatZombie.h"



#define FatForce (1)
#define FatMass (1)
#define FatSpeed (1)
#define FatDamp (1)
#define FatSizeCoef (1)
#define FatPoints (1)

FatZombie::FatZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, FatForce, FatMass, FatSpeed, radius, FatDamp, FatSizeCoef)
{
	this->points = FatPoints;
}

FatZombie::~FatZombie()
{
}
