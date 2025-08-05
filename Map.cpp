#include "Map.h"

void Map::Draw()
{
	DrawTextureV(image, position, WHITE);
	DrawRectangle(colliders[0].x, colliders[0].y, colliders[0].width, colliders[0].height, RED);
}

Map::Map()
{
	image = LoadTexture("Roblox_Rake_map.png");
	position.x = 0;
	position.y = 0;
	colCount = 1;
	SetupColls();
}

Map::~Map()
{
}

void Map::SetupColls() {
	for (int i = 0; i < colCount; i++) {
		colliders[i].x = 100;
		colliders[i].y = 100;
		colliders[i].width = 200;
		colliders[i].height = 200;
	}
}
