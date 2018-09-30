#include "BaseCharacter.h"

#include <math.h>


#define ANGLEVARDEG (180.0/PI)

BaseCharacter::BaseCharacter(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y, float force, float mass, float speed, float radius, float damp, float sizeCoef)
	: baseSpeed(speed), baseRadius(radius), dampCoef(damp), force(force), mass(mass), sizeCoef(sizeCoef)
{

	this->angle = 0;
	this->jumpSound = jump;
	this->deathSound = hit;
	this->sprite = sprite;


	this->x = x;
	this->y = y;
}

BaseCharacter::~BaseCharacter()
{
}

void BaseCharacter::draw()
{

	int tt = (this->maxTick / 2)- this->tick;
	this->radius = this->baseRadius + this->sizeCoef * (tt / (this->maxTick / 2.0));

	this->sprite->setDimensions(2*this->radius, 2*this->radius);
	this->sprite->setAngle(this->angle * 180.0/PI + 90);

	this->sprite->draw(this->x, this->y);
}

void BaseCharacter::playJumpSound()
{
	this->jumpSound->play();
}

void BaseCharacter::playDeathSound()
{
	this->deathSound->play();
}

void BaseCharacter::update()
{
	if (this->appliedForce == 0) {
		this->x += cosf(this->angle) * baseSpeed;
		this->y += sinf(this->angle) * baseSpeed;
	}
	else {
		// Solo se mueve en la direccion que lo empujaron
		this->x += cosf(this->forceAngle) * (baseSpeed + appliedForce);
		this->y += sinf(this->forceAngle) * (baseSpeed + appliedForce);
	}
	this->DamperForce();
}



bool BaseCharacter::hit(BaseCharacter * other)
{

	if (sqrtf(powf(other->x - this->x, 2) + powf(other->y - this->y, 2)) <= other->baseRadius + this->baseRadius) {
		if (this->moving) {
			other->forceAngle = this->angle;
			other->applyForce(this->force);
		}
		this->forceAngle = other->angle;
		this->applyForce(other->force);
	}

	return false;
}

void BaseCharacter::applyForce(float force)
{
	this->moving = true;
	this->appliedForce = force;
}

void BaseCharacter::DamperForce()
{
	if (this->appliedForce > 0) {
		this->appliedForce -= this->mass *dampCoef;
		if (appliedForce <= 0) {
			this->moving = false;
			this->appliedForce = 0;
		}
	}
	else {
		this->appliedForce = 0;
	}
}

void BaseCharacter::updateTick()
{
	if (this->tick == 0 && this->jumpSound != nullptr)
		this->playJumpSound();
	this->tick = (++tick) % maxTick;
}


