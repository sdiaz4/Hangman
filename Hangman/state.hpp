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

namespace hangman {

	class State {
	public:

		enum class Modes {
			easy = 0,
			regular = 1,
			hard = 2
		};

		Modes convertMode(string mode);

		int totalMistakes(Modes mode);

		size_t stringSize(string name);

		vector<char> clueLine(size_t size);

		bool letterFound(string name, char letter);

		vector<int> findLetter(string name, char letter);

		vector<char> changeClue(char letter, vector<int> letterLocations, vector<char>& clue);

		int addMistakes(int& total);

		bool lostGame(int mistakes, int totalMistakes);

		bool wonGame(string word, vector<char> clue);

		vector<char> addWrongLetter(char letter, vector<char>& letters);

		bool alreadyAsked(char letter, vector<char> usedLetters);

		bool isNormalOrHard(string mode);

		vector<char> addRightLetter(char letter, vector<char>& letters);



	};


}