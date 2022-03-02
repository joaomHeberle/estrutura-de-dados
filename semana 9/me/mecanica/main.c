#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista {
char info[500];
 struct lista * prox;
 }Lista;

typedef struct {
 Lista * prim;
 }Pilha;


char arquivo[]="processo.txt";
FILE *txt;

 Pilha* pilha_cria (void) {
 Pilha* p = (Pilha*)malloc(sizeof(Pilha));
 p->prim = NULL;
 return p;
 }


 int pilha_vazia (Pilha* p)
 {
   return (p->prim == NULL);
 }




 void push (Pilha* p, char* v){
 Lista *n = (Lista *) malloc (sizeof(Lista));
 strcpy(n->info,v);
 n->prox = p->prim;
 p->prim = n;

}



void pop( Pilha* p)
{
Lista * t;
char *v;
if (pilha_vazia (p))
     {
         printf ("Pilha esta vazia!\n");
     }
     else
     {
       t = p->prim;
        v = t->info ;
       p->prim = t->prox;
        printf("Proximo passo: %s\n",v );
       free(t);


      }
 }


  void pilha_libera (Pilha* p)
 {
 Lista * q = p->prim;
 while (q!= NULL)
 {
  Lista * t = q->prox;
  free(q);
  q=t;
 }
free(p);
 }
void pilha_imprime (Pilha* p)

{
Lista* q;
for ( q=p-> prim; q!= NULL; q=q-> prox)

printf("%s\n",q-> info);

}
void salvarTXT(Pilha * p){

    Lista* q;

    if((txt = fopen(arquivo, "w")) == NULL) {
        printf("Erro ao abrir arquivo");
    }
        else{

                for ( q=p-> prim; q!= NULL; q=q-> prox){

                    fprintf(txt,"%s\n",q-> info);
                }
        }
        fclose(txt);
}





void ler_Arquivo(Pilha * p){
    char informa[500],aux[500],vet[200][500];


    int i=0;
    if((txt = fopen(arquivo,"r")) == NULL)
    {
       return;

    }
        else
     {

       while(fgets(informa, 500, txt) != NULL){
            strcpy(vet[i],informa);
            vet[i][strlen(vet[i])-1] = '\0';
                i++;

              }

              while(i>0){

                  strcpy(aux,vet[i-1]);
                push(p,aux);
                i--;

              }

      }
     fclose(txt);
}
main()
{

char passos[500];
int opc;
Pilha * pil = pilha_cria();
ler_Arquivo(pil);

    while (opc!=3){
            printf("escolha uma opcao:\n 1 para adicionar, 2 para excluir e visulaizar ou 3 para sair:\n ");
scanf("%d",&opc);
getchar();
system("cls");
switch(opc){
case 1: printf("digite uma instrucao para adicionar: ");
fgets(passos,500,stdin);
passos[strlen(passos)-1] = '\0';
push(pil,passos);
salvarTXT(pil);
system("cls");
break;
case 2:
    pop(pil);
    salvarTXT(pil);
    getchar();
    system("cls");
    break;
case 3:
    pilha_libera(pil);
    exit(0);
    default: printf("digite uma opcao valida!!!\n");
}

}

system("pause");


}
