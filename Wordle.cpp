#include <std_lib_facilities.h>
#include "utilities.h"
#include "Wordle.h"

void playWordle() {
    string fasit = getRandomFiveLetterWord();
    cout << fasit << '\n';

    while (true) {
        // gjett ord
        string guess = readInputToString();
        // Verifisere at ordet er lovlig (5 bokstaver, kan ikke være tullball)
        while ( verifyWordLegality(guess) == false) {
            guess = readInputToString();
        }

        // Sjekke om ordet er riktig
        vector<bool> greens = {false, false, false, false, false};
        for (unsigned int letterIdx = 0; letterIdx < guess.size(); letterIdx++) {
            char bokstav = guess.at(letterIdx);
            if (checkCharacterAndPosition(fasit, bokstav, letterIdx)) {
                // Lagre at det er riktig
                greens.at(letterIdx) = true;
            }

        }
        for (unsigned int letterIdx = 0; letterIdx < guess.size(); letterIdx++) {
            if (greens.at(letterIdx) == true) {
                cout << "GREEEN ";
            }
            else {
                cout << "GRAY ";
            }
    
        }
        cout << '\n';


        // Sjekke hvilke bokstaver som er på rett plass
        // Lagre denne informasjonen

        // Sjekke hvilke bokstaver som er i ordet, men ikkje på rett plass.
        // Lagre denne informasjonen

        // Gi tilbakemelding på gjett 

    }
    // Gratulere med seier eller tap

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