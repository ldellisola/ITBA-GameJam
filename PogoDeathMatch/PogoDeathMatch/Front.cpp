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

	if (((AllegroButton*)boxes[CREDITS_ID])->click(mouseX, mouseY, timeStamp)) {
		button = buttonVal::CREDITS;
	}

	return button;
}

void Menu::runCredits(AllegroWindow * window, AllegroEventHandler & eventHandler)
{
	window->deleteLayout();
	window->insertLayout(credits);
	bool leave = false;

	while (!leave) {
		eventHandler.getEvent();

		if (eventHandler.isThereEvent()) {
			AllegroEvent ev = eventHandler.ObtainEvent();
			if (ev.getType() == EventType::MouseDown) {
				if (creditBoxes[CredButtonID]->click(ev.getX(), ev.getY(), ev.getTimestamp()))
					leave = true;
			}
			else if (ev.getType() == EventType::Timer)
				window->update();
			
		}
	}
	
}

void Menu::runInstructions(AllegroWindow * window, AllegroEventHandler & eventHandler)
{

	window->deleteLayout();
	window->insertLayout(instructions);
	bool leave = false;

	while (!leave) {
		eventHandler.getEvent();

		if (eventHandler.isThereEvent()) {
			AllegroEvent ev = eventHandler.ObtainEvent();
			if (ev.getType() == EventType::MouseDown) {
				if (instrucBoxes[InstButtonID]->click(ev.getX(), ev.getY(), ev.getTimestamp()))
					leave = true;
			}
			else if (ev.getType() == EventType::Timer)
				window->update();

		}
	}
}
