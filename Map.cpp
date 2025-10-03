#include "Map.h"

void Map::Draw()
{
	DrawTextureV(image, position, WHITE);
	for (int i = 0; i < colCount; i++) {
		DrawRectangle(colliders[i].x, colliders[i].y, colliders[i].width, colliders[i].height, RED);
		if (showHitboxes) {
			DrawCircle(colliders[i].x + (colliders[i].width / 2), colliders[i].y + colliders[i].height / 2, colliders[i].width / 2, BLUE);
		}
	}
	
}

Map::Map()
{
	image = LoadTexture("Roblox_Rake_map.png");
	position.x = 0;
	position.y = 0;
	colCount = 1;
	SetupColls();
	showHitboxes = false;
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
