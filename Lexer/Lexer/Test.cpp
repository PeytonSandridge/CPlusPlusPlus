#include "Lexer.h"


#include <iostream>


int main() {
	string code = "a + ";
	Lexer c = Lexer(code);

	vector<Character> tokenVect = c.getCharacterTokens();

	for (int i = 0; i < tokenVect.size(); i++) {

		std::cout << tokenVect.at(i).c << " : " << tokenVect.at(i).token << std::endl;
		
	}

	int a;
	std::cin >> a;
}