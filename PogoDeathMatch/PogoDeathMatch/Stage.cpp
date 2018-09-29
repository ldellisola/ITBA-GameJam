#include "Stage.h"



Stage::Stage(AllegroSprite* stageSprite_, unsigned radius_, unsigned centerX_, unsigned centerY_)
{
}


Stage::~Stage()
{
}


void Stage::draw() 
{
	this->stageSprite->draw(this->centerX, this->centerY);
}

void Stage::addPlayer(BaseCharacter * player_)
{
	this->player = player_;
}

void Stage::addZombie(BaseCharacter * zombie_)
{
	this->zombies.push_back(zombie_);
}

