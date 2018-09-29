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
	BaseCharacter(AllegroSound * jump,AllegroSound * hit,AllegroSprite * sprite, float x, float y, float force, float mass, float speed, float height, float width, float damp, float sizeCoef);
	~BaseCharacter();

	void draw();
	void playJumpSound();
	void playHitSound();
	void update();


private:
	bool hit(BaseCharacter * other);
	void applyForce(float force);

	void DamperForce();

	void updateTick();

	float x, y, height, width;
	float angle;
	const float force, mass,baseSpeed, baseHeight, BaseWidth, dampCoef, sizeCoef;
	const unsigned int maxTick = 20;
	float appliedForce = 0, speed;

	unsigned int tick;

	AllegroSprite * sprite = nullptr;
	AllegroSound * jumpSound = nullptr;
	AllegroSound * hitSound = nullptr;

};

