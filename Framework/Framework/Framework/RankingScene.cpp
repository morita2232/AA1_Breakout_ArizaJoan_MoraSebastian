#include "RankingScene.h"

void RankingScene::PushBackScores(std::string userName, int userPoints) {

	userScores.first = userName;
	userScores.second = userPoints;

	scores.push_back(userScores);

}

void RankingScene::Update()
{

	if (GetAsyncKeyState('R') != 0) {
		finished = true;
	}
}

void RankingScene::Render()
{

	for (int i = 0; i < scores.size(); i++) {
		std::cout << scores[i].first << " - " << scores[i].second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Press R to go back to the menu";
}
