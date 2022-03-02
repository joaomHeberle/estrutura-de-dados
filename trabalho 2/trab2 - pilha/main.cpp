#include <stdio.h>
#include <stdlib.h>
#include <cstring>
typedef struct lista Lista;
struct lista {
char modelo[500];
char chassi[20];
char cor[100];
 struct lista * prox;
 };

typedef struct {
 Lista * prim;
 }Pilha;
struct fila
{
 char telefone[20];
 char nome[150];
 char cpf[20];
 struct fila *prox;
};
typedef struct fila Fila;
char arqCliente[]="clientes.txt";
FILE *txt;

char auxTelefone[20];
char auxNome[150];
char auxCpf[20];
int menu(void);
void opcao(Pilha *pil,Fila *FILA, int op);
void inicia(Fila *FILA);
int vazia(Fila *FILA);
//Fila *aloca();
void insere(Fila *FILA);
Fila *retira(Fila *FILA);
void exibe(Fila *FILA);
void libera(Fila *FILA);
void txtCliente(Fila * FILA);
void ler_Arquivo(Fila * FILA);
void recCliente();
void ler_Arquivo(Fila *FILA);
//pilha
char auxModelo[500];
char auxChassi[20];
char auxCor[100];
char arquivo[]="carros.txt";
FILE *txtCar;
//funções pilha
void recPIL();
Pilha* pilha_cria (void);
int pilha_vazia (Pilha* p);
void push (Pilha* p);
void pop( Pilha* p);
void pilha_libera (Pilha* p);
void pilha_imprime (Pilha* p);
void salvarTXT(Pilha * p);
void ler_Arquivo_Pil(Pilha *pil);
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
  printf("[8] - **teste apaga fila**\n");
  printf("[9] - **teste apaga pilha**\n");
 printf("Opcao: "); scanf("%d", &opt);
system("cls");
 return opt;
}

void opcao(Pilha *pil,Fila *FILA, int op)
{
 Fila *tmp;
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


   break;
   case 6:


   break;
  case 7:
    libera(FILA);
    pilha_libera(pil);
 break;
 case 8:
  tmp= retira(FILA);
   if(tmp != NULL){
    printf("Retirado: %3s\n\n", tmp->telefone);
    libera(tmp);
   }
      break;
       case 9:
    pop(pil);

           break;
  default:
   printf("Comando invalido\n\n");
 }
}

void inicia(Fila *FILA)
{
 FILA->prox = NULL;

}

int vazia(Fila *FILA)
{
 if(FILA->prox == NULL)
  return 1;
 else
  return 0;
}

Fila *aloca(char nome[150],char telefone[20],char cpf[20])
{
 Fila *novo=(Fila *) malloc(sizeof(Fila));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
strcpy(novo->nome,nome);
strcpy(novo->telefone,telefone);
strcpy(novo->cpf,cpf);

  return novo;
 }
}
void recCliente(){
getchar();
    printf("Digite o nome do cliente: ");
    fgets(auxNome,150,stdin);
    auxNome[strlen(auxNome)-1] = '\0';

    printf("Digite o CPF do cliente: ");
    fgets(auxCpf,20,stdin);
    auxCpf[strlen(auxCpf)-1] = '\0';

    printf("Digite o numero de telefone do cliente: ");
    fgets(auxTelefone,20,stdin);
    auxTelefone[strlen(auxTelefone)-1] = '\0';

}

void insere(Fila *FILA)
{
 Fila *novo=aloca(auxNome,auxTelefone,auxCpf);

    novo->prox = NULL;
        if(vazia(FILA))
            FILA->prox=novo;
        else{
            Fila *tmp = FILA->prox;
            while(tmp->prox != NULL)
            tmp = tmp->prox;
            tmp->prox = novo;
            }

}




void txtCliente(Fila * FILA){
  Fila *tmp;
        tmp = FILA->prox;
    if((txt = fopen(arqCliente, "w")) == NULL) {
      printf("Erro ao abrir arquivo");
    }
        else{
        while( tmp != NULL){

             fprintf(txt,"%s|",tmp->nome);
             fprintf(txt,"%s|",tmp->cpf);
             fprintf(txt,"%s\n",tmp->telefone);
             tmp = tmp->prox;
        }
    }
    fclose(txt);
}

Fila *retira(Fila *FILA)
{
 if(FILA->prox == NULL){
  printf("Fila ja esta vazia\n");
  return NULL;
 }else{
  Fila *tmp = FILA->prox;
  FILA->prox = tmp->prox;

  return tmp;
 }

}


