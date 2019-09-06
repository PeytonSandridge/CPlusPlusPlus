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
	inline Lexer(string code);
	Lexer();
	inline vector<Character> getCharacterTokens();
	inline vector<string> getWords();
	inline vector<Lexeme> getLexemes();
	string input;
private:

	void setUp();

	unordered_map<char, Character::Tokens> tokenDef;
	unordered_map<string, Lexeme::Token> lexemeDef;
};




