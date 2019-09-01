#pragma once

#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

//this also includes strings
#include "Token.h"
//using std::Token;




class Lexer {
public:
	Lexer(string code);
	Lexer();
	vector<Character> getCharacterTokens();
	vector<Lexeme> getLexemes();
	string input;
private:

	void setUp();

	unordered_map<char, Character::Tokens> tokenDef;
	unordered_map<string, Lexeme::Token> lexemeDef;
};




