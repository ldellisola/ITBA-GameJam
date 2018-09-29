#pragma once
#include "BaseCharacter.h"
#include <math.h>

#define force (1)
#define mass (1)
#define speed (1)
#define height (1)
#define width (1)
#define damp (1)
#define sizeCoef (1)

class Player :
	public BaseCharacter
{
public:
	Player(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y);
	~Player();

	void update();
	void setMoving(bool moving_);
	void setAngle(float x_, float y_);
private:
	bool moving;
	unsigned angle;
};

