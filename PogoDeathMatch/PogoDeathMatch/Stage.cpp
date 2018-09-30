#include "Stage.h"
#include "Front.h"


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
	this->stageSprite->draw(0+radius, 0+ radius);
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

	bool isPlaying = true;
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
			this->player->setRotation(Rotation::Left,true);
			break;
		case ALLEGRO_KEY_D:
			this->player->setRotation(Rotation::Right,true);
			break;
			break;
		case ALLEGRO_KEY_Q:
			isPlaying = false;
			break;
	}
	break;
	case EventType::KeyUp:

		switch (ev.getValue())
		{
		case ALLEGRO_KEY_W:
			this->player->setMoving(false);
			break;
		case ALLEGRO_KEY_A:
			this->player->setRotation(Rotation::Left,false);
			break;
		case ALLEGRO_KEY_D:
			this->player->setRotation(Rotation::Right,false);
			break;
			
		}
		break;

	case EventType::Timer:
	
		for (int i = 0; i < this->zombies.size(); i++) {
			this->player->hit(zombies[i]);
		}
		this->player->update();

		for (int i = 0; i < this->zombies.size(); i++) {

		//	this->zombies[i]->hit(player);
			this->zombies[i]->calculateMovement(this->player);
			this->zombies[i]->update();
		}

		this->update();

		this->draw();
		this->player->draw();
		for (int i = 0; i < this->zombies.size(); i++)
			this->zombies[i]->draw();
		al_flip_display();

		break;
	default:
		break;
	}

	return isPlaying;
}

void Stage::update() {


	float playerNormal = sqrt(pow(this->player->getX() - (DisplaySquare / 2), 2.0) + pow(this->player->getY() - (DisplaySquare / 2), 2.0));

	if (playerNormal > (DisplaySquare / 2) ){

	//	for enemy  this->
	//	return GAME_OVER;
	//}




		
		
		
		
}