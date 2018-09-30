#include "BossZombie.h"



#define BossForce (40)
#define BossMass (40)
#define BossSpeed (4)
#define BossDamp (2.5)
#define BossSizeCoef (30)
#define BossPoints (100)

BossZombie::BossZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, BossForce, BossMass, BossSpeed, radius, BossDamp, BossSizeCoef)
{
	this->points = BossPoints;
}

BossZombie::~BossZombie()
{
}
