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

void inicia(Fila *FILA);
int vazia(Fila *FILA);
Fila *aloca(char nome[150],char telefone[20],char cpf[20]);
void insere(Fila *FILA);
Fila *retira(Fila *FILA);
void exibe(Fila *FILA);
void libera(Fila *FILA);
void txtCliente(Fila * FILA);
void ler_Arquivo(Fila * FILA);
void recCliente();
void ler_Arquivo(Fila *FILA);


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
  printf("Nao ha clientes\n");
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

  printf("Telefone: %s \n\n", tmp->telefone);
  tmp = tmp->prox;
 }


 printf("\n\n");
 system("pause");
system("cls");
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

