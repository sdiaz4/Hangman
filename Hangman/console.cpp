#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "console.hpp"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

namespace IO {

	string Input::difficulty() {
		string difficulty;

		cin >> difficulty;
		for (int i = 0; i < difficulty.size(); i++)
		{
			difficulty.at(i) = toupper(difficulty.at(i));
		}


		return difficulty;
	}

	string Input::secretWord() {
		string secretWord;

		cin >> secretWord;
		for (int i = 0; i < secretWord.size(); ++i)
		{
			secretWord.at(i) = toupper(secretWord.at(i));
		}
		return secretWord;
	}

	char Input::guessLetter() {
		char letter;
		cin >> letter;
		letter = toupper(letter);
		return letter;
		
	}


	void Output::title() {
		cout << "Hangman" << endl << "-------";
	}

	void Output::mistakes(int mistakes, int totalMistakes) {
		cout << "Mistakes: " << mistakes << "/" << totalMistakes;
	}

	void Output::clue(vector<char> clues) {
		cout << "Clue:     ";
		for (int i = 0; i < clues.size(); ++i)
		{
			cout << clues.at(i);
		}
		cout << endl;
	}

	void Output::lost(string name) {
		cout << "You lost." << endl;
		cout << "The word was: " << name;
	}

	void Output::win(string name) {
		cout << "You won!" << endl;
		cout << "The word was: " << name;
	}

	void Output::wrongLetters(vector<char> letters) {
		cout << "Wrong:    ";
		for (int i = 0; i < letters.size(); ++i) {
			cout << letters.at(i);
		}
		cout << endl;
	}

	void Output::guess(char letter) {
		cout << "Guess: " << letter << endl;
	}

	
}