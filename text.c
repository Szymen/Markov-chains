#include "assoc_tab.h"
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include<time.h>

void process_text(char* in_name,assoc_tab* tab[],int grams){

//    printf("Wykorzystujemy %d-gramy\n",grams);
    int i;
    char **words;
    words=malloc(sizeof(char)*grams*40);           /*tu tworzymy szerokosc tablicy */
    for(i=0;i<grams;i++){                       /*a tu konkretne komorki na slowa  */
        words[i]=malloc(sizeof(char)*40); /*maksymalnie 40 znakowe słowa ^-^  */
    }
    char* tmp;
    tmp=malloc(sizeof(char)*40);
//    printf("Zadano z pliku : %s\n",in_name);
    FILE *in=fopen(in_name,"r");
    if(in==NULL){
        printf("Couldn`t open file to process.\n");
        return; /*skoncz dzialanie*/
    }
    while(fscanf(in,"%s",tmp)!=EOF){
//        printf("Wczytano : %s\n",tmp);
    strcpy(words[grams-1],tmp);

//        for(i=0;i<grams;i++){
//          printf("words[%d]= \"%s\" ",i,words[i]);
//       }
        assoc_push(tab[hash_val(words,grams)],tmp);/* <---------------------------- hash!*/
        for(i=0;i<grams-1;i++){     // przepisujemy
            strcpy(words[i],words[i+1]);
        }
//        printf("\n\n");
    }
    fclose(in);
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
