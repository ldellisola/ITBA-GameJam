#include "BossZombie.h"



#define BossForce ()
#define BossMass ()
#define BossSpeed ()
#define BossDamp ()
#define BossSizeCoef ()
#define BossPoints ()

BossZombie::BossZombie(AllegroSound * jump, AllegroSound * death, AllegroSprite * sprite, float x, float y, float radius)
	:Zombie(jump, death, sprite, x, y, BossForce, BossMass, BossSpeed, radius, BossDamp, BossSizeCoef)
{
	this->points = BossPoints;
}

BossZombie::~BossZombie()
{
}
