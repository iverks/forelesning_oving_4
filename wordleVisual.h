#pragma once
#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"

constexpr int pad = 5;  // velg y skalering

constexpr int btnSize = 63;

constexpr int winW = pad * (2 + 5 + 1) + btnSize * (2 + 5);  // velg vindu bredde
constexpr int winH = pad * (2 + 6 + 1) + btnSize * (4 + 6);  // velg vindu hoyde

constexpr Point upperLeftCornerBtn = Point{winW - pad - btnSize, pad};

constexpr int inBoxW = winW - 3 * pad - btnSize;
constexpr int inBoxH = btnSize;
constexpr Point upperLeftCornerInBox = Point{pad, pad};

// UTENFOR PENSUM
enum WordleColor {
    yellow = 0xb59f3b00,
    green = 0x538d4e00,
    gray = 0x3a3a3c00,
    black = 0x12121300,
    white = 0xd7dadc00
};

struct Guess {
    const string code;
    const vector<TDT4102::Color> colors;
};

// Her defineres klassen WordleWindow, som arver fra klassen AnimationWindow.
// Det betyr at alle medlemsvariable og medlemsfunksjoner i AnimationWindow, også er en
// del av WordleWindow. Du kan lese mer om klasser i kapittel 9.4 og om arv
// i kapittel 14.3 i læreboka.
class WordleWindow : public AnimationWindow {
   public:
    WordleWindow(int x, int y, int w, int h, int size, const string& title);

    vector<Guess> guesses;

    void appendResult(
        string guess,
        vector<bool> greens,
        vector<bool> yellows);
    void displayFinalResult(string code, bool didWin);

    string getInput();

   private:
    string wait_for_guess();
    void drawBg();
    void drawLetterSquares();
    void newGuess() { button_pressed = true; }
    bool button_pressed = false;
    Button guessBtn;
    TextInput guess;
    int size = 0;
};