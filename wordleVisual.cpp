#include "wordleVisual.h"
#include "utilities.h"

void addGuess(WordleWindow &wwin, const string code, const char startLetter)
{

	// definer addGuess
}

void addFeedback(WordleWindow &wwin, const int correctPosition, const int correctCharacter)
{
	// definer addFeedback
}

WordleWindow::WordleWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{upperLeftCornerBtn.x, upperLeftCornerBtn.y, btnSize, btnSize, "Add"},
guess{upperLeftCornerInBox.x, upperLeftCornerInBox.y, inBoxW, inBoxH, "Guess"},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.callback(cb_guess, this);
};

string WordleWindow::wait_for_guess()
{
	while (!button_pressed && !should_close())
	{	
		// Draw guessed letters
		for(int gjettNr = 0; gjettNr < guesses.size(); gjettNr++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			Guess gjett = guesses.at(gjettNr);
			int y = (pad+btnSize) * 2 + (pad+btnSize) * gjettNr;
			for (unsigned int bokstavNr = 0; bokstavNr < wordLength; bokstavNr++) {
				int x = (pad+btnSize) * 1 + (pad+btnSize) * bokstavNr;
				draw_rectangle({x, y}, btnSize, btnSize, gjett.colors.at(bokstavNr));
				string letter;
				letter.push_back(gjett.code.at(bokstavNr));
				draw_text({x + 2*pad, y + btnSize - 2*pad}, letter, WordleColor::white, 50U );
			}
		}
		// Draw placeholders in the rest of the spots
		for(int gjettNr = guesses.size(); gjettNr < maxGuesses; gjettNr++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			int y = (pad+btnSize) * 2 + (pad+btnSize) * gjettNr;
			for (unsigned int bokstavNr = 0; bokstavNr < wordLength; bokstavNr++) {
				int x = (pad+btnSize) * 1 + (pad+btnSize) * bokstavNr;
				draw_rectangle({x, y}, btnSize, btnSize, WordleColor::gray);
				draw_rectangle({x+pad, y+pad}, btnSize-2*pad, btnSize-2*pad, WordleColor::black);
			}
		}

		next_frame();
	}
	button_pressed = false;
	string newGuess = guess.value();
	guess.value(0);
	return newGuess;
}

string WordleWindow::getInput()
{
	string guess = wait_for_guess();
	for (int index = 0; index < guess.size(); index++) {
			guess.at(index) = tolower(guess.at(index));
		}

	while (!verifyWordLegality(guess) && !should_close())
	{	
		guess = wait_for_guess();
		for (int index = 0; index < guess.size(); index++) {
			guess.at(index) = tolower(guess.at(index));
		}
	}
	return guess;
}

void WordleWindow::appendResult(string word, vector<bool> greens, vector<bool> yellows) {
	vector<WordleColor> colors(5, WordleColor::gray);
	for (int pelle = 0; pelle < word.size(); pelle++) {
		if (greens.at(pelle)) {
			colors.at(pelle) = WordleColor::green;
		} else if (yellows.at(pelle)) {
			colors.at(pelle) = WordleColor::yellow;
		} 
	}
	guesses.push_back(Guess{word, colors});
}