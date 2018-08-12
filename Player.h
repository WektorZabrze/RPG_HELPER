#ifndef __PLAYER__
#define __PLAYER__

#include "User.h"
#include <memory>

class Player : public User{
public:
	Player(std::string nick, std::string sex, std::string country):User(nick, sex, country){}

	std::string Describe(bool debug = false) const override{
		std::string description = "Player description \nNick: " + nick + "\nSex: " + sex + "\nCountry: " + country + "\n***CHARACTER DESCRIPTION TBD***";
		if(debug)description+="\nToken: "+token.GetToken();
		return description;
	}

	void DumpToDB() const override{
		/* dump player to db */
	}

	void LoadFromDB() override{
		/* load fields from db */
	}

	void SetCharacter(void* character){
		/*set ptr to character*/
	}

private:
	std::shared_ptr<void> character;
	/*referencja do klasy postaci*/ 
};

#endif