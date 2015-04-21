#include<stdio.h>
#include<stdlib.h>

#include "hash.h"
/*#include "linked_list.h" zainkludowane w assoc_tab ^-^  */
#include "assoc_tab.h"

int main()
{
    int i;
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


printf("Main !\n");
return 0;
}
