#include "std_lib_facilities.h"
#include "utilities.h"

int randomInteger(int lower, int upper) {
    // Fra og med, til og med
    int difference = upper-lower+1;
    return lower + (rand()%difference);
}

string getRandomFiveLetterWord() {
    int index = randomInteger(0, allowedCorrectAnswers.size()-1);
    return allowedCorrectAnswers.at(index);
}

string readInputToString() {
    string stringy;
    cout << "Guess a five letter word\n"; 
    cin >> stringy; // Get word
    for (int index = 0; index < stringy.length(); index++) {
        stringy.at(index) = tolower(stringy.at(index)); // Gjør til små bokstaver
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