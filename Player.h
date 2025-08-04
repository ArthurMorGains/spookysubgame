#pragma once
#include "raylib.h"

class Player {
public:
	float speed;
	Player();
	~Player();
	void Draw();
	void Move();
private:
	Texture2D image;
	Vector2 position;
};
