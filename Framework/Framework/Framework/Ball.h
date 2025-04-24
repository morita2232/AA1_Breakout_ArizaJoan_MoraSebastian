#pragma once
#include "GameObject.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "GameManager.h"

#include <vector>

class Ball : public GameObject {
protected:
	Vector2 direction;
	std::vector<GameObject*>& objects;
	Vector2 CalculateCollision(GameObject* other);


public:

	GameManager& gameManager;

	Ball(Vector2 _pos, ConsoleColor c, std::vector<GameObject*>& _objects, GameManager& _gameManager)
		: GameObject(_pos, '@', c), objects(_objects), direction(Vector2(1, 1)), gameManager(_gameManager) {}

	void Update() override;

	void Muerte();
};
