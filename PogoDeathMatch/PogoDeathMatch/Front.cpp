#include "Front.h"

int Menu::checkForPress(float mouseX, float mouseY, double timeStamp)
{

	buttonVal button = buttonVal::NONE;

	if (((AllegroButton*)boxes[PLAY_ID])->click(mouseX, mouseY, timeStamp)) {
		button = buttonVal::PLAY;
	}


	if (((AllegroButton*) boxes[CONT_ID])->click(mouseX, mouseY, timeStamp)) {
		button = buttonVal::CONTINUE;
	}

	if (((AllegroButton*) boxes [EXIT_ID])->click(mouseX, mouseY, timeStamp)) {
		button = buttonVal::EXIT;
	}

	if (((AllegroButton*) boxes [INSTRUCTIONS_ID])->click(mouseX, mouseY, timeStamp)) {
		button = buttonVal::INSTRUCTIONS;
	}

	return button;
}
