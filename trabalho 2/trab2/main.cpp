#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <pilha.h>
#include <fila.h>
int main(void)
{
Pilha * pil = pilha_cria();
ler_Arquivo_Pil(pil);
Fila *FILA = (Fila *) malloc(sizeof(Fila));


 if(!FILA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(FILA);
 ler_Arquivo(FILA);
 int opt;

 do{
  opt=menu();
  opcao(pil,FILA,opt);
 }while(opt!=7);

 free(FILA);
 return 0;
 }
}

int menu(void)
{
 int opt;


 printf("[1] - Cadastrar Clientes\n");
 printf("[2] - Visualizar Clientes\n");
 printf("[3] - Cadastrar Carro no Estoque\n");
 printf("[4] - Visualizar Carros no Estoque\n");
 printf("[5] - Entregar Carro/Cliente\n");
 printf("[6] - Gerar arquivo de Clientes Ordenado (Nome)\n");
 printf("[7] - Sair\n");

 printf("Opcao: "); scanf("%d", &opt);
system("cls");
 return opt;
}

void opcao(Pilha *pil,Fila *FILA, int op)
{Fila *tmp;

 switch(op){

  case 1:
        recCliente();
        insere(FILA);
        txtCliente(FILA);
   break;

  case 2:
     exibe(FILA);
   break;

  case 3:
recPIL();
    push(pil);

    salvarTXT(pil);
    system("cls");
   break;
   case 4:
 pilha_imprime(pil);

   break;
   case 5:
    EntregarCarroCliente(pil,FILA);

   break;
   case 6:


   break;
  case 7:
    libera(FILA);
    pilha_libera(pil);
 break;

  default:
   printf("Comando invalido\n\n");
 }
}


void EntregarCarroCliente(Pilha *pil,Fila *FILA){
     Fila *tmp;
     Lista *tp;
    int verifica=0;



 if(vazia(FILA))
    {
        printf("Nao ha clientes!\n\n");
        verifica++;
    }

if (pilha_vazia (pil))
     {
         printf ("Nao ha carros!\n\n");
         verifica++;
     }
     if(!verifica){


        tmp= retira(FILA);
            if(tmp != NULL)
                {
                    printf("O Cliente: %s CPF: %s e telefone: %s\n", tmp->nome,tmp->cpf,tmp->telefone);
                    free(tmp);

                }
  tp=pop(pil);
    if(tp != NULL)
                {
                    printf("Comprou o carro: %s Chassi: %s de cor: %s\n", tp->modelo,tp->chassi,tp->cor);
                    free(tp);

                }
txtCliente(FILA);
salvarTXT(pil);
}
system("pause");
system("cls");
}


