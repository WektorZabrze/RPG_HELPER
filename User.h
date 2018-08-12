#ifndef __USER__
#define __USER__

#include <string>
#include <iostream>
#include "Token.h"

class User{
public:
	User(){}
	User(std::string& nick, std::string& sex, std::string& country):nick(nick), sex(sex), country(country){}
	virtual std::string Describe(bool debug = false) const = 0;
	virtual void DumpToDB() const = 0;
	virtual void LoadFromDB(/* przekazane dane z DB przez TokenHandlera*/) = 0;
protected:
	std::string nick;
	std::string sex; //enum? (validation, etc.)
	std::string country;
	Token token;
};

#endif