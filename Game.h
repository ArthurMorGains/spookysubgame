#pragma once
#include "Player.h"

class Game {
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
private:
	Player player;
};
