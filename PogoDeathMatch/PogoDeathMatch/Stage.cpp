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

void Stage::addPlayer(Player * player_)
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
	case EventType::DisplayClose:
		return true;
	case EventType::KeyDown:
		switch (ev.getValue())
		{
		case ALLEGRO_KEY_W:
			this->player->setMoving(true);
			break;
		case ALLEGRO_KEY_A:
			this->player->rotateLeft();
			break;
		case ALLEGRO_KEY_D:
			this->player->rotateRight();
			break;
		}
		break;
	case EventType::KeyUp:

		switch (ev.getValue())
		{
		case ALLEGRO_KEY_W:
		case ALLEGRO_KEY_A:
		case ALLEGRO_KEY_D:
			this->player->setMoving(false);
		}
		break;

	case EventType::Timer:



		this->player->update();

		for (int i = 0; i < this->zombies.size(); i++) {
			this->zombies[i]->calculateMovement(this->player);
			this->zombies[i]->update();
		}

		this->draw();
		this->player->draw();
		//window.update();
		for (int i = 0; i < this->zombies.size(); i++)
			this->zombies[i]->draw();
		al_flip_display();

		break;
	default:
		break;
	}

	return false;
}
