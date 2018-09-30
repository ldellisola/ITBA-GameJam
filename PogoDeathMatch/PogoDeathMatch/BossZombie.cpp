#include "BossZombie.h"



#define BossForce (20)
#define BossMass (60)
#define BossSpeed (4)
#define BossDamp (2)
#define BossSizeCoef (15)
#define BossPoints (100)

BossZombie::BossZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, BossForce, BossMass, BossSpeed, radius, BossDamp, BossSizeCoef)
{
	this->points = BossPoints;
}

BossZombie::~BossZombie()
{
}
