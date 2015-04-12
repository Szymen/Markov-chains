#include "assoc_tab.h"
#include <stdio.h>






assoc_tab* process_text(FILE *in);  /*wczytuje z pliku tekstowego tekst i tworzy z niego tablicę przejść */
/*zwraca wskaźnik na tablicę przejsc */

void generate(FILE *out, assoc_tab* tab, int dlugosc); /*generuje tekst o podanej dlugosci*/

		/*TODO dodac obsluge reszty argumentow */
