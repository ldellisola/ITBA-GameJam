#pragma once

#include "Allegro/Allegro Wrapper/AllegroButton.h"
#include "Allegro/Allegro Wrapper/AllegroLayout.h"
#include "Allegro/AllegroV2/AllegroFactory.h"
#include "Allegro/Allegro Wrapper/WrittenBox.h"
#include "Allegro/Allegro Wrapper/AllegroButton.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"
#include "Allegro/Allegro Wrapper/WrittenBox.h"

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
#define BUTTON2_POS_Y 800
#define BUTTON_POS_X 100
#define BUTTON_TAB 400

#define PLAY_TEXT "PLAY"
#define CONTINUE_TEXT "CONT"
#define EXIT_TEXT "EXIT"
#define INSTRUCTIONS_TEXT "INSTRUCTIONS"
#define CREDITS_TEXT "Creditos"

#define PLAY_ID 0
#define CONT_ID 1
#define EXIT_ID 2
#define INSTRUCTIONS_ID 3
#define CREDITS_ID 4


#define InstructionsTitle "Instrucciones:"
#define InstTitleID 1
#define Instructions1 "- Presiona 'W' para avanzar hacia adelante."
#define Inst1ID 2
#define Instructions2 "- Presiona 'A' o 'S' para rotar."
#define Inst2ID 3
#define Instructions3 "El juego consiste en empujar "
#define Inst3ID 4
#define Instructions4 "a los enemigos afuera de la arena"
#define Inst4ID 6
#define InstButtonID 5

#define CreditsTitle "Creditos:"
#define CredTitleID 1
#define Credits1 "Musica: Mariano Merdinger"
#define Cred1ID 2
#define Credits2 "Arte/Programacion: Franco Moriconi"
#define Cred2ID 3
#define Credits3 "Programacion: Alan Mechoulam"
#define Cred3ID 4
#define Credits4 "Programacion: Lucas Dell'Isola"
#define Cred4ID 5
#define CredButtonID 6

enum buttonVal
{
	PLAY,
	CONTINUE,
	EXIT,
	INSTRUCTIONS,
	CREDITS,
	NONE
};



typedef struct {

	AllegroToggle playButton;
	AllegroToggle contButton;
	AllegroToggle exitButton;

}menuResources;


class Menu {

public:

