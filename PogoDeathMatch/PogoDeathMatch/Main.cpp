#include "Allegro/AllegroV2/AllegroClassV2.h"
#include "Allegro/Allegro Wrapper/AllegroWindow.h"
#include "Allegro/Allegro Wrapper/AllegroSprite.h"
#include "Allegro/Allegro Wrapper/AllegroEvent.h"
#include "Front.h"

#include "Zombie.h"
#include "Stage.h"



int main(void) {
	srand(time(nullptr));
	AllegroClass allegro(Allegro::InitMode::Full, Allegro::NoValue, Allegro::NoValue, 30);
	AllegroWindow window(DisplaySquare, DisplaySquare, allegro.getEventQueue(), "Albondicats");
	window.open();
	window.setAsMain();
	window.setPosition(0, 0);
	AllegroEventHandler eventHandler(allegro.getEventQueue());


	//AllegroSprite zombieSprite("zombieSprite.png", charSquare, charSquare);
	AllegroSprite playerSprite("PlayerSprite.png", charSquare, charSquare);
	AllegroSprite stageSprite("StageSprite.png", DisplaySquare, DisplaySquare);
	window.setImageAsBackground();

	AllegroSoundFactory soundF;
	AllegroSound * menuMusic = soundF.create("Menu.ogg", PlayMode::Loop, 1,1,6);
	AllegroSound * gameOverMusic = soundF.create("Game Over.ogg", PlayMode::Loop, 2, 1, 6);
	AllegroSound * gameMusic = soundF.create("GameMusic.ogg", PlayMode::Loop, 3, 1, 6);
	AllegroSound * playerjump = soundF.create("bounce.ogg", PlayMode::Once, 4);


	Stage stage(&stageSprite, DisplaySquare /2.0, DisplaySquare / 2.0, 600 / 2.0);

	Player player(playerjump, nullptr, &playerSprite, DisplaySquare / 2.0, DisplaySquare / 2.0);


	stage.addPlayer(&player);
	stage.loadSoundFactory(&soundF);

	Menu mainMenu;
	AllegroLayout gameOverLayout(DisplaySquare, DisplaySquare, "gameover.png", LayoutDrawMode::Slow);
	window.insertLayout(mainMenu.getLayout());
	AllegroEvent alEv(EventType::Empty, 0);

	bool isFirstTime = true;
	bool leave = false;

	gameState currentState = gameState::PAUSE;


	menuMusic->play();

	do {

		eventHandler.getEvent();
		if (eventHandler.isThereEvent()) {

			alEv = eventHandler.ObtainEvent();
			

			if (currentState == gameState::GAME_OVER) {
				
				if (alEv.getType() == EventType::KeyDown) {
					al_stop_samples();
					menuMusic->play();
					currentState = gameState::PAUSE;
					window.deleteLayout();
					window.insertLayout(mainMenu.getLayout());
				}
			}

			if (alEv.getType() == EventType::MouseDown) {
				switch (mainMenu.checkForPress(alEv.getX(), alEv.getY(), alEv.getTimestamp())) {
				case INSTRUCTIONS:
					leave = mainMenu.runInstructions(&window,eventHandler);
					window.deleteLayout();
					window.insertLayout(mainMenu.getLayout());
					break;
				case CREDITS:
					leave = mainMenu.runCredits(&window, eventHandler);
					window.deleteLayout();
					window.insertLayout(mainMenu.getLayout());
					break;
				case EXIT: leave = true;
					break;

				case PLAY:
					menuMusic->stop();
					
					
					gameMusic->play();
					stage.restart();


					isFirstTime = false;

				case CONTINUE:
					currentState = gameState::PLAYING;
					if (!isFirstTime) {
						gameMusic->play();
						do {
							eventHandler.getEvent();
							if (eventHandler.isThereEvent()) {
								currentState = stage.run(eventHandler.ObtainEvent(), window);
							}

						} while (currentState == gameState::PLAYING);
						al_stop_samples();
						//gameMusic->stop();
						if (currentState == gameState::PAUSE)
							menuMusic->play();
						
						break;
					}
				}
			}
			else if (alEv.getType() == EventType::DisplayClose)
				leave = true;
		}

		if (currentState == gameState::GAME_OVER) {
			if (!isFirstTime) {
				al_stop_samples();
				gameOverMusic->playAtGain(5.0);
			}

			stage.gameover();
			currentState == gameState::PAUSE;
			isFirstTime = true;
			window.deleteLayout();
			window.insertLayout(gameOverLayout);

		}
		else if (currentState == gameState::QUIT) {
			al_stop_samples();
			leave = true;
		}

		window.update();

	} while (!leave);
	

	allegro.uninstallMouseAddon();

	return 0;
}
