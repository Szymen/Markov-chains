#include "linked_list.h"
#include <string.h>





void push(char *data,node* last){
	node *temp;
	temp= malloc(sizeof(node));
	if(temp==NULL){
		fopen("errors.log","w");
		fprintf("Couldn`t push sufix. Memory error.\n");
		fclose("errors.log");
	}
	strcpy(temp->word,data);
	last->next=temp;


}
