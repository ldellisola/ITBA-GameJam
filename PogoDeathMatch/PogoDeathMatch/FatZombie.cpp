#include "FatZombie.h"



#define FatForce (10)
#define FatMass (50)
#define FatSpeed (1)
#define FatDamp (1)
#define FatSizeCoef (10)
#define FatPoints (50)

FatZombie::FatZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, FatForce, FatMass, FatSpeed, radius, FatDamp, FatSizeCoef)
{
	this->points = FatPoints;
}

FatZombie::~FatZombie()
{
}
