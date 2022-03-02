#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct{
char nome[40];
int matricula;
float n1;
float n2;
float n3;
float n4;
float media;

}Saluno;
Saluno aluno;
Saluno *paluno;

int tam,aux_matr;
int vet;
int vetA;
float aux_n1,aux_n2,aux_n3,aux_n4,aux_media;
int ver_mat=0;
int anda;
char Aux_nome[50],name[50];
char arquivo[]="notasAlunos.txt";
Saluno *rea = NULL;
FILE *txt;
vetA=0;
vet=1;
tam=1;

//funções
float calc_media(float v1,float v2,float v3,float v4){
float media;

media=(v1+v2+v3+v4)/4;

return media;

}
int verifica_Matricula(int valor){

    int contMat=1;
    int aux_mat2;
    aux_mat2=(int)valor;

while(( aux_mat2=aux_mat2/10)>0){
    contMat++;
    }
if(contMat==4){

    return 1;
}else{
    printf("digite uma matricula com 4 numeros que nao comece com 0 ex:1000\n");

    return 0;
}

}

void cadastra_Aluno(Saluno* aluno){

float media;
int aux_mat=1;
printf("digite um nome: ");
gets(Aux_nome);
strcpy(aluno[vetA].nome, Aux_nome);


while(ver_mat!=2){
        printf("digite a matricula: ");
scanf("%d",&aux_mat);

ver_mat=verifica_Matricula(aux_mat);
if(ver_mat==1){
    aluno[vetA].matricula=aux_mat;
    break;
}else{
    continue;
}
}

printf("digite a nota1: ");
scanf("%f",&aluno[vetA].n1);
printf("digite a nota2: ");
scanf("%f",&aluno[vetA].n2);
printf("digite a nota3: ");
scanf("%f",&aluno[vetA].n3);
printf("digite a nota4: ");
scanf("%f",&aluno[vetA].n4);

media=calc_media(aluno[vetA].n1,aluno[vetA].n2,aluno[vetA].n3,aluno[vetA].n4);

aluno[vetA].media=media;

}

void ler_Arquivo(Saluno aluno[vet]){

    if((txt = fopen(arquivo,"r")) == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
 else
     {

        while (!feof(txt)) {

               fscanf(txt, "%s", Aux_nome);
               fscanf(txt, "%d %f %f %f %f %f ",&aux_matr,&aux_n1,&aux_n2,&aux_n3,&aux_n4,&aux_media);


               strcpy((aluno[vetA]).nome,Aux_nome);
               (aluno[vetA]).matricula=aux_matr;
               (aluno[vetA]).n1=aux_n1;
               (aluno[vetA]).n2=aux_n2;
               (aluno[vetA]).n3=aux_n3;
               (aluno[vetA]).n4=aux_n4;
               (aluno[vetA]).media=aux_media;

                vetA++;

              }

          fclose(txt);
      }


}

void salvarTXT(Saluno aluno[]){
    int i;

    if((txt = fopen(arquivo, "w")) == NULL) {
printf("Erro ao abrir arquivo");
}
else {

for(i=0;i!=vetA;i++){

fprintf(txt, "%s %d %0.2f %0.2f %0.2f %0.2f %0.2f\n", (aluno[i]).nome,(aluno[i]).matricula,(aluno[i]).n1,
        (aluno[i]).n2,(aluno[i]).n3,(aluno[i]).n4,(aluno[i]).media);
        }
}

fclose(txt);
printf("arquivo salvo com sucesso aperte enter para continuar");
getchar();
system("cls");
}
//\n

void pesquisar_Aluno(Saluno aluno[],char nome[200]){
    int i,existe;
    existe=0;
    char nam[200];

for(i=0;i!=vetA;i++){
strcpy(nam, (aluno[i]).nome);

    if(strcmp(nome,nam)==0){
   printf("Nome: %s\tMatricula: %d\t Nota 1: %0.2f\t Nota 2: %0.2f\t Nota 3: %0.2f\tNota 4: %0.2f\tMedia: %0.2f\n",(aluno[i]).nome,
          (aluno[i]).matricula,(aluno[i]).n1,(aluno[i]).n2,(aluno[i]).n3,(aluno[i]).n4,(aluno[i]).media);
            existe++;
            printf("Aperte enter para continuar");
            getchar();
          break;
    }

}
if(existe==0){
    printf("Nome nao encontrado!!!\n");
       printf("Aperte enter para continuar");
    getchar();

    system("cls");


}






}




//main



int main()
{
char nome[200];
if((txt = fopen(arquivo, "r")) != NULL){

char linha[200];
    while(!feof(txt)){
        fgets(linha, 1000, txt);
             vet++;

    }


fclose(txt);
}
paluno=&aluno;
paluno = (Saluno *) malloc(vet*sizeof(Saluno));

     if((txt = fopen(arquivo, "r")) != NULL)
   ler_Arquivo(paluno);

int opcao=0,i=0;



while(opcao!=4){
system("cls");
printf("///Lancamento de resultados ///\n");
printf("///                         ///\n");
printf("///Digite o numero da opcao:///\n");
printf("/// 1-Novo Registro         ///\n");
printf("/// 2-Salvar Arquivo        ///\n");
printf("/// 3-Pesquisar Aluno       ///\n");
printf("/// 4-Sair                  ///\n");
printf("///                         ///\n");
printf("///////////////////////////////\n");
scanf("%d",&opcao);
getchar();
system("cls");

switch (opcao) {

    case 1:{

  vet++;
    cadastra_Aluno(paluno);
    paluno = (Saluno *) realloc(paluno,vet*sizeof(Saluno));


        vetA++;
        break;
    }
    case 2:{

        salvarTXT(paluno);
        break;
    }
    case 3:
        printf("Digite o nome para pesquisar: ");
        gets(nome);
        pesquisar_Aluno(paluno,nome);
        break;
    case 4:


    break;
}



 }
system("pause");

return 0;

}

