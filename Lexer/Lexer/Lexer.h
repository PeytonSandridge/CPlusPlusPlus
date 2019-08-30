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
private:
	string input;
	void setUp();

	unordered_map<char, Lexeme::Token> tokens;
};




