#include <stdio.h>
#include <stdlib.h>
typedef struct lista  Lista;

struct lista
{
       int valor;
       struct lista * proximo;
       };


Lista * cria_lista(void)
{
 return (NULL);
}
int tam =0;

FILE *txt;
char arquivo[] ="arquivos_numeros.txt";

void bublesort(Lista * l)

{
    Lista * novo = (Lista *) malloc (sizeof(Lista));

            int i, j = 0,  aux;
Lista *prev, *current;

            while (j < tam)

            {



                        for(i = 0; i < tam-1; i++)
                                    prev = l;
                                    current = l->proximo;

                                   if(prev->valor > current->proximo)

                                   {

                                               aux=novo->valor;

                                               novo->valor = novo->proximo;

                                               novo->proximo = aux;

                                   }

                        j++;



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

        while (!feof(txt)) {

               fscanf(txt, "%d", &Aux_num);
               l = set_lista(l,Aux_num);

            }

          fclose(txt);
      }

return(l);
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
printf("inicio do Programa\n");

Lista * lis = cria_lista();

verifica_lista(lis);

lis=ler_Arquivo(lis);

view_lista(lis);

free_lista(&lis);

system("pause");


}
