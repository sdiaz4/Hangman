#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include "state.hpp"
#include "console.hpp"
#include "game.hpp"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;


namespace hangman {
	void Game::playGame() {
		IO::Input input;
		IO::Output output;
		State state;

		

		string difficulty = input.difficulty();
		string secretWord = input.secretWord();
		

		while (secretWord != "quit") {
			vector<char> rightLetter;
			bool gameOver = false;
			int mistakes = 0;
			vector<char> clues;
			vector<char> wrongLetters;
			
			
			size_t size;

			output.title();
			cout << endl << endl;
			auto mode = state.convertMode(difficulty);
			int totalMistakes = state.totalMistakes(mode);
			size = state.stringSize(secretWord);
			clues = state.clueLine(size);

			output.mistakes(mistakes, totalMistakes);
			cout << endl;
			output.clue(clues);

			cout << endl;
		
			while (gameOver != true) {
				
				char letter = input.guessLetter();
				output.guess(letter);
				cout << endl;

				if (state.letterFound(secretWord, letter)) {
					vector<int> locations = state.findLetter(secretWord, letter);
					state.changeClue(letter, locations, clues);
					if (state.isNormalOrHard(difficulty)) {
						if (!state.alreadyAsked(letter, rightLetter)) {
							state.addRightLetter(letter, rightLetter);
						}
						else {
							state.addMistakes(mistakes);
						}
					}
					
				}
				else {
					state.addMistakes(mistakes);
					if (!state.alreadyAsked(letter, wrongLetters)) {
						state.addWrongLetter(letter, wrongLetters);
					}
				}

				output.mistakes(mistakes, totalMistakes);
				cout << endl;
				output.clue(clues);
				if (wrongLetters.size() > 0)
				{
					output.wrongLetters(wrongLetters);
				}
				cout << endl;

				if (state.wonGame(secretWord, clues)) {
					output.win(secretWord);
					gameOver = true;
				}
				else if (state.lostGame(mistakes, totalMistakes))
				{
					output.lost(secretWord);
					gameOver = true;
				}

			}
			
			difficulty = input.difficulty();
			secretWord = input.secretWord();
			cout << endl;

			
		}

	}
}