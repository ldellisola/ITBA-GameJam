#pragma once
#include "Zombie.h"
class FatZombie :
	public Zombie
{
public:
	FatZombie(AllegroSound *jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius);
	~FatZombie();
};

