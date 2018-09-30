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
	//AllegroWindow window(1300, 650, allegro.getEventQueue(), "Albondicats");
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

	Stage stage(&stageSprite, DisplaySquare/2.0, DisplaySquare/2.0, 600/2.0);
	Player player(playerjump, nullptr, &playerSprite, DisplaySquare/2, DisplaySquare/2);
	Zombie zombie(nullptr, nullptr, &zombieSprite, DisplaySquare/5, DisplaySquare/5);

	stage.addZombie(&zombie);
	stage.addPlayer(&player);

	// UI

	Menu mainMenu;
	window.insertLayout(mainMenu.getLayout());

	AllegroEvent alEv(EventType::Empty, 0);

	bool isFirstTime = true;
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

					Stage.restart();

					bool isFirstTime = false;
					bool isPlaying = true;

				case CONTINUE:

					if (!isFirstTime) {
						do {
							eventHandler.getEvent();
							if (eventHandler.isThereEvent()) {
								isPlaying = stage.run(eventHandler.ObtainEvent(), window);
							}

						} while (isPlaying);
						break;
					}
				}
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


	//leave = false;
	//do {
	//	eventHandler.getEvent();
	//	if (eventHandler.isThereEvent()) {

	//		leave = stage.run(eventHandler.ObtainEvent(), window);			
	//	}

	//} while (!leave);





	return 1;
}
