#include "Allegro/AllegroV2/AllegroClassV2.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"

#include "Stage.h"



int main(void) {
	AllegroClass allegro(Allegro::InitMode::Full, Allegro::NoValue, Allegro::NoValue, 60);
	AllegroWindow window(1300, 600, allegro.getEventQueue(), "Albondicats");

	AllegroEventHandler eventHandler(allegro.getEventQueue());

	AllegroSprite stageSprite("stage");

	Stage stage(&stageSprite, 550, 1300 / 2.0, 600 / 2.0);

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