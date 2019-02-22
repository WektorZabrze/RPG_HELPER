#ifndef __GAMEMASTER__
#define __GAMEMASTER__

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <locale> 
#include "Exceptions.h"
#include "User.h"
#include "Player.h"

class GameMaster: public User{
public:
	GameMaster(std::vector<Player>& players, const std::string& nick, const std::string& sex, const std::string& country):User(nick, sex, country), players(players){}

	std::string Describe(bool debug = false) const override{
		std::string description = "GameMaster description \nNick: " + nick + "\nSex: " + sex + "\nCountry: " + country;
		if(debug)description+="\nToken: "+token.GetToken();
		return description;
	}

	void PerformAction(){
		std::shared_ptr<Action> to_perform = std::make_shared<Action>(Action::DescribeAction("Orc attack you!"));
		for(int item: ChoosePlayers()){
			players[item].AssignAction(to_perform);
		}
		return;
	}

	void DumpToDB() const override{
		/* dump player to db */
	}

	void LoadFromDB() override{
		/* load fields from db */
	}

private:
	std::vector<int> ChoosePlayers(){
		PrintAllPlayers();
		try{
			std::vector<int> ids = ParseInput();
			return ids;
		}catch(BaseRpgHelperException& e){
			std::cout<<e.what()<<std::endl;
			return ChoosePlayers();
		}
	}

	void PrintAllPlayers(){
		for(uint8_t i = 1 ; i <= players.size(); ++i){
			std::cout<<i<<". | "<<players[i-1].LineInfo()<<std::endl;
		}
		std::cout<<"Insert space separated numbers to choose players"<<std::endl;
	}

	std::vector<int> ParseInput(){
		std::string input;
		std::getline(std::cin,input);
		std::istringstream iss(input);
		std::vector<int> result;
		int item;

		ValidateInput(input);
		while(iss>>item){
			result.push_back(item-1);
		}
		ValidateResults(result);
		return result;
	}

	void ValidateInput(std::string input){
		if(input.empty())
			throw WrongInputException("Empty input");
		for(char item: input){
			if(!(std::isdigit(item) or item == ' '))
				throw WrongInputException("Only numbers and spaces allowed!");
		}
		return;
	}

	void ValidateResults(std::vector<int>& results){
		for(auto item:results){
			if(item>=players.size())
				throw WrongInputException("Player id too high ("+std::to_string(item+1)+")");
			else if(item<0)
				throw WrongInputException("Player id must be higher than 0");
		}
		return;
	}

	std::vector<Player>& players;
};

#endif