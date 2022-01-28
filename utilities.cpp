#include "std_lib_facilities.h"
#include "utilities.h"

int randomInteger(int lower, int upper) {
    int difference = upper-lower+1;
    return lower + (rand()%difference);
}

string getRandomFiveLetterWord() {
    int index = randomInteger(0, allowedCorrectAnswers.size());
    string word = allowedCorrectAnswers[index];
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
        stringy[index] = tolower(stringy[index]);
    }
    return stringy;
}
