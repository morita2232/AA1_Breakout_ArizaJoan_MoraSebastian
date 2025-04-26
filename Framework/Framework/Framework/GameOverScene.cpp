#include "GameOverScene.h"
#include <iostream>
#include <bits/stdc++.h>
// GameOverScene.cpp
void GameOverScene::Update() {
	system("cls");
	if (!askedName) {
		std::cout << "Introduce tu nombre de jugador: ";
		std::cin >> userName;
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		userScore = gameManager.score;

		if (ranking)
			ranking->PushBackScores(userName, userScore);

		// C++ program for the implementation of Bubble sort

		using namespace std;

		void bubbleSort(vector<int>&v) {
			int n = v.size();

			// Outer loop that corresponds to the number of
			// elements to be sorted
			for (int i = 0; i < n - 1; i++) {

				// Last i elements are already
				// in place
				for (int j = 0; j < n - i - 1; j++) {

					// Comparing adjacent elements
					if (v[j] > v[j + 1])

						// Swapping if in the wrong order
						swap(v[j], v[j + 1]);
				}
			}
		}
		
		askedName = true;


	}
	else {
		// Esperar a que el jugador presione una tecla para continuar
		if (GetAsyncKeyState('R') != 0) {
			finished = true;
		}
	}
}

void GameOverScene::Render() {
	if (!askedName) {
		std::cout << "==== GAME OVER ====\n";
		std::cout << "Introduce tu nombre para guardar la puntuación.\n";
	}
	else {
		std::cout << "Gracias " << userName << ". Tu puntuación ha sido guardada.\n";
		std::cout << "Press R to go back to the menu;";
	}
	
}