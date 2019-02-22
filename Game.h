#ifndef __GAME__
#define __GAME__

#include <memory>
#include <vector>
#include <string>
#include <exception>
#include "Player.h"
#include "GameMaster.h"
#include "Exceptions.h"
//#include "World.h"
#include "Token.h"

class Game{
public:
	static Game NewGame(){
		return Game();
	}

	static Game RestoreGame(Token& token){
		return Game(token);
	}

	GameMaster& InitializeGmApi(){
		//InputGmInfo
		gameMaster = std::make_shared<GameMaster>(GameMaster(players, "Dummy", "Dummy", "Dummy"));
		return *gameMaster;
	}

	// void InitializeWorld(/* parameters for world */){
	// 	world = std::make_shared(World(/* parameters */));
	// }

	void InitializePlayer(){
		//InputPlayerInfo
		players.emplace_back("Dummy", "Dummy", "Dummy");
	}

	GameMaster& GetGMApi(Token& token){
		if(token.GetToken() == gameMaster->GetToken())
			return *gameMaster;
		else
			throw NoTokenException();
	}

	Player& GetPlayerApi(Token& token){
		for(auto& player : players){
			if(player.GetToken()==token.GetToken())
				return player;
		}
		throw NoTokenException();
	}

private:
	std::vector<Player> players;
	std::shared_ptr<GameMaster> gameMaster;
	std::shared_ptr<int> world;

	Game(){
		players.reserve(10);
	}

	Game(Token& token){
		LoadFromDB(token);
	}

	void LoadFromDB(Token& token){
		//loading world, gameMaster, players from db
	}
};

#endif
