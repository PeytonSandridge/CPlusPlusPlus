#pragma once
#include <string>
using std::string;

//enumerators for different types of characters


class Lexeme {

public:
	enum Token
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

	string data;
	Token cat;

};