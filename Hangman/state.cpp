#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "state.hpp"
#include <algorithm>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::sort;



namespace hangman {


	State::Modes State::convertMode(string mode) {
		if (mode == "EASY")
			return Modes::easy;
		else if (mode == "REGULAR")
			return Modes::regular;
		else
			return Modes::hard;
	}

	int State::totalMistakes(Modes mode) {
			
		if (mode == Modes::easy)
			return 9;
		else if (mode == Modes::regular)
			return 9;
		else
			return 6;
	}

	size_t State::stringSize(string name) {
		return name.size();
	}

	vector<char> State::clueLine(size_t size) {
		vector<char> clue;
		for (int i = 0; i < size; ++i) {
			clue.push_back('_');
		}
		return clue;
	}

	bool State::letterFound(string name, char letter) {
		for (int i = 0; i < name.size(); ++i) {
			if (name.at(i) == letter) {
				return true;
			}
		}
		return false;
	}

	vector<int> State::findLetter(string name, char letter) {
		vector<int> letterFound;
		for (int i = 0; i < name.size(); ++i) {
			if (name.at(i) == letter) {
				letterFound.push_back(i);
			}
		}
		return letterFound;
	}

	vector<char> State::changeClue(char letter, vector<int> letterLocations, vector<char>& clue) {
		for (int i = 0; i < letterLocations.size(); ++i) {
			clue.at(letterLocations.at(i)) = letter;
		}
		return clue;
	}

	int State::addMistakes(int& total) {
		total = total + 1;
		return total;
	}	


	bool State::lostGame(int mistakes, int totalMistakes) {
		if (mistakes >= totalMistakes) {
			return true;
		}
		return false;
	}

	bool State::wonGame(string word, vector<char> clue) {
		bool state = true;
		for (int i = 0; i < word.size(); ++i) {
			if (word.at(i) != clue.at(i)) {
				state = false;
			}
		}
		return state;
	}

	vector<char> State::addWrongLetter(char letter, vector<char>& letters) {
		letters.push_back(letter);
		sort(letters.begin(), letters.end());
		return letters;
	}

	bool State::alreadyAsked(char letter, vector<char> usedLetters) {
		for (int i = 0; i < usedLetters.size(); ++i) {
			if (usedLetters.at(i) == letter) {
				return true;
			}
		}
		return false;
	}

	bool State::isNormalOrHard(string mode) {
		if (mode == "easy")
			return false;
		else
			return true;
	}

	vector<char> State::addRightLetter(char letter, vector<char>& letters) {
		letters.push_back(letter);
		return letters;
	}


}