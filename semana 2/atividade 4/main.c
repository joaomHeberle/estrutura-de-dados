//atividade 4
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

        if(l<(t/2)+1&&c<(t/2)+1||l>(t/2)-1&&c>(t/2)-1){
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
