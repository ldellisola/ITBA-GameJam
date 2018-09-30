#include "FatZombie.h"



#define FatForce (4)
#define FatMass (40)
#define FatSpeed (0.5)
#define FatDamp (1)
#define FatSizeCoef (2)
#define FatPoints (50)

FatZombie::FatZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, FatForce, FatMass, FatSpeed, radius, FatDamp, FatSizeCoef)
{
	this->points = FatPoints;
}

FatZombie::~FatZombie()
{
}
