#pragma once

#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroSound.h"

#define PI (3.141592)

class BaseCharacter
{
public:
	BaseCharacter(AllegroSound * jump,AllegroSound * hit,AllegroSprite * sprite, float x, float y, float force, float mass, float speed, float height, float width, float damp, float sizeCoef);
	~BaseCharacter();

	void draw();
	void playJumpSound();
	void playHitSound();
	virtual void update();

	float getX() { return x; }
	float getY() { return y; }

protected:
	float x, y, height, width;
	float angle,speed;
	const float force, mass, baseSpeed, baseHeight, BaseWidth, dampCoef, sizeCoef;
private:
	bool hit(BaseCharacter * other);
	void applyForce(float force);

	void DamperForce();

	void updateTick();


	
	const unsigned int maxTick = 100;
	float appliedForce = 0;

	unsigned int tick =0;

	AllegroSprite * sprite = nullptr;
	AllegroSound * jumpSound = nullptr;
	AllegroSound * hitSound = nullptr;

};

