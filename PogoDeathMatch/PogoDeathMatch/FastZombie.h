#pragma once
#include "Zombie.h"

class FastZombie :
	public Zombie
{
public:
	FastZombie(AllegroSound *jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius);
	~FastZombie();
};

