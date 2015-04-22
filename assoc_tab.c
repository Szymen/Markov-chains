#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "assoc_tab.h"



void assoc_push(assoc_tab* where, char *word){
    if(where->possible==NULL){where->possible=malloc(sizeof(node));}
	where->size++;
	printf("dodalem nowy! size: %d word: %s\n",where->size,word);
	list_push(word,where->possible);
}

char* get_word_by_id(node* first,int number){
    while(number--){
        first=first->next;
        if(first==NULL){return "";}
    }
    return first->word;
}



void make_trans_from_file(char* out_file, assoc_tab *where[]){
    int size,assoc_size,i,j;
    char *tmp;
    tmp=malloc(sizeof(char)*100);

    int dud;
    FILE *in=fopen(out_file,"r");
    fscanf(in,"%d",&assoc_size);
    for(i=0;i<assoc_size;i++){

        fscanf(in,"%d",&size);
        while(size--){
            fscanf(in,"%s ",tmp);
//            printf("Dodaje : %s\n",tmp);
            assoc_push(where[i],tmp); /*TODO cos nie dziala : ( ostatni wrzucony zaslania reszte : /  */
            strcpy(tmp, "");
        }
    }
    fclose(in);
}

void write_trans_to_file(char* out_file, assoc_tab *from[], int assoc_tab_size){
printf("write!\n");
    int i,j;
    FILE *out=fopen(out_file,"w");
    if(out==NULL){
        FILE *err=fopen("errors.log","a");	/*bedzie dopisywac do pliku*/
		fprintf(err,"Couldn`t write trans to file.\n");
		fclose(err);
    }
    fprintf(out,"%d\n", assoc_tab_size);
    for(i=0;i<assoc_tab_size;i++){
        fprintf(out,"%d",from[i]->size);
        for(j=0;j<from[i]->size;j++){
            fprintf(out," %s",get_word_by_id(from[i]->possible,j));
        }
        fprintf(out,"\n");
    }
    fclose(out);
}
