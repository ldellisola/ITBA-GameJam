#pragma once

#include "BaseCharacter.h"
#include "Allegro\Allegro Wrapper\AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroSound.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include <vector>

class Stage
{
public:
	Stage(AllegroSprite* stageSprite_, unsigned radius_, unsigned centerX_, unsigned centerY_);
	~Stage();
	void draw();
	void addPlayer(BaseCharacter* player_);
	void addZombie(BaseCharacter* zombie_);

	bool run(AllegroEvent ev, AllegroWindow& window);

private:
	AllegroSprite* stageSprite;
	unsigned radius;
	unsigned centerX;
	unsigned centerY;
	BaseCharacter* player;
	std::vector<BaseCharacter*> zombies;

};

