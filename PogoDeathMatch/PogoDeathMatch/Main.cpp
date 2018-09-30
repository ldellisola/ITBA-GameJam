#include "Allegro/AllegroV2/AllegroClassV2.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"
#include "Front.h"

#include "Zombie.h"
#include "Stage.h"



int main(void) {

	AllegroClass allegro(Allegro::InitMode::Full, Allegro::NoValue, Allegro::NoValue, 30);
	AllegroWindow window(DisplaySquare, DisplaySquare, allegro.getEventQueue(), "Albondicats");
	window.open();
	window.setAsMain();
	window.setPosition(0, 0);
	AllegroEventHandler eventHandler(allegro.getEventQueue());


	AllegroSprite zombieSprite("zombieSprite.png", charSquare, charSquare);
	AllegroSprite playerSprite("PlayerSprite.png", charSquare, charSquare);
	AllegroSprite stageSprite("StageSprite.png", DisplaySquare, DisplaySquare);
	window.setImageAsBackground();

	AllegroSoundFactory soundF;
	AllegroSound * playerjump = soundF.create("bounce.ogg", PlayMode::Once, 0);

	Stage stage(&stageSprite, DisplaySquare /2.0, DisplaySquare / 2.0, 600 / 2.0);
	Player player(playerjump, nullptr, &playerSprite, DisplaySquare / 2.0, DisplaySquare / 2.0);

	stage.addPlayer(&player);
	stage.loadSoundFactory(&soundF);
	stage.loadZombieSprite(&zombieSprite);

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
				switch (mainMenu.checkForPress(alEv.getX(), alEv.getY(), alEv.getTimestamp())) {
				case EXIT: leave = true;
					break;
				case PLAY:
					do {
						eventHandler.getEvent();
						if (eventHandler.isThereEvent()) {

							leave = stage.run(eventHandler.ObtainEvent(), window);
						}

					} while (!leave);
					break;
				}
			}
			else if (alEv.getType() == EventType::DisplayClose)
				leave = true;
			window.update();


		}

	} while (!leave);
	

	//
	allegro.uninstallMouseAddon();

	leave = false;
	do {
		eventHandler.getEvent();
		if (eventHandler.isThereEvent()) {

			leave = stage.run(eventHandler.ObtainEvent(), window);			
		}

	} while (!leave);





	return 1;
}
