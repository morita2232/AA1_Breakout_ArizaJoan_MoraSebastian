#pragma once
#include "GameObject.h"
#include <Windows.h>
#include <vector>

class Pad : public GameObject {
protected:
	int width;
	int mapSize;
public:
	Pad(Vector2 _pos, ConsoleColor c, int w, int _mapSize)
		:GameObject(_pos, '_', c), width(w), mapSize(_mapSize) {}

	//Controlador de longitud del pad
	int GetWidth() { return width; }

	//Controlador de posiciones del pad (izquerda - derecha)
	std::vector<Vector2> GetPositions() {
		std::vector<Vector2> positions;
		positions.push_back(position); // centro

		for (int i = 1; i <= width; i++) {
			positions.push_back(position + Vector2(i, 0));   // derecha
			positions.push_back(position + Vector2(-i, 0));  // izquierda
		}
		return positions;
	}


	void Update() override;
	void Render() override;
};
