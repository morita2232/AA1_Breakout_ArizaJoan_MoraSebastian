#pragma once
#include "Scene.h"
#include <map>
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"
#include "GameManager.h"
#include "GameOverScene.h"
#include "RankingScene.h"

#define MAP_SIZE 15

class GameplayScene : public Scene {
protected:
	GameManager& gameManager;
	std::map<std::string, Scene*>& scenes;
	RankingScene* rankingScene;
public:

	GameplayScene(GameManager& _gameManager, std::map<std::string, Scene*>& _scenes, RankingScene* _rankingScene)
		: gameManager(_gameManager), scenes(_scenes), rankingScene(_rankingScene) {}

	void OnEnter() override;
	void Update() override;
	void Render() override;
	void OnExit() override;
};

