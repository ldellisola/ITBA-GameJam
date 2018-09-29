#pragma once
#include "BaseCharacter.h"


enum class Rotation
{
	Left, Right
};

class Player :
	public BaseCharacter
{
public:
	Player(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y);
	~Player();

	void update();
	void setMoving(bool moving_);
	void setAngle(float x_, float y_);
	void setRotation(Rotation rot,bool on);
	void rotateLeft();
	void rotateRight();
private:
	bool moving;
	bool left = false;
	bool right = false;
};
