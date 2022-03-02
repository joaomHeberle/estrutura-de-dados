//atividade 3
#include <stdio.h>
#include <stdlib.h>
#define t 7
int main()
{
   char *matriz[t][t];
    int l,c;
    l=0;
    c=0;

do{
    for(l=0;l<t;++l){

        if(l>c||l==c){
            matriz[l][c]="X";
        }
        else
        {
            matriz[l][c]="-";

        }
            printf("%s",matriz[l][c]);
        }
            printf("\n");

        c++;



 }while(c<t);

    return 0;
}
