#pragma once

#include "Allegro/Allegro Wrapper/AllegroButton.h"
#include "Allegro/Allegro Wrapper/AllegroLayout.h"
#include "Allegro/AllegroV2/AllegroFactory.h"
#include "Allegro/Allegro Wrapper/WrittenBox.h"
#include "Allegro/Allegro Wrapper/AllegroButton.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"

//#define AlanDisplay
#define OtherDisplay

#ifdef AlanDisplay
#define DisplaySquare (600)
#define charSquare (20)
#endif
#ifdef OtherDisplay
#define DisplaySquare (1500)
#define charSquare (100)
#endif

#define FONT1_SIZE 50
#define FONT1_ID 1

#define WIDTH DisplaySquare
#define HEIGHT DisplaySquare
#define BUTTON_SIZE_H 100
#define BUTTON_SIZE_W 300
#define BUTTON_POS_Y 500
#define BUTTON_POS_X 100
#define BUTTON_TAB 400

#define PLAY_TEXT "PLAY"
#define CONTINUE_TEXT "CONT"
#define EXIT_TEXT "EXIT"

#define PLAY_ID 0
#define CONT_ID 1
#define EXIT_ID 2

enum buttonVal
{
	PLAY,
	CONTINUE,
	EXIT,
	NONE
};

typedef struct {

	AllegroToggle playButton;
	AllegroToggle contButton;
	AllegroToggle exitButton;

}menuResources;

class Menu {

public:

	Menu() : font("UbuntuMono-R.ttf", FONT1_SIZE, FONT1_ID), layout(WIDTH, HEIGHT, "PogoDeathmatch1.png", LayoutDrawMode::Slow) {

		AllegroColorFactory colorF;

		boxes.addBox(new AllegroButton(BUTTON_POS_X, BUTTON_POS_Y, BUTTON_SIZE_W, BUTTON_SIZE_H, PLAY_TEXT, &this->font, colorF.create("black"), PLAY_ID));
		boxes[PLAY_ID]->loadImageBackground("examplebutton1.png");
		boxes[PLAY_ID]->setImageAsBackground();
		boxes.addBox(new AllegroButton(BUTTON_POS_X + BUTTON_TAB, BUTTON_POS_Y, BUTTON_SIZE_W, BUTTON_SIZE_H, CONTINUE_TEXT, &this->font, colorF.create("black"), CONT_ID));
		boxes[CONT_ID]->loadImageBackground("examplebutton1.png");
		boxes[CONT_ID]->setImageAsBackground();
		boxes.addBox(new AllegroButton(BUTTON_POS_X + BUTTON_TAB * 2, BUTTON_POS_Y, BUTTON_SIZE_W, BUTTON_SIZE_H, EXIT_TEXT, &this->font, colorF.create("black"), EXIT_ID));
		boxes[EXIT_ID]->loadImageBackground("examplebutton1.png");
		boxes[EXIT_ID]->setImageAsBackground();

		layout.addBox(boxes[PLAY_ID]);
		layout.addBox(boxes[CONT_ID]);
		layout.addBox(boxes[EXIT_ID]);

	};

	AllegroLayout&  getLayout() { return (this->layout); }

	int checkForPress(float mouseX, float mouseY, double timeStamp);

private:

	BoxArray boxes;
	AllegroFont font;
	AllegroLayout layout;
};