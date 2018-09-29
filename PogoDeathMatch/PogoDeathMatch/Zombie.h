#pragma once
#include <queue>
#include <math.h>
#include "BaseCharacter.h"


class Zombie :
	public BaseCharacter
{
public:
	Zombie(AllegroSound *jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y);
	~Zombie(); 
	void update();
	void calculateMovement(BaseCharacter * player);
private:
	std::queue<float> directions;
	
};

