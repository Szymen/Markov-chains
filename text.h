#include "assoc_tab.h"
#include <stdio.h>






void process_text(char* in,assoc_tab* tab[],int grams);  /*wczytuje z pliku tekstowego tekst i tworzy z niego tablicę przejść */
/*zwraca wskaźnik na tablicę przejsc */

void generate_text(char* out, assoc_tab* tab[],int hash_size,int grams, int dlugosc); /*generuje tekst o podanej dlugosci*/

		/*TODO dodac obsluge reszty argumentow */
