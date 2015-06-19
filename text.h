#include "assoc_tab.h"
#include <stdio.h>






int process_text(char* in,assoc_tab* tab[],int grams);  /*wczytuje z pliku tekstowego tekst i tworzy z niego tablicę przejść */
/*zwraca wartosc pierwszego hasha */ /*dziala!*/

void generate_text(char* out, assoc_tab* tab[],int grams, int dlugosc); /*generuje tekst o podanej dlugosci*/

		/*TODO dodac obsluge reszty argumentow */
