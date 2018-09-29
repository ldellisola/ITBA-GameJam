#include "BaseCharacter.h"

#include <math.h>


#define STARTANGLEDEG 90
#define ANGLEVARDEG (180.0/PI)

BaseCharacter::BaseCharacter(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y, float force, float mass, float speed, float radius, float damp, float sizeCoef)
	: baseSpeed(speed), baseRadius(radius), dampCoef(damp), force(force), mass(mass), sizeCoef(sizeCoef)
{

	this->angle = 0;
	this->jumpSound = jump;
	this->hitSound = hit;
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

	//this->width = this->BaseWidth + this->sizeCoef * (tt / (this->maxTick / 2.0));
	//this->height = this->baseHeight + this->sizeCoef * (tt / (this->maxTick / 2.0));

	this->sprite->setDimensions(2*this->radius, 2*this->radius);
	this->sprite->setAngle(STARTANGLEDEG + this->angle * 180.0/PI );

	this->sprite->draw(this->x, this->y);
}

void BaseCharacter::playJumpSound()
{
	this->jumpSound->play();
}

void BaseCharacter::playHitSound()
{
	this->hitSound->play();
}

void BaseCharacter::update()
{
	if (this->appliedForce == 0) {
		this->x += cosf(this->angle) * baseSpeed;
		this->y += sinf(this->angle) * baseSpeed;
	}
	else {
		// Solo se mueve en la direccion que lo empujaron
		this->x += cosf(this->angle) * (baseSpeed + appliedForce);
		this->y += sinf(this->angle) * (baseSpeed + appliedForce);
	}
	this->DamperForce();
}



bool BaseCharacter::hit(BaseCharacter * other)
{
	/*if (this->x <= (other->x + other->BaseWidth) && (this->x + this->width) >= other->x)
		if ((this->y + this->height >= other->y) && (this->y) <= (other->y + other->baseHeight))
			if ( (sqrtf(powf(this->angle - other->angle, 2)) >=0)  &&  (sqrtf(powf(this->angle - other->angle, 2))<=PI/2.0)) {
				other->applyForce(this->force);
				return true;
			}
	return false;*/
	return false;
}

void BaseCharacter::applyForce(float force)
{
	this->appliedForce = -force;
}

void BaseCharacter::DamperForce()
{
	if (this->appliedForce < 0) {
		this->appliedForce += this->mass *dampCoef;
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


