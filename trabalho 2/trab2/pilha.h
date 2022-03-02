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
void EntregarCarroCliente(Pilha *pil,Fila *FILA);
