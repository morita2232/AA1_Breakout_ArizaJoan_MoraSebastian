#include "RankingScene.h"

//Metodo de Lectura
void RankingScene::LoadScores() {
	fileName.open("scores.wcs", std::ios::binary | std::ios::in);
	if (fileName.is_open()) {
		size_t count = 0;
		fileName.read(reinterpret_cast<char*>(&count), sizeof(size_t));

		for (size_t i = 0; i < count; ++i) {
			size_t strSize = 0;
			fileName.read(reinterpret_cast<char*>(&strSize), sizeof(size_t));
			std::string name(strSize, ' ');
			fileName.read(&name[0], strSize);

			int score = 0;
			fileName.read(reinterpret_cast<char*>(&score), sizeof(int));

			scores.emplace_back(name, score); // esta funcion de vector la usamos ya que como trabajamos con el pair facilita el push al vector.
		}

		fileName.close();
	}
	else {
		std::cout << "No se pudo abrir el archivo para lectura.\n";
	}
}

//Metodo para Escritura
void RankingScene::SaveScores() {
	fileName.open("scores.wcs", std::ios::binary | std::ios::out | std::ios::trunc);
	if (fileName.is_open()) {
		size_t count = scores.size();
		fileName.write(reinterpret_cast<const char*>(&count), sizeof(size_t));

		for (const auto& entry : scores) {
			size_t strSize = entry.first.size();
			fileName.write(reinterpret_cast<const char*>(&strSize), sizeof(size_t));
			fileName.write(entry.first.c_str(), strSize);
			fileName.write(reinterpret_cast<const char*>(&entry.second), sizeof(int));
		}

		fileName.close();
	}
	else {
		std::cout << "No se pudo abrir el archivo para escritura.\n";
	}
}

//Metodo para ordenar el vector de Scores
void RankingScene::bubbleSort(std::vector<std::pair<std::string, int>>& v) {
	int n = v.size();

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - i - 1; j++) {

			if (v[j].second < v[j + 1].second){
				std::swap(v[j], v[j + 1]);
			}
		}
	}
}

//Metodo para Guardar Puntuacion nueva
void RankingScene::PushBackScores(std::string userName, int userPoints) {
	userScores.first = userName;
	userScores.second = userPoints;

	scores.push_back(userScores);

	bubbleSort(scores);

	SaveScores();
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
