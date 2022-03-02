#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

main()
{   char opcao[4];
    int op=0;
    int num=5;
    char bufnum[500];
    char nome[]= "joao";

    itoa(num,bufnum,10);

    strcat(nome,bufnum);

    printf("nome: %s",nome);
    char teste[500]="tem cachorro";
    printf("faça uma pergunta: ");
    gets(teste);
    while(op!=1&&op!=2){
        printf("\nescreva sim ou nao: ");
        gets(opcao);

        strupr(opcao);
        printf("opcao %s\n",opcao);


        if(!strcmp(opcao,"SIM")){

            op=1;
            printf("\nop %d\n",op);
        }else if(!strcmp(opcao,"NAO")){
            op=2;
         printf("\nop %d\n",op);
        }else{
            printf("\nescolha sim ou nao");
        }

    }

    char t[500]="tem gato";
    char te[500]="bisturi";
     Arvore * a = arvore_cria(teste);
      Arvore * c = arvore_cria(t);
     Arvore * x = arvore_cria(t);
    Arvore * b = arvore_cria(te);


     arvore_insere(a,x);
     arvore_insere(a,b);
      arvore_insere(b,c);

     arvore_imprime(a);

     printf("Altura: %d \n", arvore_altura(a));



     system("pause");

      }
