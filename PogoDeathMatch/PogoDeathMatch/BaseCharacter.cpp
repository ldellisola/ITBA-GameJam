#include "BaseCharacter.h"

#include <math.h>

#define PI (3.141592)

BaseCharacter::BaseCharacter()
	:baseHeight(), baseSpeed(), BaseWidth(), dampCoef(), force(), mass()
{
}


BaseCharacter::~BaseCharacter()
{
}

void BaseCharacter::draw()
{
	//if (this->tick < 10) {
	//	this->width =
	//}
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


