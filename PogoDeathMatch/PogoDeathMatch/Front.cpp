#include "Front.h"

int Menu::checkForPress(float mouseX, float mouseY, double timeStamp)
{

	buttonVal button = buttonVal::NONE;

	((AllegroToggle*) boxes[PLAY_ID])->toggle(mouseX, mouseY, timeStamp);

	if ( ( (AllegroToggle*) boxes[PLAY_ID])->isPressed() ) {
		button = buttonVal::PLAY;
	}


	((AllegroToggle*) boxes[CONT_ID])->toggle(mouseX, mouseY, timeStamp);

	if (((AllegroToggle*) boxes[CONT_ID])->isPressed()) {
		button = buttonVal::CONTINUE;
	}


	((AllegroToggle*) boxes[EXIT_ID])->toggle(mouseX, mouseY, timeStamp);

	if (((AllegroToggle*) boxes [EXIT_ID])->isPressed()) {
		button = buttonVal::EXIT;
	}

	return button;
}
