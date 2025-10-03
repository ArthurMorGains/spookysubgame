#include "Game.h"
#include "raymath.h"
#include <iostream>

Game::Game()
{
	freeCamMoveDir.x = 0;
	freeCamMoveDir.y = 0;
	camSpeed = 175;
	cam.zoom = 1.0f;
	cam.target = Vector2Add(player.position, player.centerOffset);
	freeCamTarget = player.position;
	cam.rotation = 0.0f;
	Vector2 camOffset{};
	camOffset.x = GetScreenWidth() / 2.0f;
	camOffset.y = GetScreenHeight() / 2.0f;
	cam.offset = camOffset;
	freeCam = false;
	player.isFreeCam = false;
}

Game::~Game()
{
}

void Game::Draw()
{
	map.Draw();
	player.Draw();
}

void Game::Update()
{
	if (!freeCam) {
		cam.target = Vector2Add(player.position, player.centerOffset);
	}
}

void Game::HandleInput()
{
	for (int i = 0; i < map.colCount; i++) {
		Rectangle colRect = player.CheckCollisionPlayerToRect(map.colliders[i]);
		std::cout << player.collisionSide.x << ", " << player.collisionSide.y << std::endl;
	}
	if (!freeCam) {
		player.Move();
	}
	else {
		if (IsKeyDown(KEY_W)) {
			freeCamMoveDir.y = -1;
		}
		else if (IsKeyDown(KEY_S)) {
			freeCamMoveDir.y = 1;
		}
		else {
			freeCamMoveDir.y = 0;
		}
		if (IsKeyDown(KEY_A)) {
			freeCamMoveDir.x = -1;
		}
		else if (IsKeyDown(KEY_D)) {
			freeCamMoveDir.x = 1;
		}
		else {
			freeCamMoveDir.x = 0;
		}
		if (IsKeyDown(KEY_LEFT_SHIFT)) {
			camSpeed = 300;
		}
		else {
			camSpeed = 175;
		}
		Vector2Normalize(freeCamMoveDir);
		float deltaTime = GetFrameTime();
		if (freeCamMoveDir.x > 0.1) {
			cam.target.x += freeCamMoveDir.x * camSpeed * deltaTime;
		}
		if (freeCamMoveDir.x < -0.1) {
			cam.target.x += freeCamMoveDir.x * camSpeed * deltaTime;
		}
		if (freeCamMoveDir.y < -0.1) {
			cam.target.y += freeCamMoveDir.y * camSpeed * deltaTime;
		}
		if (freeCamMoveDir.y > 0.1) {
			cam.target.y += freeCamMoveDir.y * camSpeed * deltaTime;
		}
	}

	if (IsKeyPressed(KEY_F)) {
		switch (freeCam) {
		case true: freeCam = false; player.isFreeCam = false; break;
		case false: freeCam = true; player.isFreeCam = true;  break;
		}
	}
}
