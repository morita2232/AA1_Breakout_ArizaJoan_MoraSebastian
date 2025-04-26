#pragma once
#include "Scene.h"
#include <fstream>

class RankingScene : public Scene {
protected:
	//Vector of pairs-> 1st is a string a 2nd is the score
	//If you don't undestand std::pair<>, you can use another approach
	std::vector<std::pair<std::string, int>> scores;
	std::pair<std::string, int> userScores;
	std::fstream fileName;
	void bubbleSort(std::vector<std::pair<std::string, int>>& v);

public:
	//SETTER
	void PushBackScores(std::string userName, int userPoints);
	
	void LoadScores();
	void SaveScores();

	RankingScene() {
		nextScene = "Menu";
		LoadScores();
	}


	~RankingScene() {
		SaveScores();
	}
	void Update() override;
	void Render() override;
};