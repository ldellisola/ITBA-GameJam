#include "Stage.h"
#include <iostream>
#include "Front.h"

bool intersects(Player * player, Stage*stage, int x, int y);

Stage::Stage(AllegroSprite* stageSprite_, unsigned radius_, unsigned centerX_, unsigned centerY_)
{
	this->stageSprite = stageSprite_;
	this->radius = radius_;
	this->centerX = centerX_;
	this->centerY = centerY_;
	this->bossZombieSprite = new AllegroSprite("zombie_boss.png");
	this->fastZombieSprite = new AllegroSprite("zombie_flash.png");
	this->fatZombieSprite = new AllegroSprite("zombie_fat.png");
	this->slowZombieSprite = new AllegroSprite("zombieSprite.png");
}


Stage::~Stage()
{
	delete bossZombieSprite;
	delete fastZombieSprite;
	delete fatZombieSprite;
	delete slowZombieSprite;
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





gameState Stage::run(AllegroEvent ev, AllegroWindow& window)
{

	gameState currentState = gameState::PLAYING;

	switch (ev.getType())
	{
	case EventType::DisplayClose:
		return gameState::QUIT;
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
			currentState = gameState::PAUSE;
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

			this->zombies[i]->calculateMovement(this->player);
			this->zombies[i]->update();
		}

		currentState = this->update();

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

	return currentState;
}


gameState Stage::update() {

	gameState currentState = gameState::PLAYING;

	float playerNormal = sqrt(pow(this->player->getX() - (DisplaySquare / 2), 2.0) + pow(this->player->getY() - (DisplaySquare / 2), 2.0));


	if (playerNormal > (DisplaySquare / 2)) {


		for (int i = 0; i < this->zombies.size(); i++)
			zombies.erase(zombies.begin() + i);

		return gameState::GAME_OVER;
	}
	else {
		std::vector<int> zombiesToKill;

		float zombieNormal;

		for (int i = this->zombies.size()-1; i >=0 ; i--) {
			zombieNormal = sqrt(pow(this->zombies[i]->getX() - (DisplaySquare / 2), 2.0) + pow(this->zombies[i]->getY() - (DisplaySquare / 2), 2.0));

			if (zombieNormal > (DisplaySquare / 2)) {
				this->score += zombies[i]->givePoints();
				delete this->zombies[i];
				zombiesToKill.push_back(i);
			}
		}

		for (int i = 0; i < zombiesToKill.size(); i++)
			zombies.erase(zombies.begin() + zombiesToKill[i]);

	}

	return currentState;

}

void Stage::randomlyGenerateZombies()
{
	int base = maxZombies - this->zombies.size();
	int prob = rand() % (int)(100000/ (1+base*base*base*base));
	int x, y;
	static int zombiesSpawned = 0;

	if (prob < 50) {

	int index = (rand() % (5));
	int pos[10] = { this->radius,this->radius,
					this->radius,this->radius *1.5,
					this->radius,this->radius * 0.5,
					this->radius *0.5,this->radius,
					this->radius * 1.5, this->radius };



	if (prob == 0 && zombiesSpawned > 40) {
		this->zombies.push_back(new BossZombie(soundFactory->create("bounce.ogg", PlayMode::Once, 0), nullptr, this->bossZombieSprite, pos[2 * index], pos[2 * index + 1], 200));
		++zombiesSpawned;
	}
	else if (prob < 10 && zombiesSpawned>30) {
		this->zombies.push_back(new FatZombie(soundFactory->create("bounce.ogg", PlayMode::Once, 0), nullptr, this->fatZombieSprite, pos[2*index], pos[2 * index +1], 150));
		++zombiesSpawned;
	}
	else if (prob < 25&& zombiesSpawned>10) {
		this->zombies.push_back(new FastZombie(soundFactory->create("bounce.ogg", PlayMode::Once, 0), nullptr, this->fastZombieSprite, pos[2 * index], pos[2 * index + 1], 50));
		++zombiesSpawned;
	}
	else {
		this->zombies.push_back(new SlowZombie(soundFactory->create("bounce.ogg", PlayMode::Once, 0), nullptr, this->slowZombieSprite, pos[2 * index], pos[2 * index + 1], 75));
		++zombiesSpawned;
	}
	}
}


bool intersects(Player * player,Stage*stage,  int x, int y) {
	if (hypotf(stage->getX() - x  ,stage->getY() - y  ) < stage->getR())
			return false;
	return true;
}

void Stage::restart() {

	this->player->setCoords(DisplaySquare / 2, DisplaySquare / 2);
	this->player->setMoving(false);
	this->player->setRotation(Rotation::Left, false);
	this->player->setRotation(Rotation::Right, false);
	this->zombiesSpawned = 0;

	for (int i = 0; i < this->zombies.size(); i++)
		zombies.erase(zombies.begin() + i);


}
