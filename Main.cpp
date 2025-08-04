#include "raylib.h"
#include "Game.h"


int main() {
	int windowWidth = 800;
	int windowHeight = 500;

	InitWindow(windowWidth, windowHeight, "Raylib Game!");
	SetTargetFPS(60);

	Game game;

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(DARKGREEN);
		game.HandleInput();
		game.Draw();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}