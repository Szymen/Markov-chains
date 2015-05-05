#include "assoc_tab.h"
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include<time.h>

int process_text(char* in_name,assoc_tab* tab[],int grams){

    FILE *in=fopen(in_name,"r");
    if(in==NULL){printf("Couldn`t open file to process.\nGood luck next time!\n"); return; }
    int i,first_hash;
    char **tmp=malloc(sizeof(char)*(grams+1));

    for(i=0;i<=grams;i++){
        tmp[i]=malloc(sizeof(char)*50);
    }

    for(i=0;i<=grams;i++){ /*generowanie pierwszego hasha*/
        fscanf(in,"%s",tmp[i]); /*wczytuje gram+1 slow */
    }

    first_hash=hash_val(tmp,grams);         /*wyliczenie wartosci pierwszego i przesuniecie slow- przygotwanie do wczytania kolejnego */
    assoc_push(tab[first_hash],tmp[grams]);
    for(i=1;i<=grams;i++){
            strcpy(tmp[i-1],tmp[i]);
        }

    while(fscanf(in,"%s",tmp[grams])!=EOF)
    {
            assoc_push(tab[hash_val(tmp,grams)],tmp[grams]);                            /*wrzucanie do tablicy przejsc */
                for(i=1;i<=grams;i++){
            strcpy(tmp[i-1],tmp[i]);
        }
    }
    return first_hash;
}

void generate_text(char* out, assoc_tab* tab[], int hash_size,int grams,int dlugosc){

    int i;
    int act_size=0;
    int hash;
    int numerek;

    char *word;
    word=malloc(sizeof(char)*50);
    char* act_hash_word[grams];
    for(i=0;i<grams;i++){
        act_hash_word[i]=malloc(sizeof(char)*50);
    }


    srand(time(NULL));

    while(1){
    //printf("a");              //losujemy początkowy hash :D
    hash=rand()%hash_size;
    if(tab[hash]->size!=0){break;}
    srand(hash);
    }

srand(time(NULL));
printf("Wybrano początkowy hash jako %d, mozliwosci tam jest %d\n",hash,tab[hash]->size);
numerek=(rand()%tab[hash]->size)+1;
word=get_word_by_id(tab[hash]->possible,numerek);

printf("Wylosowane slowo :  %s , z numerka : %d \n", word, numerek);
printf("Wylosowane slowo :  %s , z numerka : %d \n", get_word_by_id(tab[hash]->possible,numerek), numerek);


    FILE *outfile=fopen(out,"w");


/*
    while(act_size<dlugosc){

//        word=get_word_by_id();
  //      fprintf(outfile,"%s ",)

    word=get_word_by_id(tab[hash]->possible,(rand()%tab[hash]->size)+1);


//    hash=hash_val(act_hash_word,grams);

    fprintf(outfile,"%d to jest sajz!\n",act_size);
    act_size++;
    }
*/
    fclose(outfile);
    printf("Wygenerowalismy!\n");

}
