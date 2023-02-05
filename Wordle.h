#pragma once
#include <string>
#include <vector>

void playWordle();
bool checkCharacterAndPosition(std::string code, char guess, int position);
bool checkCharacterIgnorePosition(std::string code, char guess);
void printGuessResult(std::string guess,
                      std::vector<bool> greens,
                      std::vector<bool> yellows);
void printFinalResult(std::string code, bool didWin);
