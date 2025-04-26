#pragma once
#include "Scene.h"
#include <string>
#include "RankingScene.h"
#include "GameManager.h"
#include <iostream>
#include <vector>
#include <algorithm>

class GameOverScene : public Scene {
protected:
	int userScore;
	std::string userName;
	RankingScene* ranking;
	bool askedName = false;


public:

	GameManager& gameManager;

	//constructor
	GameOverScene(RankingScene* rankingScene, std::string name, int score, GameManager& _gameManager)
		: ranking(rankingScene), userName(name), userScore(score), gameManager(_gameManager), askedName(false) {

		nextScene = "Menu";
	}
	//destructor
	~GameOverScene() = default; //Destructor TODO -> save scores
	
	void Update() override;
	void Render() override;
};