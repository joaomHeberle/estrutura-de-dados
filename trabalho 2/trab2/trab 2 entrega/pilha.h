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
Lista* pop( Pilha* p);
void pilha_libera (Pilha* p);
void pilha_imprime (Pilha* p);
void salvarTXT(Pilha * p);
void ler_Arquivo_Pil(Pilha *pil);




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


Lista* pop( Pilha* p)
{
Lista * t;

if (pilha_vazia (p))
     {
         printf ("Nao ha carros!\n");
     }
     else
     {
       t = p->prim;

       p->prim = t->prox;
       return t;
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
if (pilha_vazia (p))
     {
         printf ("Nao ha carros!\n\n");
     }else{
for ( q=p-> prim; q!= NULL; q=q-> prox)

printf("Modelo:%s Chassi:%s Cor:%s\n\n",q->modelo,q->chassi,q->cor);

system("pause");
system("cls");
}
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

