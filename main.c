#include<stdio.h>
#include<stdlib.h>
#include "text.h"
#include "hash.h"
/*#include "linked_list.h" zainkludowane w assoc_tab ^-^  */
/*#include "assoc_tab.h"  jest w text.h */

int main()
{
    /*node* lista;
    char* test="Foo";
    char* test2="Bar";
    char* test3="Baz";
    char* test4="Qux";
    char* test5="Norf";
    lista=malloc(sizeof(node));
    list_push(test,lista);
    list_push(test2,lista);
    list_push(test3,lista);
    list_push(test4,lista);
    list_push(test5,lista);
    i=0;
    while(lista->next!=NULL){
        printf("%d Slowo : %s\n",i++,lista->word);
        lista=lista->next;
    }
    */
    /*
    char* test="Foo";
    char* test2="Bar";
    char* test3="Baz";
    char* test4="Qux";
    char* test5="Norf";
    assoc_tab tab[100];
    assoc_tab tab2[100];
    assoc_tab *tab3[12];

    for(i=0;i<12;i++){tab3[i]=malloc(sizeof(assoc_tab));}
    for(i=0;i<12;i++){
        printf("tab3[%d]->size = %d\n",i,tab3[i]->size);
    }

    assoc_push(tab3[2],test);
  printf("\n\n");
  for(i=0;i<12;i++){
        printf("tab3[%d]->size = %d\n",i,tab3[i]->size);
    }
  printf("%s",tab3[2]->possible->word);
    assoc_push(tab3[2],test2);
    assoc_push(tab3[2],test);
    assoc_push(tab3[2],test);
      printf("\n\n");
  for(i=0;i<12;i++){
        printf("tab3[%d]->size = %d\n",i,tab3[i]->size);
    }
*/
/*

    assoc_tab *tab3[12];
    for(i=0;i<12;i++){tab3[i]=malloc(sizeof(assoc_tab));}
    assoc_push(tab3[2],test);
    assoc_push(tab3[2],test2);
    assoc_push(tab3[2],test);
    assoc_push(tab3[2],test);
    for(i=0;i<tab3[2]->size;i++)printf("W tab3[2] slowo nr : %d to : %s\n",i,get_word_by_id(tab3[2]->possible,i));
*/

   /* for(i=0;i<10;i++){
        printf("Tab[%d] size : %d , possibilities ",i,tab[i]->size);
        if(tab[i]->possible==NULL){
            printf("(null)\n");
        }
        else printf("cos jest\n");
    }*/
   /* for(j=0;j<4;j++){for(i=0;i<100000;i++){
        assoc_push(tab[i],test);
    }}
    */
   // write_trans_to_file("duzo.txt",tab,100000);
/*
        for(i=0;i<10;i++){
        printf("Tab[%d] size : %d , possibilities ",i,tab[i]->size);
        if(tab[i]->possible==NULL){
            printf("(null)\n");
        }
        else printf("cos jest\n");
    }
    make_trans_from_file("duzo.txt",tab);
    for(i=0;i<10;i++){
        printf("Tab[%d] size : %d , possibilities ",i,tab[i]->size);
        if(tab[i]->possible==NULL){
            printf("(null)\n");
        }
        else printf("cos jest\n");
    }
    */


    int i,j;

    int TAB_SIZE=100009;
    assoc_tab *tab[TAB_SIZE];
    assoc_initialize(tab,TAB_SIZE);

    int licznik1=0;
    int licznik=0;
    process_text("odyseja.txt",tab,3);
    for(i=0;i<100009;i++){
        if(tab[i]->size==1){licznik1+=1;}
        //printf("%d. ilosc nastepnikow : %d\n",i,tab[i]->size);}
        if(tab[i]->size>0){licznik++;}
    }
    printf("Ogolem niezerowych : %d, w tym pojedynczych : %d, czyli reszty zostaje : %d\n",licznik, licznik1, licznik-licznik1);
    generate("dupa.txt",tab,TAB_SIZE,3,10);

return 0;
}
