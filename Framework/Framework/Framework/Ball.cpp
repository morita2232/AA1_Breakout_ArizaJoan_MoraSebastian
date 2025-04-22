/*
#include "Ball.h"

Vector2 Ball::CalculateCollision(GameObject* other)
{
	int vertical = 0;
	int horizontal = 0;

	for (int i = 0; i < objects.size(); i++) {
		bool top = (other->GetPosition() + Vector2(-1, 0)) == objects[i]->GetPosition();
		bool bottom = (other->GetPosition() + Vector2(1, 0)) == objects[i]->GetPosition();
		vertical += (int)top + (int)bottom;

		bool left = (other->GetPosition() + Vector2(0, -1)) == objects[i]->GetPosition();
		bool right = (other->GetPosition() + Vector2(0, 1)) == objects[i]->GetPosition();
		horizontal += (int)left + (int)right;
	}

	Vector2 outDir = direction;

	if (vertical == 0 && horizontal == 0) {
		vertical = rand() % 2 > 0;
		horizontal = rand() % 2 > 0;
	}
if (Pad* p = dynamic_cast<Pad*>(other)) {
	for (int i = 1; i <= p->GetWidth(); i++) {
		if (position == p->GetPosition() + Vector2(i, 0)) {
			direction.x = 1; direction.y = -1; // derecha
			return direction;
		}
		if (position == p->GetPosition() + Vector2(-i, 0)) {
			direction.x = -1; direction.y = -1; // izquierda
			return direction;
		}
	}
	// centro
	direction.y = -1;
	direction.x = 0;
	return direction;
}


	if (vertical > horizontal) {
		outDir.y = -outDir.y;
	}
	else if (horizontal > vertical) {
		outDir.x = -outDir.x;
	}
	else {
		outDir.y = -outDir.y;
		outDir.x = -outDir.x;
	}

	return outDir;
}


void Ball::Update()
{
	position = position + direction;

	for (GameObject* go : objects) {
		if (go == this) continue;

		bool collision = false;

		if (Pad* p = dynamic_cast<Pad*>(go)) {
			for (Vector2 padPos : p->GetPositions()) {
				if (position == padPos) {
					collision = true;
					break;
				}
			}
		}
		else {
			collision = (position == go->GetPosition());
		}


		if (collision) {
			if (Wall* w = dynamic_cast<Wall*>(go)) {
				direction = CalculateCollision(go);
			}
			if (Brick* b = dynamic_cast<Brick*>(go)) {
				direction = CalculateCollision(go);
				b->Destroy();
			}
			if (Pad* p = dynamic_cast<Pad*>(go)) {
				direction = CalculateCollision(go);
			}
		}
	}
}
*/

/*
#include "Ball.h"
#include <cstdlib> 

Vector2 Ball::CalculateCollision(GameObject* other)
{
	int vertical = 0;   
	int horizontal = 0; 

	for (int i = 0; i < objects.size(); i++) {
		Vector2 otherPos = other->GetPosition();
		Vector2 objPos = objects[i]->GetPosition();

		
		bool top = (otherPos + Vector2(-1, 0)) == objPos;
		bool bottom = (otherPos + Vector2(1, 0)) == objPos;
		vertical += (int)top + (int)bottom;

		
		bool left = (otherPos + Vector2(0, -1)) == objPos;
		bool right = (otherPos + Vector2(0, 1)) == objPos;
		horizontal += (int)left + (int)right;



	}

	Vector2 outDir = direction;

	
	if (vertical == 0 && horizontal == 0) {
		vertical = rand() % 2;
		horizontal = rand() % 2;
	}

	
	if (vertical > horizontal) {
		outDir.y = -outDir.y;
	}
	else if (horizontal > vertical) {
		outDir.x = -outDir.x;
	}
	else {
		outDir.x = -outDir.x;
		outDir.y = -outDir.y;
	}

	return outDir;
}

void Ball::Update()
{
	Vector2 nextPos = position + direction;

	for (GameObject* go : objects) {
		if (go == this) continue;

		
		if (Brick* b = dynamic_cast<Brick*>(go)) {
			if (b->GetDestroyed()) continue;
		}

		if (nextPos == go->GetPosition()) {
			if (Wall* w = dynamic_cast<Wall*>(go)) {
				direction = CalculateCollision(go);
			}

			if (Brick* b = dynamic_cast<Brick*>(go)) {
				direction = CalculateCollision(go);
				b->Destroy();
			}
			if (Pad* p = dynamic_cast<Pad*>(go)) {
				Vector2 padPos = p->GetPosition();
				int padWidth = p->GetWidth();

				for (int i = -padWidth; i <= padWidth; i++) {
					Vector2 partPos = padPos + Vector2(i, 0);
					if (nextPos == partPos) {
						direction.y = -direction.y;

						if (i < 0) direction.x = -1; // Rebote hacia la izquierda
						if (i > 0) direction.x = 1;  // Rebote hacia la derecha

						break;
					}

				}
			}



			break;
		}
	}

	position = position + direction;
}
*/

