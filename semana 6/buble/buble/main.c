#include <stdio.h>
#include <stdlib.h>
typedef struct lista  Lista;

struct lista
{
       int valor;
       struct lista * proximo;
       };

Lista* elemento ( Lista *first, int pos );
Lista * cria_lista(void)
{
 return (NULL);
}
int tam =0;

FILE *txt;
char arquivo[] ="arquivos_numeros.txt";

void bubbleSort( Lista *primeiro ) {

     int i, j,aux;

     for( i = tam - 1; i >= 0; i-- ) {
          for( j = 1; j <= i; j++ ) {
               if(  elemento( primeiro, j - 1 )->valor > elemento( primeiro, j )->valor ) {
                    aux = elemento( primeiro, j - 1 )->valor;
                    elemento( primeiro, j - 1 )->valor = elemento( primeiro, j )->valor;
                    elemento( primeiro, j )->valor = aux;
               }
          }
     }
}

Lista *set_lista(Lista * l, int a)
{
 Lista * novo = (Lista *) malloc (sizeof(Lista));
 novo->valor = a;
 novo->proximo = l;
 tam++;
 return(novo);
}
Lista *ler_Arquivo(Lista * l){
    int Aux_num;

    if((txt = fopen(arquivo,"r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
   }
 else
     {

        while(fscanf(txt, "%d", &Aux_num) == 1) {

               l = set_lista(l,Aux_num);

            }

          fclose(txt);
      }

return(l);
}

Lista* elemento ( Lista *l, int pos ){

       if( pos > tam - 1 ) {
           return NULL;
       }

       int count = 0;
       Lista *aux = l;

       while ( count < pos ) {
             aux = aux->proximo;
             count++;
       }

       return aux;
}



void view_lista(Lista * l)
{
Lista * pl;
      for (pl = l; pl != NULL; pl = pl->proximo)
      {
          printf("Valor %d  \n", pl->valor);
      }
}


int verifica_lista(Lista * l)
{
if (l == NULL)
   printf("\nLista Vazia\n");
else
    printf("\nLista nao vazia\n");
}




void free_lista(Lista ** pl)
{
      while (*pl != NULL)
      {
           Lista * t = (*pl)->proximo;
           *pl = NULL;
           free(*pl);
           *pl = t;
      }
 }


main()
{



Lista * lis = cria_lista();

verifica_lista(lis);

lis=ler_Arquivo(lis);

view_lista(lis);

bubbleSort(lis);
printf("\n");
printf("valores ordenados\n");
view_lista(lis);


free_lista(&lis);

system("pause");


}
