#include "BaseCharacter.h"

#include <math.h>

#define PI (3.141592)


BaseCharacter::BaseCharacter(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y, float force, float mass, float speed, float height, float width, float damp, float sizeCoef)
	: baseHeight(height), baseSpeed(speed), BaseWidth(width), dampCoef(damp), force(force), mass(mass), sizeCoef(sizeCoef)
{
	this->jumpSound = jump;
	this->hitSound = hit;
	this->sprite = sprite;

	this->x = x;
	this->y = y;
	this->angle = 0;
}

BaseCharacter::~BaseCharacter()
{
}

void BaseCharacter::draw()
{
	unsigned int tt = (this->maxTick / 2)- this->tick;

	this->width = this->BaseWidth + this->sizeCoef * (tt / (this->maxTick / 2));
	this->height = this->baseHeight + this->sizeCoef * (tt / (this->maxTick / 2));

	this->sprite->setDimensions(this->height, this->width);
	this->sprite->setAngle(this->angle);

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
		this->x += cosf(this->angle) * speed;
		this->y += sinf(this->angle) * speed;
	}
	else {
		// Solo se mueve en la direccion que lo empujaron
		this->x += cosf(this->angle) * (speed + appliedForce);
		this->y += sinf(this->angle) * (speed + appliedForce);
	}
	this->updateTick();
	this->DamperForce();
}

bool BaseCharacter::hit(BaseCharacter * other)
{
	if (this->x <= (other->x + other->BaseWidth) && (this->x + this->width) >= other->x)
		if ((this->y + this->height >= other->y) && (this->y) <= (other->y + other->baseHeight))
			if ( (sqrtf(powf(this->angle - other->angle, 2)) >=0)  &&  (sqrtf(powf(this->angle - other->angle, 2))<=PI/2.0)) {
				other->applyForce(this->force);
				return true;
			}
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
	this->tick = (++tick) % maxTick;
}


