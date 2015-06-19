#include<stdio.h>
#include<stdlib.h>
#include "text.h"
#include "hash.h"
/*#include "linked_list.h" zainkludowane w assoc_tab ^-^  */
/*#include "assoc_tab.h"  jest w text.h */

int main()
{
    int TAB_SIZE = 1000009;
    int GRAMS = 3;
    int first_hash;
    assoc_tab *tab[TAB_SIZE];
    assoc_initialize(tab,TAB_SIZE);
    process_text("Iliada.txt",tab,GRAMS);
    process_text("calineczka.txt",tab,GRAMS);
    /*int i=0;
    for( i = 0; i<TAB_SIZE;i++){
        if(tab[i]->size>0){
            printf("W petli indeks : %d ->", i);
            node *tmp = tab[i]->possible;
            while(tmp){
                printf("%s, ",tmp->word);
                tmp=tmp->next;
            }
            printf("\n");
            }


    }*/
    generate_text("wiekszy_wynik.txt",tab,GRAMS,50);
    printf("%d",tab[0]->size);
   /* for(;i<TAB_SIZE;i++){
        if(tab[i]->size != 0){
            printf(" tab[%d]->size = %d\n",i,tab[i]->size);
            wypisz(tab,i);
        }
    }*/
   /* for(i= 0; i<10000;i++){
        get_word_random(tab,99881);
    }*/


return 0;
}

