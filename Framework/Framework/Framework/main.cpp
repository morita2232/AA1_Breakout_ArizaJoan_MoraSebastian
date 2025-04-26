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
			if (currentScene->GetNextScene() == "Exit") {
				// Liberar memoria antes de salir
				for (auto& pair : scenes) {
					delete pair.second;
				}
				return 0; // End the game
			}
			currentScene = scenes[currentScene->GetNextScene()]; //Select the next scene in the map with the string
			currentScene->OnEnter(); //Start the next scene
		}

		//CONTROL TIME (FPS)
		Sleep(100); //100ms sleep, 10 FPS
	}
}