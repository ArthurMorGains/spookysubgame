#pragma once
#include "raylib.h"

class Map {
private:
	Texture2D image;
	Vector2 position;
	void SetupColls();
public:
	int colCount;
	Rectangle colliders[1];
	void Draw();
	Map();
	~Map();
};