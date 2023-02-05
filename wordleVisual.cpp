#include "wordleVisual.h"

#include "utilities.h"

using namespace TDT4102;

const map<char, Color> colorConverter{
    {'y', Color(0xb59f3b)},  // yellow
    {'g', Color(0x538d4e)},  // green
    {'G', Color(0x3a3a3c)},  // gray
    {'B', Color(0x121213)},  // black
    {'W', Color(0xd7dadc)},  // white
};

WordleWindow::WordleWindow(int x, int y, int w, int h, int size, const string& title)
    : AnimationWindow(x, y, w, h, title),
      guessBtn{upperLeftCornerBtn, btnSize, btnSize, "Add"},
      guess{upperLeftCornerInBox, inBoxW, inBoxH, "Guess"},
      size(size) {
    add(guess);
    add(guessBtn);
    guessBtn.setCallback(std::bind(&WordleWindow::newGuess, this));
};

bool WordleWindow::enterToggled() {
    static bool enterWasDown = false;
    bool enterIsDown = is_key_down(KeyboardKey::ENTER);
    if (enterIsDown && !enterWasDown) {
        enterWasDown = true;
        return true;
    }
    enterWasDown = false;
    return false;
}

string WordleWindow::wait_for_guess() {
    while (!button_pressed && !should_close() && !enterToggled()) {
        drawBg();
        // Draw guessed letters
        drawLetterSquares();
        next_frame();
    }
    button_pressed = false;
    string newGuess = guess.getText();
    guess.setText("");
    return newGuess;
}

string WordleWindow::getInput() {
    string guess = wait_for_guess();
    for (int index = 0; index < guess.size(); index++) {
        guess.at(index) = tolower(guess.at(index));
    }

    while (!verifyWordLegality(guess) && !should_close()) {
        guess = wait_for_guess();
        for (int index = 0; index < guess.size(); index++) {
            guess.at(index) = tolower(guess.at(index));
        }
    }
    return guess;
}

void WordleWindow::appendResult(string word, vector<bool> greens, vector<bool> yellows) {
    vector<Color> colors(5, colorConverter.at('G'));
    for (int pelle = 0; pelle < word.size(); pelle++) {
        if (greens.at(pelle)) {
            colors.at(pelle) = colorConverter.at('g');
        } else if (yellows.at(pelle)) {
            colors.at(pelle) = colorConverter.at('y');
        }
    }
    guesses.push_back(Guess{word, colors});
}

void WordleWindow::displayFinalResult(string code, bool didWin) {
    char displayColor = 'G';
    string displayText = code;
    if (didWin) {
        displayColor = 'g';
        displayText = "correct";
    }

    while (!button_pressed && !should_close()) {
        drawBg();
        drawLetterSquares();
        draw_rectangle({pad + btnSize, winH - (pad + 2 * btnSize)}, (pad + btnSize) * 5, (pad + btnSize), colorConverter.at(displayColor));
        draw_text({2 * pad + btnSize, winH - (pad + 2 * btnSize)}, displayText, colorConverter.at('W'), 50U);
        next_frame();
    }
    button_pressed = false;
}

void WordleWindow::drawBg() {
    draw_rectangle({0, 0}, this->width(), this->height(), colorConverter.at('B'));
}

void WordleWindow::drawLetterSquares() {
    for (int gjettNr = 0; gjettNr < guesses.size(); gjettNr++) {
        // Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
        Guess gjett = guesses.at(gjettNr);
        int y = (pad + btnSize) * 2 + (pad + btnSize) * gjettNr;
        for (unsigned int bokstavNr = 0; bokstavNr < wordLength; bokstavNr++) {
            int x = (pad + btnSize) * 1 + (pad + btnSize) * bokstavNr;
            draw_rectangle({x, y}, btnSize, btnSize, gjett.colors.at(bokstavNr));
            string letter;
            letter.push_back(gjett.code.at(bokstavNr));
            draw_text({x + 2 * pad, y}, letter, colorConverter.at('W'), 56U);
        }
    }
    // Draw placeholders in the rest of the spots
    for (int gjettNr = guesses.size(); gjettNr < maxGuesses; gjettNr++) {
        // Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
        int y = (pad + btnSize) * 2 + (pad + btnSize) * gjettNr;
        for (unsigned int bokstavNr = 0; bokstavNr < wordLength; bokstavNr++) {
            int x = (pad + btnSize) * 1 + (pad + btnSize) * bokstavNr;
            draw_rectangle({x, y}, btnSize, btnSize, colorConverter.at('G'));
        }
    }
}
