#include <iostream>
#include "Player.h"
#include "GameMaster.h"

int main(){
	Player a("Loniowsky", "Man","Poland");
	GameMaster b("Test", "Test", "Test");
	std::cout<<a.Describe(true)<<std::endl;
	std::cout<<b.Describe(true)<<std::endl;
}