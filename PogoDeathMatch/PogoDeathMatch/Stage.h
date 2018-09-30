#pragma once

#include "BaseCharacter.h"
#include "Zombie.h"
#include "Player.h"
#include "Allegro\Allegro Wrapper\AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroSound.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include <vector>


enum class gameState { PLAYING, PAUSE, GAME_OVER, QUIT };

class Stage
{
public:
	Stage(AllegroSprite* stageSprite_, unsigned radius_, unsigned centerX_, unsigned centerY_);
	~Stage();
	void draw();
	void addPlayer(Player* player_);
	void loadSoundFactory(AllegroSoundFactory * sound);
	void loadZombieSprite(AllegroSprite * sprite);
	//void addZombie(Zombie* zombie_);

	gameState run(AllegroEvent ev, AllegroWindow& window);
	void restart();

	float getX() { return centerX; }
	float getY() { return centerY; }
	float getR() { return radius; }

	void randomlyGenerateZombies();

private:
	gameState update();
	AllegroSprite* stageSprite;
	unsigned radius;
	unsigned centerX;
	unsigned centerY;
	Player* player;
	std::vector<Zombie*> zombies;
	unsigned int maxZombies = 5;
	
	AllegroSoundFactory * soundFactory = nullptr;
	AllegroSprite * zombieSprite = nullptr;
};

