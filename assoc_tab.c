#include<stdio.h>
#include "linked_list.h"
#include "assoc_tab.h"






void assoc_push(assoc_tab* where, char *word){
	
	where->size++;
	list_push(word,where->possible);
}


char* get_by_hash(int hash_val, int number){return "lul";};

void make_trans_from_file(FILE *in, assoc_tab *where,int assoc_tab_size ){printf("make!");};

void write_trans_to_file(FILE *out, assoc_tab * from, int assoc_tab_size){printf("write!");};
