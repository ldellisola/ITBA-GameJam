#pragma once
#include "BaseCharacter.h"




class Player :
	public BaseCharacter
{
public:
	Player(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y);
	~Player();

	void update();
	void setMoving(bool moving_);
	void setAngle(float x_, float y_);
	void rotateLeft();
	void rotateRight();
private:
	bool moving;
};
