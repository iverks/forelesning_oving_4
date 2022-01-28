#pragma once
void playWordle();
bool verifyWordLegality(string word);
bool checkCharacterAndPosition(string code, char guess, int position);
bool checkCharacterIgnorePosition(string code, char guess);