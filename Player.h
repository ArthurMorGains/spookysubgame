#pragma once
#include "raylib.h"

class Player {
public:
	float speed;
	Player();
	~Player();
	void Move();
	void Draw();
	Rectangle CheckCollisionPlayerToRect(Rectangle rectangle);
	Vector2 collisionSide;
	Vector2 position;
	Vector2 centerOffset;
	bool isFreeCam;
	bool showHitboxes;
private:
	int gravity;
	bool isColliding;
	Texture2D idle1;
	Texture2D idle1f;
	Rectangle hitBox;
	Vector2 hitCenter;
};
