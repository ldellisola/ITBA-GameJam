#pragma once
#include <queue>
#include <math.h>
#include "BaseCharacter.h"


class Zombie :
	public BaseCharacter
{
public:
	Zombie();
	~Zombie(); 
	void update();
	void calculateMovement(BaseCharacter * player);
private:
	std::queue<float> directions;
	
};

