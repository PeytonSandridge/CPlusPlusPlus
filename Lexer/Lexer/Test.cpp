#include "Lexer.h"


#include <iostream>


int main() {
	string code = "alphabet because 9098.2321f 23.213 213kjhkj";
	Lexer c = Lexer(code);

	vector<Character> tokenVect = c.getCharacterTokens();
	for (int i = 0; i < tokenVect.size(); i++) {

		std::cout << tokenVect.at(i).c << " : " << tokenVect.at(i).token << std::endl;

	}
	vector<Lexeme> lexVect = c.getLexemes();
	for (int i = 0; i < tokenVect.size(); i++) {

		std::cout << lexVect.at(i).data << " : " << lexVect.at(i).cat << std::endl;
		
	}

	int a;
	std::cin >> a;
}