#ifndef __GAMEMASTER__
#define __GAMEMASTER__

#include "User.h"

class GameMaster: public User{
public:
	GameMaster(std::string nick, std::string sex, std::string country):User(nick, sex, country){}

	std::string Describe(bool debug = false) const override{
		std::string description = "GameMaster description \nNick: " + nick + "\nSex: " + sex + "\nCountry: " + country;
		if(debug)description+="\nToken: "+token.GetToken();
		return description;
	}

	void DumpToDB() const override{
		/* dump player to db */
	}

	void LoadFromDB() override{
		/* load fields from db */
	}
};

#endif