#include "BossZombie.h"



#define BossForce (6)
#define BossMass (15)
#define BossSpeed (1)
#define BossDamp (1)
#define BossSizeCoef (15)
#define BossPoints (25)

BossZombie::BossZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, BossForce, BossMass, BossSpeed, radius, BossDamp, BossSizeCoef)
{
	this->points = BossPoints;
}

BossZombie::~BossZombie()
{
}
