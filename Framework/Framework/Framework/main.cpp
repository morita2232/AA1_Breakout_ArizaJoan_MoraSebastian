#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <map>

#include "Scene.h"
#include "RankingScene.h"
#include "GameManager.h"
#include "GameplayScene.h"
#include "MenuScene.h"
#include "GameOverScene.h"
#include "CreditsScene.h"


//TODO
/*

-Moverse con las flechas izquierda y derecha -> LISTO

-Cuando destruye un bloque sumar 15 puntos -> LISTO
-Dar 5 puntos de forma acumulativa por cada bloque que destrya antes de tocar la pala -> LISTO

-3 vidas, si toca la pared de abajo se quita 1 vida -> LISTO
-Si no hay vidas o no hay bloques se acaba el juego -> MEDIO LISTO

-Pedir el nombre del jugador cuando se acaba la partida para guardar la puntuacion

-Guardar las 5 mejores puntuaciones de forma ordenada (podemos usar un algoritmo bubble sort)

*/

int main(){
	srand(time(NULL));

	//The scenes are stored in a map
	// KEY -> Name of the scene
	// VALUE -> Pointer to the scene object
	// 
	//We store the current scene to update and render it.

	std::map<std::string, Scene*> scenes;
	Scene* currentScene;

	RankingScene* rankingScene = new RankingScene();

	GameManager* gameManager = new GameManager();

	//Create the scenes
	scenes.emplace("Menu", new MenuScene(scenes, gameManager, rankingScene));
	scenes.emplace("Gameplay", new GameplayScene(*gameManager, scenes, rankingScene));
	scenes.emplace("Ranking",rankingScene);
	scenes.emplace("Credits", new CreditsScene());

	//Select the starting scene, in this case, the main menu
	currentScene = scenes["Menu"];
	currentScene->OnEnter();

	while (true) {
		
		//UPDATE
		currentScene->Update();

		//RENDER
		system("cls");
		ConsoleSetColor(WHITE, BLACK);
		currentScene->Render();

		//SCENE TRANSITIONING
		if (currentScene->IsFinished()) { //Check if the scene is finished

			currentScene->OnExit(); //IF finished, exit the scene
			if (currentScene->GetNextScene() == "Exit") { //IF the scene wants to go to "Exit", end the game
				return 0; //End the game
			}
			currentScene = scenes[currentScene->GetNextScene()]; //Select the next scene in the map with the string
			currentScene->OnEnter(); //Start the next scene
		}

		//CONTROL TIME (FPS)
		Sleep(100); //100ms sleep, 10 FPS
	}
}