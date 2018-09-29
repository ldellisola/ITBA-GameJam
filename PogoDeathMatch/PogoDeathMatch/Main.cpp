#include "Allegro/AllegroV2/AllegroClassV2.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"

#include "Zombie.h"
#include "Stage.h"


int main(void) {
	AllegroClass allegro(Allegro::InitMode::Full, Allegro::NoValue, Allegro::NoValue, 60);
	AllegroWindow window(1300, 600, allegro.getEventQueue(), "Albondicats");
	window.open();
	window.setAsMain();
	window.setPosition(0, 0);
	AllegroEventHandler eventHandler(allegro.getEventQueue());


	AllegroSprite zombieSprite("zombieSprite.png");
	AllegroSprite playerSprite("PlayerSprite.png");
	AllegroSprite stageSprite("StageSprite.png",2000,2000);
	//AllegroBox background(0, 0, 2000, 2000);
	//window.loadImageBackground(al_load_bitmap("StageSprite.png"));
	window.setImageAsBackground();
	//window.update();
	

	Stage stage(&stageSprite, 550, 1300 / 2.0, 600 / 2.0);

	Zombie zombie(nullptr, nullptr, &zombieSprite, 500, 500);

	stage.addZombie(&zombie);
	// UI



	//


	bool leave = false;
	do {
		eventHandler.getEvent();
		if (eventHandler.isThereEvent()) {

			leave = stage.run(eventHandler.ObtainEvent(),window );
			
		}

	} while (!leave);





	return 1;
}