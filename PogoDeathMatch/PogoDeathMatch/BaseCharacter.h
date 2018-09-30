#pragma once

#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroSound.h"

#define PI (3.141592)

class BaseCharacter
{
public:
	BaseCharacter(AllegroSound * jump,AllegroSound * hit,AllegroSprite * sprite, float x, float y, float force, float mass, float speed, float radius, float damp, float sizeCoef);
	~BaseCharacter();

	void draw();
	void playJumpSound();
	void playDeathSound();
	virtual void update();
	bool hit(BaseCharacter * other);
	void applyForce(float force);

	float getX() { return x; }
	float getY() { return y; }
	float getR() { return radius; }

protected:
	bool moving;
	float x, y, radius;
	float angle,speed, forceAngle;
	const float force, mass, baseSpeed, baseRadius, dampCoef, sizeCoef;
	void updateTick();
	float appliedForce = 0;
private:

	void DamperForce();
	
	const unsigned int maxTick = 20;


	unsigned int tick =0;

	AllegroSprite * sprite = nullptr;
	AllegroSound * jumpSound = nullptr;
	AllegroSound * deathSound = nullptr;

};

