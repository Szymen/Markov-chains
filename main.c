#include<stdio.h>
#include<stdlib.h>
#include "text.h"
#include "hash.h"
/*#include "linked_list.h" zainkludowane w assoc_tab ^-^  */
/*#include "assoc_tab.h"  jest w text.h */

int main(int argc, char* argv[]) // stopien n-gramu , nazwa pliku wejsciowego, nazwa pliku wyjsciowego, dlugosc tekstu
{
    int TAB_SIZE = 1000009;
    int GRAMS = 3;
    if (argc < 4){printf("Zle podane parametry!\n"); return 1;}

    GRAMS = atoi(argv[1]);
    char *nazwa_wejscia = argv[2];
    char *nazwa_wyjscia = argv[3];
    int dlugosc_wyjscia = atoi(argv[4]);

    assoc_tab *tab[TAB_SIZE];
    assoc_initialize(tab,TAB_SIZE);
    process_text(nazwa_wejscia,tab,GRAMS);
    generate_text(nazwa_wyjscia,tab,GRAMS,dlugosc_wyjscia);
    return 0;
}

