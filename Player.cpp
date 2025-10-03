#include "Player.h"
#include "raymath.h"
#include "Map.h"
#include <iostream>

Player::Player()
{
	idle1 = LoadTexture("temp.png");
	idle1f = LoadTexture("tempf.png");
	position.x = ((float)(GetScreenWidth() - idle1.width)) / 2;
	position.y = ((float)(GetScreenHeight() - idle1.height)) / 2;
	speed = 175;
	hitBox.x = position.x;
	hitBox.y = position.y;
	hitBox.height = (float)idle1.height;
	hitBox.width = (float)idle1.width;

	hitCenter.x = hitBox.x + (hitBox.width / 2);
	hitCenter.y = hitBox.y + (hitBox.height / 2);

	collisionSide.x = 0;
	collisionSide.y = 0;

	centerOffset.x = (hitBox.width / 2);
	centerOffset.y = (hitBox.height / 2);

	isColliding = false;

	gravity = -10;

	isFreeCam = false;
	showHitboxes = false;
}

Player::~Player()
{
	UnloadTexture(idle1);
	UnloadTexture(idle1f);
}

void Player::Draw()
{						//The center of the sprite
	if (GetMouseX() < (GetScreenWidth()/2.0f) && !isFreeCam) {
		DrawTextureV(idle1f, position, WHITE);
	}
	else {
		DrawTextureV(idle1, position, WHITE);
	}
	if (showHitboxes) {
		DrawCircle(int(hitCenter.x), int(hitCenter.y), int(hitBox.width) / 2.0f, BLUE);
	}
}

Rectangle Player::CheckCollisionPlayerToRect(Rectangle rectangle)
{	
	Rectangle colRec = GetCollisionRec(hitBox, rectangle);

	Vector2 directionToP;

	directionToP.x = hitCenter.x - (colRec.x + (colRec.width / 2));
	directionToP.y = hitCenter.y - (colRec.y + (colRec.height / 2));

	Vector2Normalize(directionToP);



	if (colRec.x == 0 && colRec.y == 0) {
		collisionSide.x = 0;
		collisionSide.y = 0;
	}
	else if (abs(directionToP.x) > abs(directionToP.y) && directionToP.x > 0 && colRec.x != 0) {
		collisionSide.x = -1;
		collisionSide.y = 0;
	}
	else if (abs(directionToP.x) > abs(directionToP.y) && directionToP.x < 0 && colRec.x != 0) {
		collisionSide.x = 1;
		collisionSide.y = 0;
	}
	else if (abs(directionToP.x) < abs(directionToP.y) && directionToP.y > 0 && colRec.x != 0) {
		collisionSide.x = 0;
		collisionSide.y = 1;
	}
	else if (abs(directionToP.x) < abs(directionToP.y) && directionToP.y < 0 && colRec.x != 0) {
		collisionSide.x = 0;
		collisionSide.y = -1;
	}
	else {
		collisionSide.x = 0;
		collisionSide.y = 0;
	}

	








	return colRec;
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

	if (IsKeyDown(KEY_LEFT_SHIFT)) {
		speed = 300;
	}
	else {
		speed = 175;
	}

	//Normalize the move vector
	Vector2Normalize(moveDir);
	
	float deltaTime = GetFrameTime();

	if (collisionSide.x != moveDir.x) {
		position.x += moveDir.x * speed * deltaTime;
	}
	if (collisionSide.y * -1.0f != moveDir.y) {
		position.y += moveDir.y * speed * deltaTime;
	}

	hitBox.x = position.x;
	hitBox.y = position.y;

	hitCenter.x = hitBox.x + (hitBox.width / 2);
	hitCenter.y = hitBox.y + (hitBox.height / 2);
}
 
