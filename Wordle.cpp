#include "Wordle.h"

#include "std_lib_facilities.h"
#include "utilities.h"
#include "wordleVisual.h"

void playWordle() {
    int guessNr = 0;
    string code;
    string guess;

    code = getRandomFiveLetterWord();
    // WordleWindow wwin(300, 20, winW, winH, wordLength, "Wordle");
    cout << code << "\n";

    while (guess != code && guessNr < maxGuesses) {
        cout << "guess nr: " << ++guessNr << '\n';
        guess = getInput();
        // guess = wwin.getInput();
        guessNr++;

        vector<bool> greens, yellows;
        for (int i = 0; i < guess.length(); i++) {
            greens.push_back(false);
            yellows.push_back(false);
        }

        string tempCode = code;
        for (int i = 0; i < guess.length(); i++) {
            greens.at(i) = checkCharacterAndPosition(code, guess.at(i), i);
            tempCode.at(i) = ' ';
        }
        for (int i = 0; i < guess.length(); i++) {
            if (checkCharacterIgnorePosition(tempCode, guess.at(i)) && !checkCharacterAndPosition(code, guess.at(i), i)) {
                yellows.at(i) = true;
                for (int j = 0; j < 5; j++) {
                    if (tempCode.at(j) == guess.at(i)) {
                        tempCode.at(j) = ' ';
                        break;
                    }
                }
            }
        }

        // Feedback
        // wwin.appendResult(guess, greens, yellows);
        printGuessResult(guess, greens, yellows);
    }

    bool didWin = false;
    if (guess == code) {
        didWin = true;
    }

    // wwin.displayFinalResult(code, didWin);
    printFinalResult(code, didWin);
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

void printGuessResult(string guess, vector<bool> greens, vector<bool> yellows) {
    for (int i = 0; i < guess.length(); i++) {
        if (greens.at(i))
            // cout << "green ";
            cout << magicGreen << guess.at(i) << endMagic;
        else if (yellows.at(i))
            // cout << "yellow ";
            cout << magicYellow << guess.at(i) << endMagic;
        else
            // cout << "grey ";
            cout << guess.at(i);
    }
    cout << "\n";

    for (int i = 0; i < guess.length(); i++) {
        if (greens.at(i))
            // cout << "green ";
            cout << magicGreen << "GREEN " << endMagic;
        else if (yellows.at(i))
            // cout << "yellow ";
            cout << magicYellow << "YELLOW " << endMagic;
        else
            // cout << "grey ";
            cout << "GRAY ";
    }
    cout << "\n";
}

void printFinalResult(string code, bool didWin) {
    cout << "The word was " << code;
    if (didWin) {
        cout << " congratulations!\n";
    } else {
        cout << " im sorry\n";
    }
}
