#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

namespace IO {

	class Input {
	public:
		string difficulty();
		string secretWord();
		char guessLetter();
	};

	class Output {
	public:

		void title();
		void mistakes(int mistakes, int totalMistakes);
		void clue(vector<char> clues);
		void lost(string name);
		void win(string name);
		void wrongLetters(vector<char> letters);
		void guess(char letter);
		
	};


};