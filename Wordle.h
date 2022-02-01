#pragma once
#include "std_lib_facilities.h"

void playWordle();
bool checkCharacterAndPosition(string code, char guess, int position);
bool checkCharacterIgnorePosition(string code, char guess);