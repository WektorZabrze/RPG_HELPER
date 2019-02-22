#ifndef __TOKENHANDLER__
#define __TOKENHANDLER__

#include <string>
#include "Token.h"
#include "Exceptions.h"

class TokenHandler{
public:
    static /*obiekt bazy danych*/bool SearchForTokenAndGet(Token& input_token){
        if(ValidateToken(input_token)){
            //tutaj wyszukiwanie tokenu z bazy danych
            // return obiekt z bazy danych z odpowiednim tokenem
            return true;
        }
        throw NoTokenException();
    }

    static bool ValidateToken(Token& input_token){
        return true;
        /*spr czy zapytanie do DB zwraca jakikolwiek wynik*/
    }
};

#endif