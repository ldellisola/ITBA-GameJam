#include "Allegro/AllegroV2/AllegroClassV2.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"

#include "Zombie.h"
#include "Stage.h"


int main(void) {
	AllegroClass allegro(Allegro::InitMode::Full, Allegro::NoValue, Allegro::NoValue, 30);
	allegro.uninstallMouseAddon();
	AllegroWindow window(1300, 600, allegro.getEventQueue(), "Albondicats");
	window.open();
	window.hideMouseCursor();
	window.setAsMain();
	window.setPosition(0, 0);
	AllegroEventHandler eventHandler(allegro.getEventQueue());


	AllegroSprite zombieSprite("zombieSprite.png");
	AllegroSprite playerSprite("PlayerSprite.png");
	AllegroSprite stageSprite("StageSprite.png",2000,2000);
	window.setImageAsBackground();
	

	Stage stage(&stageSprite, 550, 1300 / 2.0, 600 / 2.0);
	Player player(nullptr, nullptr, &playerSprite, 200, 200);
	Zombie zombie(nullptr, nullptr, &zombieSprite, 500, 500);

	stage.addZombie(&zombie);
	stage.addPlayer(&player);
	// UI



	//


	bool leave = false;
	do {
		eventHandler.getEvent();
		if (eventHandler.isThereEvent()) {

			leave = stage.run(eventHandler.ObtainEvent(),window );
			
		}

	} while (!leave);





	return 1; //Come along with me and the butterflies and bees
}