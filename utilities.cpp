#include "std_lib_facilities.h"
#include "utilities.h"

int randomInteger(int lower, int upper) {
    int difference = upper-lower+1;
    return lower + (rand()%difference);
}

string getRandomFiveLetterWord() {
    int index = randomInteger(0, allowedCorrectAnswers.size());
    string word = allowedCorrectAnswers.at(index);
    if (word.length() != wordLength) {
        cout << "Generated word is not 5 letters long! Catastrophy!\n";
    }
    return word;
}

string readInputToString() {
    string stringy;
    cout << "Guess a five letter word\n";
    cin >> stringy;
    for (int index = 0; index < stringy.length(); index++) {
        stringy.at(index) = tolower(stringy.at(index));
    }
    return stringy;
}

bool verifyWordLegality(string word) {
    if (word.length() != 5) {
        cout << "Word needs to be 5 letters long!\n";
        return false;
    }

    for (string allowedWord: allowedCorrectAnswers) {
        if (word == allowedWord) {
            return true;
        }
    }

    for (string allowedWord: allowedWrongAnswers) {
        if (word == allowedWord) {
            return true;
        }
    }

    cout << "Did you really think that was a real word?\n";
    return false;
}

string getInput() {
    string guess = readInputToString();
	while (!verifyWordLegality(guess))
	{
		guess = readInputToString();
	}
	return guess;
}