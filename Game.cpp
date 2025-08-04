#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Draw()
{
	player.Draw();
}

void Game::Update()
{
}

void Game::HandleInput()
{
	player.Move();
}
