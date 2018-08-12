#ifndef __NOTOKENEXCEPTION__
#define __NOTOKENEXCEPTION__

#include <exception>

class NoTokenException : public exception{
	const char* what() const throw(){
		return "Token not found in DB!";
	}
};

#endif