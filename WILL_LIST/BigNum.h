
// Estruturas  //

typedef struct Celula* Apontador;

typedef struct Celula
{
 int Casa;
Apontador prox;
Apontador ante;
}TipoCelula;


typedef struct
{
char sinal;
Apontador primeiro;
Apontador ultimo;
}BigNum;




// Funcoes e Procedimentos  //
int ComparaBigNum(BigNum a, BigNum b);
void ShiftDireita(BigNum* a, int quantidade);
void ShiftEsquerda(BigNum* a, int quantidade);
void IgualaDigitosBigNum(BigNum a, BigNum b);
int ContaDigitoBigNum(BigNum a);
int ContaDigito(int i);
void FBigNumVazia(BigNum *lista); //Cria uma lista encadeada vazia.
void InsereNoBigNum(BigNum* lista , int digito);
void RetiraPrimeiro(BigNum *a);

BigNum criar(int num);
void destruir(BigNum *a);

BigNum somar(BigNum a, BigNum b);
BigNum subtrair(BigNum a, BigNum b);
BigNum multiplica (BigNum a, BigNum b);
BigNum dividir(BigNum a, BigNum b);
void imprimir();
BigNum Fatorial(int n);
void inverte(int *num); // Inverte um inteiro.
void imprimenormal();
int ProcessaSinal(BigNum a, BigNum b);
int LeLinhasEntrada();
