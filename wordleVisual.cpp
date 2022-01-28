#include "wordleVisual.h"
#include "utilities.h"

void addGuess(WordleWindow &mwin, const string code, const char startLetter)
{
	// definer addGuess
}

void addFeedback(WordleWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// definer addFeedback
}

void WordleWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

WordleWindow::WordleWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{upperLeftCornerBtn.x, upperLeftCornerBtn.y, btnW, btnH, "Add"},
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
		for(int guessIndex = 0; guessIndex < guesses.size(); guessIndex++) {
			//Implementer gjett slik at det vises fargede rektangler i grafikkvinduet
			{
                // Tegn rektangler ved bruk av draw_rectangle()
				draw_rectangle(Point{100, 100}, 10, 10, Color::gray);
				
			}
		}

		for(int feedbackIndex = 0; feedbackIndex < feedbacks.size(); feedbackIndex++) {
			// Implementer feedback

			for (int i = 0; i < size; i++)
			{
				// Tegn sirkler ved hjelp av draw_circle
			}
		}

		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;
	string newGuess = guess.value();
	guess.value(0);
	return newGuess;
}

string WordleWindow::getInput()
{
	string guess;
	while (!verifyWordLegality(guess) && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		for (int index = 0; index < input.length(); index++) {
			input[index] = tolower(input[index]);
		}
	}
	return guess;
}

void WordleWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}