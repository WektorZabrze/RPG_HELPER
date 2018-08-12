#ifndef __TOKEN__
#define __TOKEN__

#include <string>
#include <random>
#include <ctime>

class Token{
public:
	Token(){
		GenerateToken();
	}

	void GenerateToken(std::string base = "abcdefghijklmnopqrtsuwxyzABCDEFGHIJKLMNOPQRSTUWXYZ1234567890"){

		char token[20];
		srand(time(NULL));
		uint len = base.length();
		
		for(char& pos : token){
			pos = base[random()%len];
		}

		value = token;
	}

	std::string GetToken() const {return value;}
private:
	std::string value;
};

#endif