#include "GameplayScene.h"

void GameplayScene::OnEnter()
{
	//Reseteo de variables por partida nueva
	gameManager.life = 3;
	gameManager.score = 0;
	gameManager.combo = 0;
	gameManager.brickCounter = 0;

	//Wall generation
	for (int i = 0; i < MAP_SIZE; i++) {
		Wall* topWall = new Wall(Vector2(i, 0), YELLOW, false);
		Wall* bottomWall = new Wall(Vector2(i, MAP_SIZE - 1), YELLOW, true);
		if (i > 0 && i < MAP_SIZE - 1) {
			Wall* leftSideWall = new Wall(Vector2(0, i), YELLOW, false);
			Wall* rightSideWall = new Wall(Vector2(MAP_SIZE - 1, i), YELLOW, false);
			objects.push_back(leftSideWall);
			objects.push_back(rightSideWall);
		}
		objects.push_back(topWall);
		objects.push_back(bottomWall);
	}

	//Bricks
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j < MAP_SIZE - 1; j++) {
			objects.push_back(new Brick(Vector2(j, i), CYAN));
		}
	}

	//PAD
	objects.push_back(new Pad(Vector2(MAP_SIZE / 2, (MAP_SIZE * 3) / 4), WHITE, 1, MAP_SIZE));
	
	//BALL
	objects.push_back(new Ball(Vector2(2, MAP_SIZE / 2), WHITE, objects, gameManager));
}

void GameplayScene::Update()
{
	Scene::Update();

	//condicion de victoria y derrota para guardar nombre de usuario y puntuacion
	if (gameManager.life <= 0 || gameManager.brickCounter >= 39) {
		

		if (scenes["GameOver"])
			delete scenes["GameOver"];

		scenes["GameOver"] = new GameOverScene(rankingScene, "", gameManager.score, gameManager);


		finished = true;
		nextScene = "GameOver";
	}


}

void GameplayScene::Render()
{
	Scene::Render();

}

void GameplayScene::OnExit()
{
	for (GameObject* o : objects)
		delete o;

	objects.clear();
}
