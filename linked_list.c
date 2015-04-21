#include "linked_list.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>




void list_push(char *data,struct node* first){
	struct node* temp;
	temp= malloc(sizeof(struct node));
	if(temp==NULL){
		FILE *err=fopen("errors.log","a");	/*bedzie dopisywac do pliku*/
		fprintf(err,"Couldn`t push sufix. Memory error.\n");
		fclose(err);
	}
	strcpy(temp->word,data);
	
	while(first->next!=NULL){
		first=first->next;
		}
	
	first->next=temp;


}
