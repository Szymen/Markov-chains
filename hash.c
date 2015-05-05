#include "hash.h"

int hash_val(char *words[], int word_amount){
    int k;

//    printf("\nWywolano hash_val %d slow : ",word_amount);
//    for(k=0;k<word_amount;k++){printf("\"%s\", ",words[k]);}
//printf("\n");

	unsigned int MULTIPLIER=33;
	unsigned int mod=100009;
	unsigned int hash_val=0;
	int i,j;
	for(i=0;i<word_amount;i++){
		for(j=0;words[i][j]!=0;j++)
		{
			hash_val*=MULTIPLIER;
			hash_val+=words[i][j]-64;
		}
	}
//    printf("Wartosc hasha : %d\n",hash_val%mod );
	return hash_val%mod;
}
