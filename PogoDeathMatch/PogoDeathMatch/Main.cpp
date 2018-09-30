#include "Allegro/AllegroV2/AllegroClassV2.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"
#include "Front.h"

#include "Zombie.h"
#include "Stage.h"


int main(void) {

	AllegroClass allegro(Allegro::InitMode::Full, Allegro::NoValue, Allegro::NoValue, 30);
	AllegroWindow window(1300, 600, allegro.getEventQueue(), "Albondicats");
	window.open();
	window.setAsMain();
	window.setPosition(0, 0);
	AllegroEventHandler eventHandler(allegro.getEventQueue());


	AllegroSprite zombieSprite("zombieSprite.png");
	AllegroSprite playerSprite("PlayerSprite.png");
	AllegroSprite stageSprite("StageSprite.png",2000,2000);
	window.setImageAsBackground();

	AllegroSoundFactory soundF;
	AllegroSound * playerjump = soundF.create("bounce.ogg", PlayMode::Once, 0);

	Stage stage(&stageSprite, 550, 1300 / 2.0, 600 / 2.0);
	Player player(playerjump, nullptr, &playerSprite, 200, 200);
	Zombie zombie(nullptr, nullptr, &zombieSprite, 500, 500);

	stage.addZombie(&zombie);
	stage.addPlayer(&player);

	// UI

	Menu mainMenu;
	window.insertLayout(mainMenu.getLayout());

	AllegroEvent alEv(EventType::Empty, 0);

	bool leave = false;
	do {
		eventHandler.getEvent();
		if (eventHandler.isThereEvent()) {

			alEv = eventHandler.ObtainEvent();
			


			if (alEv.getType() == EventType::MouseDown) {
				if (mainMenu.checkForPress(alEv.getX(), alEv.getY(), alEv.getTimestamp()) == EXIT)
					leave = true;
			}
			else if (alEv.getType() == EventType::DisplayClose)
				leave = true;
			window.update();


		}

	} while (!leave);
	

	//
	allegro.uninstallMouseAddon();


	//Menu mainMenu;
	//window.insertLayout(mainMenu.getLayout());

	/*AllegroEvent alEv(EventType::Empty, 0);*/


	leave = false;
	do {
		eventHandler.getEvent();
		if (eventHandler.isThereEvent()) {

			leave = stage.run(eventHandler.ObtainEvent(), window);			
		}

	} while (!leave);





	return 1;
}
