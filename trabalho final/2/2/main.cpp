#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <locale.h>



typedef struct tree
{
char per[500] ;
  struct tree* sad;
  struct tree* sae;
} Arvore;
int cont;
Arvore* criaArvore();
void insereNaArvore(Arvore** t, char per[500],int op);
Arvore* criaArvore()
{

  return NULL;
}


void insereNaArvore(Arvore** t, char per[500],int op)
{

  if(*t == NULL)
  {
    *t = (Arvore*)malloc(sizeof(Arvore));
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    strcpy((*t)->per , per);

  } else {
    if(op==1)
    {
   
        cont++;
      insereNaArvore(&(*t)->sae, per,op);
    }
    if(op==2)
    {
      
        cont++;
      insereNaArvore(&(*t)->sad, per,op);

    }
  }
}



    
int main()
{
    cont=0;
    setlocale(LC_ALL, "Portuguese");
    char opcao[4];
    int i=0;
    char pergunta[500];
    char teste[500]="tem cachorro";
	char n;
    int op=0;
    Arvore* t = criaArvore(); 
    printf("Aperte enter para começar");
    getchar();
   
    while(strcmp(opcao,"SIM")){
    printf("\nFaça uma pergunta: ");
    gets(teste);
    while(op!=1&&op!=2){
        printf("\nsim ou nao: ");
        gets(opcao);
        strupr(opcao);



        if(!strcmp(opcao,"SIM")){

            op=1;
         
             insereNaArvore(&t, teste,op);
             
        }else if(!strcmp(opcao,"NAO")){
            op=2;
         
          insereNaArvore(&t, teste,op);
        }else{
            printf("\nOpção incorreta escolha sim ou nao");
        }

    }
i++;
op=0;
if(!strcmp(opcao,"SIM")){

printf("sua resposta %s :",teste);
gets(opcao);
   strupr(opcao);
   
   
   }
   
  

     
}





  free(t);

  return 0;
}
