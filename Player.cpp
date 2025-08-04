#include "Player.h"
#include <iostream>
#include "raymath.h"

Player::Player()
{
	image = LoadTexture("dom_idle1.png");
	position.x = ((float)(GetScreenWidth() - image.width)) / 2;
	position.y = ((float)(GetScreenHeight() - image.height)) / 2;
	speed = 3;
}

Player::~Player()
{
	UnloadTexture(image);
}

void Player::Draw()
{
	DrawTextureV(image, position, WHITE);
}

void Player::Move()
{
	Vector2 moveDir;
	if (IsKeyDown(KEY_W)) {
		moveDir.y = -1;
	}
	else if (IsKeyDown(KEY_S)) {
		moveDir.y = 1;
	}
	else {
		moveDir.y = 0;
	}



	if (IsKeyDown(KEY_A)) {
		moveDir.x = -1;
	}
	else if (IsKeyDown(KEY_D)) {
		moveDir.x = 1;
	}
	else {
		moveDir.x = 0;
	}

	//Normalize the move vector
	Vector2Normalize(moveDir);
	
	//Update position
	position.x += moveDir.x * speed;
	position.y += moveDir.y * speed;
}
