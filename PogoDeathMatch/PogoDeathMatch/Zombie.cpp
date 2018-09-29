#include "Zombie.h"

float variateAngle(float angle);


Zombie::Zombie()
	:
BaseCharacter(AllegroSound * jump, AllegroSound * hit, AllegroSprite * sprite, float x, float y, float force, float mass, float speed, float height, float width, float damp, float sizeCoef)
{
}


Zombie::~Zombie()
{
}

void Zombie::update()
{
	this->angle = directions.front();

	BaseCharacter::update();

	directions.pop();
}

void Zombie::calculateMovement(BaseCharacter * player)
{
	if (directions.size() == 0) {
		float tempAngle = atan2f(player->getY() - this->y, player->getX() - this->x);


		for (int i = 0; i < 5; i++) {
			this->directions.push(variateAngle(tempAngle));
		}
	}

}


float variateAngle(float angle) {

	int var = (rand() % 200) - 100;

	return angle + var / 100.0;

}