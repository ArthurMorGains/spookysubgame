#pragma once
#include "Player.h"
#include "Map.h"

class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
	Camera2D cam;
	bool freeCam;
	Player player;
	Vector2 freeCamTarget;
	Vector2 freeCamMoveDir;
	float camSpeed;
private:
	Map map;
};
