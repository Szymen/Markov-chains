#include "assoc_tab.h"
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include<time.h>

void process_text(char* in_name,assoc_tab* tab[],int grams){

    FILE *in=fopen(in_name,"r");
    if(in==NULL){printf("Couldn`t open file to process.\nGood luck next time!\n"); return -1; } //nie udalo sie otworzyc pliku

    int i,first_hash;
    char **tmp=malloc(sizeof(char)*(grams+1));

    for(i=0;i<=grams;i++){
        tmp[i]=malloc(sizeof(char)*50);
    }                                   // inicjowanie zmiennych

    fscanf(in,"%s",tmp[grams-1]);   //wczytujemy pierwsze słowo
    assoc_push(tab[0],tmp[grams-1]);    //wrzucamy to słowo pod indeksem 0 - od tego zaczniemy generowanie

    while(fscanf(in,"%s",tmp[grams])!=EOF)
    {
            assoc_push(tab[hash_val(tmp,grams)],tmp[grams]); /*wrzucanie do tablicy przejsc */
            for(i=1;i<=grams;i++){ strcpy(tmp[i-1],tmp[i]); } // przesuwanie slow, robienie miejsce na kolejne
    }
}


void generate_text(char* out, assoc_tab* tab[],int grams,int docelowa_dlugosc){

    int akt_dl = 0;
    int i;
    int akt_hash = 0;
    char **klucz = malloc (sizeof (char) * grams);
    for(i =0;i<grams;i++){
        klucz[i] = malloc (sizeof (char) * 50);
    }
    FILE*out_file = fopen (out,"wr");
                                    // pod indeksem 0 znajduje sie pierwsze slowo z tekstu.
    klucz[grams-1] = get_word_random(tab,0);


    while (akt_dl < docelowa_dlugosc){

        fprintf(out_file,"%s ",klucz[grams-1]);
        akt_hash = hash_val(klucz,grams);
        for( i=1 ; i < grams ; i++ ){
            klucz[i-1] = klucz[i];}
        klucz[grams-1] = get_word_random(tab,akt_hash);

        akt_dl++;
    }

    fclose(out_file);
}

