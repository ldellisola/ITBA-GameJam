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

bool Stage::run(AllegroEvent ev, AllegroWindow& window)
{
	switch (ev.getType())
	{
	case EventType::KeyDown:
		// movimiento del jugador
		break;
	case EventType::Timer:

		this->player->update();
		for (int i = 0; i < this->zombies.size(); i++)
			this->zombies[i]->update();

		this->draw();
		this->player->draw();
		for (int i = 0; i < this->zombies.size(); i++)
			this->zombies[i]->draw();
		window.update();
		break;
	default:
		break;
	}
}

