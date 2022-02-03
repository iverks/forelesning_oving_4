#include "std_lib_facilities.h"
int charToInt(char character) {
    // a -> 1, A -> 1
    // b -> 2 ...
    character = tolower(character);
    // a - a = 0
    // b - a = 1 
    character -= 'a';
    character += 1;
    return static_cast<int>(character);
}