	Menu() : colorFactory(),font("UbuntuMono-R.ttf", FONT1_SIZE, FONT1_ID), layout(WIDTH, HEIGHT, "PogoDeathmatch1.png", LayoutDrawMode::Slow)
	,credits(WIDTH,HEIGHT,colorFactory.create("black"),LayoutDrawMode::Slow), instructions(WIDTH, HEIGHT, colorFactory.create("black"), LayoutDrawMode::Slow)
	{



		boxes.addBox(new AllegroButton(BUTTON_POS_X, BUTTON_POS_Y, BUTTON_SIZE_W, BUTTON_SIZE_H, PLAY_TEXT, &this->font, colorFactory.create("black"), PLAY_ID));
		boxes[PLAY_ID]->loadImageBackground("examplebutton1.png");
		boxes[PLAY_ID]->setImageAsBackground();
		boxes.addBox(new AllegroButton(BUTTON_POS_X + BUTTON_TAB, BUTTON_POS_Y, BUTTON_SIZE_W, BUTTON_SIZE_H, CONTINUE_TEXT, &this->font, colorFactory.create("black"), CONT_ID));
		boxes[CONT_ID]->loadImageBackground("examplebutton1.png");
		boxes[CONT_ID]->setImageAsBackground();
		boxes.addBox(new AllegroButton(BUTTON_POS_X + BUTTON_TAB * 2, BUTTON_POS_Y, BUTTON_SIZE_W, BUTTON_SIZE_H, EXIT_TEXT, &this->font, colorFactory.create("black"), EXIT_ID));
		boxes[EXIT_ID]->loadImageBackground("examplebutton1.png");
		boxes[EXIT_ID]->setImageAsBackground();
		boxes.addBox(new AllegroButton(BUTTON_POS_X + BUTTON_TAB, BUTTON2_POS_Y, BUTTON_SIZE_W, BUTTON_SIZE_H, INSTRUCTIONS_TEXT, &this->font, colorFactory.create("black"), INSTRUCTIONS_ID));
		boxes[INSTRUCTIONS_ID]->loadImageBackground("examplebutton1.png");
		boxes[INSTRUCTIONS_ID]->setImageAsBackground();
		boxes.addBox(new AllegroButton(BUTTON_POS_X + BUTTON_TAB * 2, BUTTON2_POS_Y, BUTTON_SIZE_W, BUTTON_SIZE_H, CREDITS_TEXT, &this->font, colorFactory.create("black"), CREDITS_ID));
		boxes[CREDITS_ID]->loadImageBackground("examplebutton1.png");
		boxes[CREDITS_ID]->setImageAsBackground();

		layout.addBox(boxes[PLAY_ID]);
		layout.addBox(boxes[CONT_ID]);
		layout.addBox(boxes[EXIT_ID]);
		layout.addBox(boxes[INSTRUCTIONS_ID]);
		layout.addBox(boxes[CREDITS_ID]);

		///////////


		instrucBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 600, (float) 100.0, 1200,400,InstructionsTitle, &font, colorFactory.create("white"), InstTitleID));
		instrucBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 600, (float) HEIGHT/2.0 - 300.0, 1200, 400, Instructions1, &font, colorFactory.create("white"), Inst1ID));
		instrucBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 600, (float)(HEIGHT / 2.0) - 200.0 , 1200, 400, Instructions2, &font, colorFactory.create("white"), Inst2ID));
		instrucBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 700, (float)(HEIGHT / 2.0)-500 , 1500, 400, Instructions3, &font, colorFactory.create("white"), Inst3ID));
		instrucBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 700, (float)(HEIGHT / 2.0) - 400, 1500, 400, Instructions4, &font, colorFactory.create("white"), Inst4ID));
		instrucBoxes.addBox(new AllegroButton((float)WIDTH / 2.0 -600 , (float)(HEIGHT / 2.0)+200, 1200, 400, "Volver",&font, colorFactory.create("white"), InstButtonID));
		instrucBoxes[InstButtonID]->setBorderThickness(5);
		instrucBoxes[InstButtonID]->setBorderColor(colorFactory.create("white"));

		instructions.addBox(instrucBoxes[InstTitleID]);
		instructions.addBox(instrucBoxes[Inst1ID]);
		instructions.addBox(instrucBoxes[Inst2ID]);
		instructions.addBox(instrucBoxes[Inst3ID]);
		instructions.addBox(instrucBoxes[Inst4ID]);
		instructions.addBox(instrucBoxes[InstButtonID]);


		/////////



		creditBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 600, (float) 100.0, 1200, 400, CreditsTitle, &font, colorFactory.create("white"), CredTitleID));
		creditBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 600, (float)HEIGHT / 2.0 - 500.0, 1200, 400, Credits1, &font, colorFactory.create("white"), Cred1ID));
		creditBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 600, (float)(HEIGHT / 2.0) - 400.0, 1200, 400, Credits2, &font, colorFactory.create("white"), Cred2ID));
		creditBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 600, (float)(HEIGHT / 2.0)-300, 1200, 400,Credits3, &font, colorFactory.create("white"), Cred3ID));
		creditBoxes.addBox(new AllegroWrittenBox((float)WIDTH / 2.0 - 600, (float)(HEIGHT / 2.0) -200, 1200, 400, Credits4, &font, colorFactory.create("white"), Cred4ID));
		creditBoxes.addBox(new AllegroButton((float)WIDTH / 2.0 - 600, (float)(HEIGHT / 2.0) + 300, 1200, 400, "Volver", &font, colorFactory.create("white"), CredButtonID));
		creditBoxes[CredButtonID]->setBorderThickness(5);
		creditBoxes[CredButtonID]->setBorderColor(colorFactory.create("white"));

		credits.addBox(creditBoxes[CredTitleID]);
		credits.addBox(creditBoxes[Cred1ID]);
		credits.addBox(creditBoxes[Cred2ID]);
		credits.addBox(creditBoxes[Cred3ID]);
		credits.addBox(creditBoxes[Cred4ID]);
		credits.addBox(creditBoxes[CredButtonID]);

	};

	AllegroLayout&  getLayout() { return (this->layout); }

	int checkForPress(float mouseX, float mouseY, double timeStamp);

	void runCredits(AllegroWindow* window, AllegroEventHandler & eventHandler);

	void runInstructions(AllegroWindow* window, AllegroEventHandler & eventHandler);

private:

	BoxArray boxes;
	AllegroFont font;
	AllegroLayout layout;

	AllegroColorFactory colorFactory;

	AllegroLayout instructions;
	BoxArray instrucBoxes;

	AllegroLayout credits;
	BoxArray creditBoxes;


};