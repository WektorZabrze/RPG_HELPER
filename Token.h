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
		char token[21];
		srand(time(NULL));
		unsigned len = base.length()-1;
		
		for(char& pos : token){
			pos = base[rand()%len];
		}
		token[20]='\0';

		value = token;
	}

	std::string GetToken() const {return value;}
private:
	std::string value;
};

#endif