#pragma once
#include <string>

void playWordle();
bool checkCharacterAndPosition(std::string code, char guess, int position);
bool checkCharacterIgnorePosition(std::string code, char guess);