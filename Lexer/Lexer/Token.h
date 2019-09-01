#pragma once
#include <string>
using std::string;

//enumerators for different types of characters


class Character {

public:
	enum Tokens
	{
		WHITE_SPACE,
		NEW_LINE,
		LETTER,
		NUMBER,
		OPERATOR,
		COMMENT,
		CHAR_QOUTE,
		STRING_QOUTE
	};

	Tokens token;
	char c;
	Character(char ch, Tokens t) {
		token = t;
		c = ch;
	}
};

class Lexeme {
public:
	enum Token
	{
		//name of a var
		IDENTIFIER,
		//name of a reserved word (if, for, return, etc)
		KEYWORD,
		//{, (, ;,
		SEPARATOR,
		//+ = <
		OPERATOR,
		// this
		COMMENT,
		//true, 7.23f, "word"
		LITERAL
	};
	string data;
	Token cat;
	Lexeme(string iData, Token iCat) {
		data = iData;
		cat = iCat;
	}
};