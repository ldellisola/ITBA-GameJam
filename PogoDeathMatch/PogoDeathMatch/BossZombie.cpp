#include "BossZombie.h"



#define BossForce (1)
#define BossMass (1)
#define BossSpeed (1)
#define BossDamp (1)
#define BossSizeCoef (1)
#define BossPoints (1)

BossZombie::BossZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, BossForce, BossMass, BossSpeed, radius, BossDamp, BossSizeCoef)
{
	this->points = BossPoints;
}

BossZombie::~BossZombie()
{
}
