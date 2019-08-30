#include "Lexer.h"
void Lexer::setUp() {
	//identifies space and tab as WHITESPACE
	tokens[' '] = Lexeme::WHITE_SPACE;
	tokens['\t'] = Lexeme::WHITE_SPACE;

	//identifies new line
	tokens['\n'] = Lexeme::NEW_LINE;

	//sets type of letters to LETTER
	for (char i = 'a'; i <= 'z'; i++) {
		tokens[i] = Lexeme::LETTER;
	}

	for (int i = 0; i <= 9; i++) {
		tokens[i] = Lexeme::NUMBER;
	}

	tokens['|'] = Lexeme::COMMENT;

	tokens['\''] = Lexeme::CHAR_QOUTE;

	tokens['#'] = Lexeme::STRING_QOUTE;

	tokens['-'] = Lexeme::OPERATOR;
	tokens['+'] = Lexeme::OPERATOR;
	tokens['*'] = Lexeme::OPERATOR;
	tokens['/'] = Lexeme::OPERATOR;
	tokens['='] = Lexeme::OPERATOR;

}

Lexer::Lexer(string code){
	input = code;
	setUp();
}


