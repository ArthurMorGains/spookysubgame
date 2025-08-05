#include "raylib.h"
#include "raymath.h"

#include "Game.h"


int main() {
	int windowWidth = 1000;
	int windowHeight = 750;

	InitWindow(windowWidth, windowHeight, "SpookySubGame");
	SetTargetFPS(144);

	Game game;

	while (!WindowShouldClose()) {
		game.Update();
		BeginDrawing();
		BeginMode2D(game.cam);
		ClearBackground(DARKGREEN);
		game.HandleInput();
		game.Draw();
		EndMode2D();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
