#pragma once
#include "Zombie.h"
class SlowZombie :
	public Zombie
{
public:
	SlowZombie(AllegroSound *jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius);
	~SlowZombie();
};

