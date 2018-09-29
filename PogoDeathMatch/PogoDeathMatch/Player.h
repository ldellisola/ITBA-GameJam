#pragma once
#include "BaseCharacter.h"


enum class Rotation
{
	Left, Right, None
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
	void setRotation(Rotation rot);
	void rotateLeft();
	void rotateRight();
private:
	bool moving;
	Rotation rotation = Rotation::None;
};
