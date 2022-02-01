#include "std_lib_facilities.h"
#include "utilities.h"
#include "Wordle.h"

int main() {
   srand(time(NULL));

   
   // // Char-aritmetikk
   // char g = 'g';
   // char d = 'd';
   // char k = 'k'; 
   // char n = 'n';

   // cout << char(g + 1) // Hva printes her?
   //    << char(d + 1)
   //    << char(k + 1)
   //    << char(k + 1)
   //    << char(n + 1) << '\n'; 
   
   /*
   // // Char-aritmetikk 2
   // char vanskelig = 'z';
   // // Hva blir dette?
   // cout << char(vanskelig + 1) << '\n';

   /*
   // // Datatyper
   // // IKKE BRUK AUTO I ØVINGEN !!
   // auto eksempel = 58008;
   // // IKKE BRUK AUTO I ØVINGEN !!
   // auto a = 'o';
   // auto b = "hello"; // Hint: det er ikke en string
   // auto c = "w";
   // auto dd = 'rld';
   // string e = "!";
   */

   // Oppgave 4
   playWordle();
}

