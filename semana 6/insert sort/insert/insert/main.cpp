#include <stdio.h>
#include <stdlib.h>
typedef struct lista  Lista;

struct lista
{
       int valor;
       struct lista * proximo;
       };
void insertSort(Lista *l);
Lista* elemento ( Lista *first, int pos );
Lista * cria_lista(void)
{
 return (NULL);
}
int tam =0;

FILE *txt;
char arquivo[] ="arquivos_numeros.txt";




Lista* cria (int v)
{
 Lista* p = (Lista*) malloc(sizeof(Lista));
 p->valor = v;
 return p;
}

Lista* insere_ordenado (Lista* l, int v)
{
 Lista* novo = cria(v);
 Lista* ant = NULL;
 Lista* p = l;

 while (p != NULL && p->valor < v) {
 ant = p;
 p = p->proximo;
 }

 if (ant == NULL) {
 novo->proximo = l;
 l = novo;
 }
 else {
 novo->proximo = ant->proximo;
 ant->proximo = novo;
 }
 return l;
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


for(int i =33;i<200;i+=2){
lis = insere_ordenado(lis,i);
}
view_lista(lis);
for(int i=10; i>0;i--){
lis = insere_ordenado(lis,i);
}

view_lista(lis);


printf("\n");
printf("valores ordenados\n");
view_lista(lis);

free_lista(&lis);

system("pause");


}
