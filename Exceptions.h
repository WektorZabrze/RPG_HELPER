#ifndef __NOTOKENEXCEPTION__
#define __NOTOKENEXCEPTION__

#include <exception>
#include <string>


class BaseRpgHelperException : public std::exception{
public:
    BaseRpgHelperException(std::string err = "dummy"):err(err){}
	const char* what() const throw(){
		return err.c_str();
	}
private:
	std::string err;
};

class NoTokenException : public BaseRpgHelperException{
public:
	NoTokenException(std::string err = "No such Token in DB"):BaseRpgHelperException(err){}
};

class WrongInputException: public BaseRpgHelperException{
public:
	WrongInputException(std::string err = "Wrong input"):BaseRpgHelperException(err){}
};


#endif