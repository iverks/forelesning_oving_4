#include <std_lib_facilities.h>
#include "utilities.h"
#include "Wordle.h"
#include "wordleVisual.h"

void playWordle() {
    constexpr int maxGuesses = 6;
    int guessNr = 0;
    string code;
    string guess;
    code = getRandomFiveLetterWord();
    WordleWindow wwin(300, 20, winW, winH, wordLength, "Wordle");
    wwin.color(WordleColor::black);

    while ( guess != code && guessNr < maxGuesses ) {
        cout << "guess nr: " << ++guessNr << '\n';
        guess = wwin.getInput();

        vector<bool> greens, yellows;
        for (int i = 0; i < code.length(); i++) {
            greens.push_back(false);
            yellows.push_back(false);
        }

        for (int i = 0; i < code.length(); i++) {
            greens[i] = checkCharacterAndPosition(code, guess[i], i);
        }
       
        for (int i = 0; i < code.length(); i++) {
            yellows[i] = checkCharacterIgnorePosition(code, guess[i]);
        }

        for (int i = 0; i < code.length(); i++) {
            if (greens[i])
                // cout << "green ";
                cout << magicGreen << guess[i] << endMagic;
            else if (yellows[i]) 
                // cout << "yellow ";
                cout << magicYellow << guess[i] << endMagic;
            else 
                // cout << "grey ";
                cout << guess[i];
        }
        cout << "\n";
    }
    if (guess == code ) 
        cout << "kinda nice bro\n";
    else 
        cout << "Nice try haha\n"; 
}


bool checkCharacterAndPosition(string code, char guess, int position) {
    if ( code[position] == guess) {
        return true;
    }
    else {
        return false;
    }
}

bool checkCharacterIgnorePosition(string code, char guess) {
    for (int i = 0; i < code.length(); i++ ){
        if (code[i] == guess) {
            return true;
        }
    }
    return false;
}