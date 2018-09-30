#pragma once
#include <queue>
#include <math.h>
#include "BaseCharacter.h"


class Zombie :
	public BaseCharacter
{
public:
	Zombie(AllegroSound *jump, AllegroSound * death, AllegroSprite * sprite, float x, float y,
		float force, float mass, float speed, float radius, float damp, float sizeCoef);
	~Zombie(); 
	void update();
	void calculateMovement(BaseCharacter * player);

	float givePoints() { return points; }
protected:
	float points;
private:
	std::queue<float> directions;
	
};

