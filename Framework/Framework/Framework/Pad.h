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

	int GetWidth() { return width; }

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
