//atividade7
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct
{ int idade;
char nome[100];
}Cpessoa ;

int main()
{

int i,p;
int age=0;
char name[200]="";
char opcao[3]="";
i=p=0;
Cpessoa aluno;
Cpessoa *paluno;
paluno = &aluno;
paluno = (struct Cpessoa *) malloc(sizeof(paluno));
printf("%d",paluno);
do{
    printf("Inserir Novo: Sim/Nao\n");
    gets(opcao);
    strupr(opcao);
    if(strcmp(opcao,"SIM")==0){
        printf("digite um nome: ");
        gets(name);
        strcpy((*(paluno+p)).nome, name);
        printf("digite uma idade: ");
        scanf("%d",&age);
        getchar();
        (*(paluno+p)).idade = age;
        printf("nome: %s\n",name);
        p++;
    }else if(strcmp(opcao,"NAO")!=0){
    printf("Apenas Sim ou Nao\n");

    }
}while (strcmp(opcao,"NAO"))
    ;

for (i = 1; i<=p ;i++)
{
printf("%s - %d \n", paluno->nome, paluno->idade);
paluno++;

}

paluno=paluno-p;
printf("%d",paluno);
system("pause");
free(paluno);
return 0;
};

