#include "Lexer.h"
void Lexer::setUp() {
	//identifies space and tab as WHITESPACE
	tokenDef[' '] = Character::WHITE_SPACE;
	tokenDef['\t'] = Character::WHITE_SPACE;

	//identifies new line
	tokenDef['\n'] = Character::NEW_LINE;

	//sets type of letters to LETTER
	for (char i = 'a'; i <= 'z'; i++) {
		tokenDef[i] = Character::LETTER;
	}

	for (int i = 0; i <= 9; i++) {
		tokenDef[i] = Character::NUMBER;
	}

	tokenDef['|'] = Character::COMMENT;

	tokenDef['\''] = Character::CHAR_QOUTE;

	tokenDef['#'] = Character::STRING_QOUTE;

	tokenDef['-'] = Character::OPERATOR;
	tokenDef['+'] = Character::OPERATOR;
	tokenDef['*'] = Character::OPERATOR;
	tokenDef['/'] = Character::OPERATOR;
	tokenDef['='] = Character::OPERATOR;

}

Lexer::Lexer(string code){
	input = code;
	setUp();
}

vector<Character*> Lexer::getCharacterTokens() {
	vector<Character*> tokenVect;

	for (int i = 0; i < input.length; i++) {
		tokenVect.push_back(new Character(input[i], tokenDef[input[i]]));
	}

	return tokenVect;
}

vector<Lexeme> Lexer::getLexemes()
{
	return vector<Lexeme>();
}



