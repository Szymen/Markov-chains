#include<stdio.h>
#include<stdlib.h>
#include "text.h"
#include "hash.h"
/*#include "linked_list.h" zainkludowane w assoc_tab ^-^  */
/*#include "assoc_tab.h"  jest w text.h */

int main()
{
    int TAB_SIZE=1000009;
    assoc_tab *tab[TAB_SIZE];
    assoc_initialize(tab,TAB_SIZE);
    char *slowo="dupa";
    int i;

    int first=process_text("odyseja.txt",tab,3);


    printf("%d\n",first);



return 0;
}

