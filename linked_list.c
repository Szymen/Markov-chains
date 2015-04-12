#include "linked_list.h"
#include <string.h>





void list_push(char *data,node* first){
	node *temp;
	temp= malloc(sizeof(node));
	if(temp==NULL){
		fopen("errors.log","w");
		fprintf("Couldn`t push sufix. Memory error.\n");
		fclose("errors.log");
	}
	strcpy(temp->word,data);
	
	while(first->next!=null){
		first=first->next;
		}
	
	first->next=temp;


}