#include "Ball.h"
#include <cstdlib>

Vector2 Ball::CalculateCollision(GameObject* other)
{
	int vertical = 0;
	int horizontal = 0;

	for (int i = 0; i < objects.size(); i++) {
		Vector2 otherPos = other->GetPosition();
		Vector2 objPos = objects[i]->GetPosition();

		bool top = (otherPos + Vector2(-1, 0)) == objPos;
		bool bottom = (otherPos + Vector2(1, 0)) == objPos;
		vertical += (int)top + (int)bottom;

		bool left = (otherPos + Vector2(0, -1)) == objPos;
		bool right = (otherPos + Vector2(0, 1)) == objPos;
		horizontal += (int)left + (int)right;
	}

	Vector2 outDir = direction;

	if (vertical == 0 && horizontal == 0) {
		vertical = rand() % 2;
		horizontal = rand() % 2;
	}

	if (Pad* p = dynamic_cast<Pad*>(other)) {
		for (int i = 1; i <= p->GetWidth(); i++) {
			if (position == p->GetPosition() + Vector2(i, 0)) {
				direction.x = 1;
				direction.y = -1;
				return direction;
			}
			if (position == p->GetPosition() + Vector2(-i, 0)) {
				direction.x = -1;
				direction.y = -1;
				return direction;
			}
		}
		direction.y = -1;
		direction.x = 0;
		return direction;
	}

	if (vertical > horizontal) {
		outDir.y = -outDir.y;
	}
	else if (horizontal > vertical) {
		outDir.x = -outDir.x;
	}
	else {
		outDir.x = -outDir.x;
		outDir.y = -outDir.y;
	}

	return outDir;
}

void Ball::Update()
{
	Vector2 nextPos = position + direction;

	for (GameObject* go : objects) {
		if (go == this) continue;

		if (Brick* b = dynamic_cast<Brick*>(go)) {
			if (b->GetDestroyed()) continue;
		}

		// Colisión con la pala
		if (Pad* p = dynamic_cast<Pad*>(go)) {
			Vector2 padPos = p->GetPosition();
			int padWidth = p->GetWidth();

			for (int i = -padWidth; i <= padWidth; i++) {
				Vector2 partPos = padPos + Vector2(i, 0);
				if (nextPos == partPos) {
					direction.y = -direction.y;

					if (i < 0) direction.x = -1;
					else if (i > 0) direction.x = 1;
					else direction.x = 0;

					position = position + direction;
					return;
				}
			}
		}

		// Colisión con cualquier otro objeto
		if (nextPos == go->GetPosition()) {
			if (Wall* w = dynamic_cast<Wall*>(go)) {
				direction = CalculateCollision(go);
			}
			if (Brick* b = dynamic_cast<Brick*>(go)) {
				direction = CalculateCollision(go);
				b->Destroy();
			}
			break;
		}
	}

	position = position + direction;
}

