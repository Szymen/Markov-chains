

int hash_val(char *words[], int word_amount){

	unsigned int MULTIPLIER=33;
	unsigned int mod=10009;
	unsigned int hash_val=0;	
	for(i=0;i<word_amount;i++){
		for(j=0;j<tab[i][j]!=0;j++)
		{
			hash_val*=MULTIPLIER;
			hash_val+=words[i][j]-64;	
		}
	}

	return hash_val%mod;
}
