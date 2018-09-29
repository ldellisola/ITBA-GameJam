#pragma once

#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroSound.h"

enum class Direction
{
	forward, backwards
};

class BaseCharacter
{
public:
	BaseCharacter();
	~BaseCharacter();

	void draw();
	void update();


private:
	bool hit(BaseCharacter * other);
	void applyForce(float force);

	void DamperForce();

	void updateTick();

	float x, y, height, width;
	float angle;
	const float force, mass,baseSpeed, baseHeight, BaseWidth, dampCoef;
	const unsigned int maxTick = 20;
	float appliedForce = 0, speed;

	unsigned int tick;

	AllegroSprite * sprite = nullptr;
	AllegroSound * jumpSound = nullptr;
	AllegroSound * hitSound = nullptr;

};