void exibe(Fila *FILA)
{ system("cls");

 if(vazia(FILA)){
  printf("Fila vazia!\n\n");
  return ;
 }

 Fila *tmp;
 tmp = FILA->prox;
 printf("Clientes na fila de espera: \n");
 while( tmp != NULL){

  printf("Nome: %s ", tmp->nome);

  printf("CPF: %s ", tmp->cpf);

  printf("Telefone: %s \n", tmp->telefone);
  tmp = tmp->prox;
 }


 printf("\n\n");
}
void ler_Arquivo(Fila *FILA){
    char aux[500],*subNome,*subCpf,*subTelefone;
    int i=0,cont=0,j=0;
    if((txt = fopen(arqCliente,"r")) == NULL)
    {
       return;

    }
        else
     {

      while(fgets(aux, 1000, txt) != NULL){
        aux[strlen(aux)-1] = '\0';

        subNome= strtok(aux,"|");

        subCpf= strtok(NULL,"|");

        subTelefone= strtok(NULL,"|");

        if(subCpf==NULL)break;
        strcpy(auxNome,subNome);
        strcpy(auxCpf,subCpf);
        strcpy(auxTelefone,subTelefone);
//        printf("Nome aux: %s\n",auxNome);
//        printf("CPF aux: %s\n",auxCpf);
//        printf("Telefone aux: %s\n",auxTelefone);
        insere(FILA);


    }



}
     fclose(txt);
}

void libera(Fila *FILA)
{
 if(!vazia(FILA)){
  Fila *proxFila,
     *atual;

  atual = FILA->prox;
  while(atual != NULL){
   proxFila = atual->prox;
   free(atual);
   atual = proxFila;
  }
 }
}


//termina FILA cliente
// inicio pilha de carros
//inicio pilha
void recPIL()
    {
        getchar();
    printf("Digite o modelo do carro: ");
    fgets(auxModelo,500,stdin);
    auxModelo[strlen(auxModelo)-1] = '\0';

    printf("Digite o numero do chassi: ");
    fgets(auxChassi,20,stdin);
    auxChassi[strlen(auxChassi)-1] = '\0';

    printf("Digite a cor do carro: ");
    fgets(auxCor,100,stdin);
    auxCor[strlen(auxCor)-1] = '\0';


    }


 Pilha* pilha_cria (void) {
 Pilha* p = (Pilha*)malloc(sizeof(Pilha));
 p->prim = NULL;
 return p;
 }


 int pilha_vazia (Pilha* p)
 {
   return (p->prim == NULL);
 }




 void push (Pilha* p){
 Lista *n = (Lista *) malloc (sizeof(Lista));
 strcpy(n->modelo,auxModelo);
 strcpy(n->chassi,auxChassi);
 strcpy(n->cor,auxCor);
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
        v = t->modelo;
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

printf("Modelo:%s\nChassi:%s\nCor:%s\n\n",q->modelo,q->chassi,q->cor);


}
void salvarTXT(Pilha * p){

    Lista* q;

    if((txtCar = fopen(arquivo, "w")) == NULL) {
        printf("Erro ao abrir arquivo");
    }
        else{

                for ( q=p-> prim; q!= NULL; q=q-> prox){

                    fprintf(txtCar,"%s|",q->modelo);
                    fprintf(txtCar,"%s|",q->chassi);
                    fprintf(txtCar,"%s\n",q->cor);
                }
        }
        fclose(txtCar);
}


void ler_Arquivo_Pil(Pilha *pil){

    char aux[500],*subModelo,*subChassi,*subCor,teste,c;
    int i=0,cont=0,j=1,auxcont,conta=0, auxConta=0;
    Lista* lis;
    teste='\n';
    if((txtCar = fopen(arquivo,"r")) == NULL)
    {
       return;

    }
        else
     {
         while(fgets(aux, 1000, txtCar) != NULL)
        cont++;

        rewind(txtCar);
auxcont=cont;

while((c = getc(txtCar) ) != EOF){ conta++;}


  rewind(txtCar);
while((c = getc(txtCar) ) != EOF){
    if(auxConta==conta-1){

        break;
    }
auxConta++;

}

  rewind(txtCar);


      while(fgets(aux, 1000, txtCar) != NULL)
      {
            i++;
            if(i==auxcont&&auxcont!=0)
            {



                    if(j>1){
                    aux[strlen(aux)-1] = '\0';

                    }else if(c==10&&j==1){
                        aux[strlen(aux)-1] = '\0';
                        }
                        else if(c!=10&&j==1){

                }

                    subModelo= strtok(aux,"|");

                    subChassi= strtok(NULL,"|");

                    subCor= strtok(NULL,"|");

                        if(subChassi==NULL)break;
                    strcpy(auxModelo,subModelo);
                    strcpy(auxChassi,subChassi);
                    strcpy(auxCor,subCor);
                    push(pil);


rewind(txtCar);

      rewind(txtCar);
auxcont--;
j++;
i=0;
            }


        }


    }
     fclose(txtCar);
}


