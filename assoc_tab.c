#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "assoc_tab.h"



void assoc_push(assoc_tab* where, char *word){

//    printf("W assoc_pushu dorzucono : %s\n",word);
    if(where->possible==NULL){where->possible=malloc(sizeof(node));}
	where->size++;
	list_push(word,where->possible);

}

char* get_word_by_id(node* first,int number){

    if(first == NULL){return "(null)";}
    if (number == 0){return first->word;}
    number--;
    while(number--){
        if(first==NULL){return "(null)";}
        first=first->next;

    }
    return first->word;
}
char *get_word_random(assoc_tab *tab[],int hash){
    if(tab[hash]->size == 0){return "";}
    unsigned int wyrandowany = 0;
    srand(hash*time(NULL));
    wyrandowany = rand() % tab[hash]->size;
    /*printf("Chcesz otrzymac z hasha : %d\n",hash);
    printf("Size w funkcji : %d\nNastepniki w funkcji : ",tab[hash]->size);*/
    node *pom = malloc (sizeof (node));
    pom = tab[hash]->possible;
    //while(pom){
        //printf("%s ", pom->word);
      //  pom=pom->next;
    //}
    /*printf("\nWyrandowany indeks to : %d\n",wyrandowany);*/
    pom = tab[hash]->possible;
    while(wyrandowany--){
        pom = pom->next;
    }

    return pom->word;

}




void make_trans_from_file(char* out_file, assoc_tab *where[]){
    int size,assoc_size,i,j;
    char *tmp;
    int k;
    tmp=malloc(sizeof(char)*100);
    int dud;
    FILE *in=fopen(out_file,"r");
    fscanf(in,"%d",&assoc_size);
    for(i=0;i<assoc_size;i++){

        fscanf(in,"%d",&size);
        while(size--){
            fscanf(in,"%s ",tmp);
//            printf("Dodaje : %s\n",tmp);
            assoc_push(where[i],tmp);
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


void assoc_initialize(assoc_tab *what[],int t_width){
    int i;
    for(i=0;i<t_width;i++){
        what[i]=malloc(sizeof(node));
    }

}




