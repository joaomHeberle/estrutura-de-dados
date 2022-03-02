//atividade6
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct
{ int idade;
char nome[100];
}Cpessoa ;

int main()
{
//pessoa p[10];
//p[1].idade = 30;
//strcpy(p[1].nome,"Lucas");
//p[2].idade = 21;
//strcpy(p[2].nome,"Joao");
//p[3].idade = 10;
//strcpy(p[3].nome,"Alberto");
//p[4].idade = 40;
//strcpy(p[4].nome,"Francis");
//printf("\n%d - %s", p[1].idade, p[1].nome);
//printf("\n%d - %s", p[2].idade, p[2].nome);
//printf("\n%d - %s", p[3].idade, p[3].nome);
//printf("\n%d - %s", p[4].idade, p[4].nome);
int i;
int tam=0;
 Cpessoa aluno;
Cpessoa *paluno;
paluno = &aluno;
paluno = (struct Cpessoa *) malloc(sizeof(paluno));

strcpy((*paluno).nome, "Janice");
(*paluno).idade = 22;

strcpy((*(paluno+1)).nome, "Julia");
(*(paluno+1)).idade = 22;

strcpy((*(paluno+2)).nome, "Augusto");
(*(paluno+2)).idade = 23;

strcpy((*(paluno+3)).nome, "Alberto");
(*(paluno+3)).idade = 24;

strcpy((*(paluno+4)).nome, "miguel");
(*(paluno+4)).idade = 24;
strcpy((*(paluno+5)).nome, "jose");
(*(paluno+5)).idade = 24;

strcpy((*(paluno+6)).nome, "jc");
(*(paluno+6)).idade = 24;
strcpy((*(paluno+7)).nome, "xzx");
(*(paluno+7)).idade = 24;
strcpy((*(paluno+8)).nome, "s");
(*(paluno+8)).idade = 24;
for (int i = 0; i<9 ; ++i)
{

printf("%s - %d \n", (*paluno).nome, (*paluno).idade);
printf("%s - %d \n", paluno->nome, paluno->idade);
paluno++;
}
getchar();
free(paluno);

system("pause");
return 0;
};
