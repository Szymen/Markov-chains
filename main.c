#include<stdio.h>

#include "hash.h"

int main()
{
int a;
int i;
char*tab[3];
tab[0]="ala";
tab[1]="ma";
tab[2]="kota";
for(i=1;i<3;i++)
{
a=hash_val(tab,i);
printf("%d hash_val =  %d\n",i, a);

}




printf("Hello!\n");
return 0;
}
