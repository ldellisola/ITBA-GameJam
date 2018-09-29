#include "Stage.h"



Stage::Stage(AllegroSprite* stageSprite_, unsigned radius_, unsigned centerX_, unsigned centerY_)
{
	this->stageSprite = stageSprite_;
	this->radius = radius_;
	this->centerX = centerX_;
	this->centerY = centerY_;
}


Stage::~Stage()
{
}


void Stage::draw() 
{
	this->stageSprite->draw(0, 0);
}

void Stage::addPlayer(BaseCharacter * player_)
{
	this->player = player_;
}

void Stage::addZombie(Zombie * zombie_)
{
	this->zombies.push_back(zombie_);
}

bool Stage::run(AllegroEvent ev, AllegroWindow& window)
{
	switch (ev.getType())
	{
	case EventType::KeyDown:
		// movimiento del jugador
		break;
	case EventType::Timer:

		//this->player->update();
		for (int i = 0; i < this->zombies.size(); i++) {
			this->zombies[i]->calculateMovement(nullptr);
			this->zombies[i]->update();
		}

		//this->draw();
		//this->player->draw();
		for (int i = 0; i < this->zombies.size(); i++)
			this->zombies[i]->draw();
		window.update();
		break;
	default:
		break;
	}

	return false;
}

