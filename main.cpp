#include "Wordle.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "wordleVisual.h"

int main() {
    srand(time(NULL));

    //? Char-aritmetikk
    // char g = 'g';
    // char d = 'd';
    // char k = 'k';
    // char n = 'n';

    //? Hva printes her?
    // cout << char(g + 1)
    //    << char(d + 1)
    //    << char(k + 1)
    //    << char(k + 1)
    //    << char(n + 1) << '\n';

    // // Char-aritmetikk 2
    // char vanskelig = 'z';
    // // Hva blir dette?
    // cout << char(vanskelig + 1) << '\n';

    //* Bli kjent med feilmeldinger
    //? string stringy = 'hello'; //! error: no viable conversion from 'int' to 'std::string' (aka 'basic_string<char>')
    //? char a = "a"; //! error: cannot initialize a variable of type 'char' with an lvalue of type 'const char[2]'
    //? char a = 'å'; //! error: character too large for enclosing character literal type

    // Oppgave 4
    playWordle();
    return 0;
}
