#include "linked_list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>




void list_push(char *data,node* first){
    while(first->next!=NULL){  // przewijamy do ostatniego
		first=first->next;
		}
    first->next=malloc(sizeof(node)); // tworzymy nowy wezel

    if(first->next==NULL){
        FILE *err=fopen("errors.log","a");	/*bedzie dopisywac do pliku*/
		fprintf(err,"Couldn`t push sufix. Memory error.\n");
		fclose(err);
		return ; // konczymy dzialanie funkcji
    };

    if(first->word==NULL){
        first->word=malloc(sizeof(char)*50);
        strcpy(first->word,data);
        //first->word=data;
        }
    else {//first->next->word=data;
        first->next->word=malloc(sizeof(char)*50);
        strcpy(first->next->word,data);
    }
//    printf("Koniec List_pusha\n");
}
