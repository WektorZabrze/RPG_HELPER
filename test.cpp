#include <iostream>
#include "Game.h"
#include "GameMaster.h"

int main(){
	Game a = Game::NewGame();
	GameMaster& gm = a.InitializeGmApi();
	a.InitializePlayer();
	a.InitializePlayer();
	a.InitializePlayer();
	gm.PerformAction();
	return 0;
}