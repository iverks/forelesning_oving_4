#include "Wordle.h"

#include "std_lib_facilities.h"
#include "utilities.h"
#include "wordleVisual.h"

void playWordle() {
    int guessNr = 0;
    string code;
    string guess;

    code = getRandomFiveLetterWord();
    WordleWindow wwin(300, 20, winW, winH, wordLength, "Wordle");

    while (guess != code && guessNr < maxGuesses) {
        guess = wwin.getInput();
        guessNr++;

        vector<bool> greens, yellows;
        for (int i = 0; i < guess.length(); i++) {
            greens.push_back(false);
            yellows.push_back(false);
        }

        for (int i = 0; i < guess.length(); i++) {
            greens.at(i) = checkCharacterAndPosition(code, guess.at(i), i);
            yellows.at(i) = checkCharacterIgnorePosition(code, guess.at(i));
        }

        // Feedback
        wwin.appendResult(guess, greens, yellows);
    }

    bool didWin = false;
    if (guess == code) {
        didWin = true;
    }

    wwin.displayFinalResult(code, didWin);
}

bool checkCharacterAndPosition(string code, char guess, int position) {
    if (code.at(position) == guess) {
        return true;
    } else {
        return false;
    }
}

bool checkCharacterIgnorePosition(string code, char guess) {
    for (int i = 0; i < code.length(); i++) {
        if (code.at(i) == guess) {
            return true;
        }
    }
    return false;
}