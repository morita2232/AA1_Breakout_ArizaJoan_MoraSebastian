#pragma once

class GameManager {
public:
	//variable que controla la puntuacion total de la partida
	int score = 0;
	//Variable que controla la cantidad de veces que destruyes un brick consecutivamente antes de chocar contra la pala
	int combo = 0;

	//variable que controla la cantida de bricks restantes
	int brickCounter = 0;

	//variablke que controla la cantidad de vidas restantes
	short life;


};
