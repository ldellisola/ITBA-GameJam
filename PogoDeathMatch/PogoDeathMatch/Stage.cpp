#include "Stage.h"
#include "Front.h"

bool intersects(Player * player, int x, int y);


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

void Stage::loadSoundFactory(AllegroSoundFactory * soundFactory)
{
	this->soundFactory = soundFactory;
}

void Stage::loadZombieSprite(AllegroSprite * sprite)
{
	this->zombieSprite = sprite;
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

		if (this->zombies.size() < this->maxZombies) {
			this->randomlyGenerateZombies();
		}

		al_clear_to_color(al_color_name("hotpink"));
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

	if (playerNormal > (DisplaySquare / 2)) {

		//	for enemy  this->
		//	return GAME_OVER;
		//}


	}
}

void Stage::randomlyGenerateZombies()
{
	int prob = rand() % 500;
	int x, y;


	if (prob == 0) {
		do {
			x = this->centerX + (rand() % (this->radius)) - this->radius / 2.0;
			y = this->centerY + (rand() % (this->radius)) - this->radius / 2.0;
		} while (!intersects(player, x, y));
		this->zombies.push_back(new Zombie(soundFactory->create("bounce.ogg", PlayMode::Once, 0), nullptr, this->zombieSprite, x, y));
	}
}


bool intersects(Player * player, int x, int y) {
	if (player->getX() - player->getR() / 2.0 <= x && x <= player->getX() + 2 * player->getR())
		if (player->getY() - player->getR() / 2.0 <= y && y <= player->getY() + 2 * player->getR())
			return false;
	return true;
}