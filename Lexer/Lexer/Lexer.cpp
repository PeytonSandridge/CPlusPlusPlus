#include "Lexer.h"
#include <iostream>
using std::iostream;

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

inline Lexer::Lexer(string code){
	input = code;
	setUp();
}

Lexer::Lexer() {
	input = "";
	setUp();
}

inline vector<Character> Lexer::getCharacterTokens() {
	vector<Character> tokenVect;

	for (int i = 0; i < input.size(); i++) {
		tokenVect.push_back(Character(input[i], tokenDef[input[i]]));
	}

	return tokenVect;
}

inline vector<string> Lexer::getWords() {
	//gets all characters and their catagorizations
	vector<Character> chars = getCharacterTokens();
	//creates vectors for final words
	vector<string> words;

	string str = "";

	//sorts all characters
	while (!chars.empty()) {
		//gets the current token (creates a variable so i dont have to reaccess each time
		Character curr = chars.front();

		//creates words using the separators and also adds operators and etc
		if (curr.token != Character::LETTER) {
			//if there was already a word, push it and reset string
			if (str != "") {
				words.push_back(str);
				str = "";
			}

			//if its not a whitespace character push it to words
			if (curr.token != Character::WHITE_SPACE) {
				words.push_back(getString(curr.c));
			}
		} else {
			str += curr.c;
		}

		//erases the front
		chars.erase(chars.begin());
	}
}

inline vector<Lexeme> Lexer::getLexemes() {
	vector<Lexeme> lexes;
	vector<Character> chars = getCharacterTokens();

	string temp;

	while (!chars.empty()) {
		char c = chars.front().c;
		chars.erase(chars.begin());

		
	}
}

// checks to see if a word is entirely made of letters
inline bool isWord(string s) {
	bool isLetter = false;
	for (int i = 0; i < s.size(); i++) {
		if (!isLetter) {
			return false;
		}
		isLetter = false;
		for (char a = 'a'; a <= 'z'; a++) {
			if (s[i] == a) {
				isLetter = true;
			}
		}
	}
}

//checks to see if a string can be a number
inline bool isNum(string str) {
	//needs to start with a number
	if (isdigit(str[0])) {
		return false;
	}

	//keeps track if weve seen a decimal or not
	bool hasDecimal = false;

	//checks to see if rest of string is digit, f, or a .
	for (int index = 1; index <= str.size()-1; index++) {
		char temp = str[index];

		//checks to see the non numerical valid inputs
		if (!isdigit(temp)) {
			if (temp == '.') {
		
				// checks to see if weve seena  decimal or not (a number can only have 1 decimal point
				if (!hasDecimal) {
					hasDecimal = true;
				} else {
					return false;
				}

			} else if (temp == 'f') {
				
				//only the last character should have a f
				if (index != str.size() - 1) {
					return false;
				}

			}
			
			//if its not a digit or a case statement, return false
			return false;
		}

		
	}
	
	return true;
}

//creates string from char
inline string getString(char c) {
	//creates a string of size 1 and sets all indexes (1) to the input char
	string s(1, c);

	return s;
}

