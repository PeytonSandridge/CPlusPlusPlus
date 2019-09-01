#include "Lexer.h"
void Lexer::setUp() {
	//identifies space and tab as WHITESPACE
	tokenDef[' '] = Character::WHITE_SPACE;
	tokenDef['\t'] = Character::WHITE_SPACE;

	//identifies new line
	//tokenDef['\n'] = Character::NEW_LINE;

	//sets type of letters to LETTER
	for (char i = 'a'; i <= 'z'; i++) {
		tokenDef[i] = Character::LETTER;
	}

	for (int i = 0; i <= 9; i++) {
		tokenDef[i] = Character::NUMBER;
	}

	//tokenDef['|'] = Character::COMMENT;

	//tokenDef['\''] = Character::CHAR_QOUTE;

	//tokenDef['#'] = Character::STRING_QOUTE;

	tokenDef['-'] = Character::OPERATOR;
	tokenDef['+'] = Character::OPERATOR;
	tokenDef['*'] = Character::OPERATOR;
	tokenDef['/'] = Character::OPERATOR;
	tokenDef['='] = Character::OPERATOR;



	/**
	* Sets up definitions for lexemes
	*	
	**/
	lexemeDef["+"] = Lexeme::OPERATOR;
	lexemeDef["-"] = Lexeme::OPERATOR;
	lexemeDef["="] = Lexeme::OPERATOR;
	lexemeDef["<"] = Lexeme::OPERATOR;
	lexemeDef[">"] = Lexeme::OPERATOR;
	lexemeDef["*"] = Lexeme::OPERATOR;
	lexemeDef["/"] = Lexeme::OPERATOR;

//	lexemeDef["//"] = Lexeme::COMMENT;
	
	lexemeDef["{"] = Lexeme::SEPARATOR;
	lexemeDef["("] = Lexeme::SEPARATOR;
	lexemeDef[";"] = Lexeme::SEPARATOR;

	lexemeDef["if"] = Lexeme::KEYWORD;
}

Lexer::Lexer(string code){
	input = code;
	setUp();
}

Lexer::Lexer() {
	input = "";
	setUp();
}

vector<Character> Lexer::getCharacterTokens() {
	vector<Character> tokenVect;

	for (int i = 0; i < input.size(); i++) {
		tokenVect.push_back(Character(input[i], tokenDef[input[i]]));
	}

	return tokenVect;
}

vector<Lexeme> Lexer::getLexemes() {
	vector<Lexeme> lexemes;
	vector<Character> characters = getCharacterTokens();

	string str = "";
	vector<string> words;
	do {
		Character currChar = characters.at(characters.begin);
		

		
		if (currChar.token != Character::LETTER) {
			if (lexemeDef[str] == Lexeme::KEYWORD) {
				lexemes.push_back(Lexeme(str, Lexeme::KEYWORD));
			} else if (lexemeDef[str] == Lexeme::LITERAL) {
				lexemes.push_back(Lexeme(str, Lexeme::LITERAL));
			} else if (lexemeDef[str] == Character::NUMBER) {
				while ((isdigit(currChar.c) 
					|| currChar.c == 'f')
					&& str[str.size()-1] != 'f') {
					str += currChar.c;
					characters.erase(characters.begin);
				}
			}
			
			else if (str != "") {
				lexemes.push_back(Lexeme(str, Lexeme::IDENTIFIER));
			}
			str = "";
		} else {
			str += currChar.c;
		}

	} while (!characters.empty());
}


