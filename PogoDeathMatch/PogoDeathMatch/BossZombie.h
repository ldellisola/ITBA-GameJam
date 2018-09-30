#pragma once
#include "Zombie.h"
class BossZombie :public Zombie
{
public:
	BossZombie(AllegroSound *jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius);
	~BossZombie();
};

