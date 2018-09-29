#include "Allegro/AllegroV2/AllegroClassV2.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"

#include "Zombie.h"
#include "Stage.h"


int main(void) {
<<<<<<< HEAD
	AllegroClass allegro(Allegro::InitMode::Full, Allegro::NoValue, Allegro::NoValue, 30);
=======
	AllegroClass allegro(Allegro::InitMode::Full, Allegro::NoValue, Allegro::NoValue, 60);
>>>>>>> parent of d9b9120... El menu funca che
	AllegroWindow window(1300, 600, allegro.getEventQueue(), "Albondicats");
	window.open();
	window.setAsMain();
	window.setPosition(0, 0);
	AllegroEventHandler eventHandler(allegro.getEventQueue());


	AllegroSprite zombieSprite("zombieSprite.png");
	AllegroSprite playerSprite("PlayerSprite.png");
	AllegroSprite stageSprite("StageSprite.png",2000,2000);
	window.setImageAsBackground();
<<<<<<< HEAD

=======
	
>>>>>>> parent of d9b9120... El menu funca che

	Stage stage(&stageSprite, 550, 1300 / 2.0, 600 / 2.0);
	Player player(nullptr, nullptr, &playerSprite, 200, 200);
	Zombie zombie(nullptr, nullptr, &zombieSprite, 500, 500);

	stage.addZombie(&zombie);
	stage.addPlayer(&player);
<<<<<<< HEAD

=======
>>>>>>> parent of d9b9120... El menu funca che
	// UI



	//

<<<<<<< HEAD
	//Menu mainMenu;
	//window.insertLayout(mainMenu.getLayout());

	bool leave = false;


	/*AllegroEvent alEv(EventType::Empty, 0);*/
=======
>>>>>>> parent of d9b9120... El menu funca che

	bool leave = false;
	do {
		eventHandler.getEvent();
		if (eventHandler.isThereEvent()) {
<<<<<<< HEAD
			leave = stage.run(eventHandler.ObtainEvent(), window);

			//alEv = eventHandler.ObtainEvent();
			//window.update();


			//if (alEv.getType() == EventType::MouseDown) {
			//	if (mainMenu.checkForPress(alEv.getX(), alEv.getY(), alEv.getTimestamp()) == EXIT)
			//		leave = true;
			//}
=======

			leave = stage.run(eventHandler.ObtainEvent(),window );
			
>>>>>>> parent of d9b9120... El menu funca che
		}

	} while (!leave);





	return 1;
}
