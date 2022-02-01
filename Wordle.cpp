#include <std_lib_facilities.h>
#include "utilities.h"
#include "Wordle.h"
#include "wordleVisual.h"

void playWordle() {
    int guessNr = 0;
    string code;
    string guess;

    code = getRandomFiveLetterWord();
    WordleWindow wwin(300, 20, winW, winH, wordLength, "Wordle");
    wwin.color(WordleColor::black);

    while ( guess != code && guessNr < maxGuesses ) {
        cout << "guess nr: " << ++guessNr << '\n';
        // guess = getInput();
        guess = wwin.getInput();

        vector<bool> greens, yellows;
        for (int i = 0; i < guess.length(); i++) {
            greens.push_back(false);
            yellows.push_back(false);
        }

        for (int i = 0; i < guess.length(); i++) {
            greens.at(i) = checkCharacterAndPosition(code, guess.at(i), i);
            yellows.at(i) = checkCharacterIgnorePosition(code, guess.at(i));
        }

        // Grafikk
        wwin.appendResult(guess, greens, yellows);

        for (int i = 0; i < code.length(); i++) {
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
    }
    if (guess == code ) 
        cout << "Flink :^)\n";
    else 
        cout << "...\n"; 
        cout << "Det riktige ordet var: " << code << ", burde kanskje gjettet det...\n";
}


bool checkCharacterAndPosition(string code, char guess, int position) {
    if ( code.at(position) == guess) {
        return true;
    }
    else {
        return false;
    }
}

bool checkCharacterIgnorePosition(string code, char guess) {
    for (int i = 0; i < code.length(); i++ ){
        if (code.at(i) == guess) {
            return true;
        }
    }
    return false;
}