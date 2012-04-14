#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "BigNum.h"

int LeLinhasEntrada(FILE* fp){
  int ch;
  int linhas = 0;
  while( ch = fgetc(fp) != EOF){
    printf("%d",ch);
    if(ch == '\n'){
      linhas++;
    }
  }
    return linhas;
}

int ComparaBigNum(BigNum a, BigNum b){ // Retorna 1 se forem iguais, 0 caso contrário.
	Apontador Aux1;
	Apontador Aux2;

	Aux1 = a.primeiro->prox;
	Aux2 = b.primeiro->prox;

	int contador=0;

	while(Aux1 != NULL || Aux2 != NULL){
	    if(Aux1->Casa == Aux2->Casa){
            if(Aux1->prox == NULL && Aux2->prox != NULL){
                return 0;
            }
            Aux1 = Aux1->prox;
            Aux2 = Aux2->prox;
            contador++;
		}
            else{
            return 0;
            }
	}
			if(ContaDigitoBigNum(a) == contador){
			return 1;
			}
	return 0;
}

void MudaSinal (BigNum *lista){
    lista->sinal = '-';
}

void FBigNumVazia(BigNum *lista){   //Cria um BigNum Vazio
    lista->primeiro = (Apontador) malloc(sizeof(TipoCelula)); //cria uma celula cabeça
    //lista->primeiro->Casa = 0;   VALOR DA CÉLULA CABEĆA.
    lista->ultimo = lista->primeiro ;  //campo ultimo da lista é igual ao campo primeiro (ambos apontam pra celula cabeça)
    lista->primeiro->prox = NULL;    //campo prox do apontado por primeiro aponta pra NULL
    lista->primeiro->ante = NULL;
    lista->sinal = '+';
    //printf("ListaCriada\n");
}

void InsereNoBigNum(BigNum *lista, int digito){   //Transforma e insere um inteiro no BigNum.
    lista->ultimo->prox = (Apontador) malloc(sizeof(TipoCelula) ) ;//cria nova celula

    lista->ultimo->prox->ante = lista->ultimo;

    lista->ultimo = lista->ultimo->prox;  // Anda com o ponteiro ultimo pra célula criada.
    lista->ultimo->Casa = digito;  //Campo Casa da célula apontada por ultimo recebe digito.
    lista->ultimo->prox = NULL;

    //printf("Sucesso digito eh %d\n",digito);
}

void ShiftDireita(BigNum* a, int quantidade){ //Insere 0s à direita Ex. 24 ::= 2400
	while(quantidade != 0){
		a->ultimo->prox = (Apontador) malloc(sizeof(TipoCelula) );
		a->ultimo->prox->ante = a->ultimo;
		a->ultimo = a->ultimo->prox;
		a->ultimo->Casa = 0;
		a->ultimo->prox = NULL;
		quantidade--;
	}
}

void RetiraPrimeiro(BigNum *a){ //Retira Primeiro elemento da Lista
Apontador Aux;

Aux = a->primeiro->prox;
a->primeiro->prox = a->primeiro->prox->prox;
a->primeiro->prox->prox->ante = a->primeiro;
free(Aux);


}

void RetiraUltimo(BigNum *a){
  Apontador Aux;
  
 Aux = a->ultimo->ante;
 
  
}

void destruir(BigNum *a){
    Apontador Aux;
    Aux = a->primeiro->prox;

    while(Aux != NULL){
        a->primeiro->prox = a->primeiro->prox->prox;
        //a->primeiro->prox->prox->ante = a->primeiro;
        free(Aux);
        Aux = a->primeiro->prox;
    }
}

void ShiftEsquerda(BigNum* a, int quantidade){
	Apontador Auxiliar;
	while(quantidade != 0){
		Auxiliar = a->primeiro->prox;
		a->primeiro->prox = (Apontador) malloc(sizeof(TipoCelula) );
		a->primeiro->prox->prox = Auxiliar;
		a->primeiro->prox->prox->ante = a->primeiro->prox;
		a->primeiro->prox->Casa = 0;
		quantidade--;
		}
}

void imprimir(BigNum* a){ //Imprime um BigNum na ordem normal
    Apontador Aux;
    Aux = a->ultimo;

    if(a->sinal != '+'){
    printf("%c",a->sinal);
    }
  while(Aux->ante != NULL){
    printf("%d", Aux->Casa);
    Aux = Aux->ante;
  	}
printf("\n");
}

void imprimenormal(BigNum* a){ //Imprime um BigNum ordem em que estão na lista
    Apontador Aux;
    Aux = a->primeiro->prox;

    if(a->sinal != '+'){
    printf("%c",a->sinal);
    }
  while(Aux != NULL){
    printf("%d", Aux->Casa);
    Aux = Aux->prox;
  	}
printf("\n");

}

BigNum criar(int num){    //Cria um BigNum a partir de um inteiro
int digito;
int contador = ContaDigito(num);
BigNum a;

inverte(&num);
FBigNumVazia(&a);

//printf("Contador eh: %d\n", contador);

while(contador > 0){
digito = num / pow(10,contador-1);
InsereNoBigNum(&a,digito);
num = num - (digito*pow(10,contador -1));
contador--;
     }
return(a);
}

void inverte(int *num){  // Inverte um inteiro.
int m=0;
while(*num>0){
    m *=10;
    m += *num%10;
    *num /= 10;
}
*num = m;
}

int ContaDigito(int i){ //Conta o Número de Digitos em um Inteiro qualquer.
int contador = 1;
int parametro = 10;
while(i >= parametro){
	parametro*=10;
	contador++;
}
return contador;
}

BigNum somar(BigNum a, BigNum b){
    Apontador Aux1;
    Apontador Aux2;
    BigNum resultado;
    FBigNumVazia(&resultado);

    
    
    Aux1 = a.primeiro->prox;
    Aux2 = b.primeiro->prox;

    int vaium = 0;
    int parcial;

	while(Aux1 != NULL && Aux2 != NULL){

	    // a e b numero iguais de dígitos
		if(Aux1->prox == NULL && Aux2->prox == NULL){
			parcial = Aux1->Casa + Aux2->Casa;

                if(parcial >= 10){
                	vaium = 1;
					InsereNoBigNum(&resultado,parcial%10);
					InsereNoBigNum(&resultado,vaium);
					return resultado;
                    }

					  if(parcial<10){
					    InsereNoBigNum(&resultado,parcial);
						return resultado;
						}
		}

		// a com numero maior de digitos
		if(Aux1->prox != NULL && Aux2->prox == NULL){
			parcial = Aux1->Casa + Aux2->Casa;
               if(parcial >=10){
					vaium=1;
					InsereNoBigNum(&resultado,parcial%10);
					Aux1->prox->Casa = Aux1->prox->Casa+vaium;

                        while(Aux1->prox != NULL){
                             Aux1 = Aux1->prox;

                                if(Aux1->Casa >= 10 && Aux1->prox == NULL){
                                    InsereNoBigNum(&resultado, (Aux1->Casa)%10);
                                    InsereNoBigNum(&resultado, (Aux1->Casa)/10);
                                  }
                                    if(Aux1->Casa >=10 && Aux1->prox != NULL){
                                      Aux1->prox->Casa = Aux1->prox->Casa+vaium;
                                      InsereNoBigNum(&resultado, (Aux1->Casa)%10);
                                      }
                                        if(Aux1->Casa <10 && Aux1->prox != NULL){
                                           InsereNoBigNum(&resultado, Aux1->Casa);
                                        }
                                            if(Aux1->Casa <10 && Aux1->prox == NULL){
                                                InsereNoBigNum(&resultado, Aux1->Casa);
                                            }
                            }

					}
                        if(parcial <10){
                            InsereNoBigNum(&resultado,parcial);
                                while(Aux1->prox != NULL){
                                    InsereNoBigNum(&resultado, Aux1->prox->Casa);
                                    Aux1 = Aux1->prox;
                                    }
					    }
        }

        // 43 + 31, por exemplo
		if(Aux1->prox != NULL && Aux2->prox != NULL){
			parcial = Aux1->Casa + Aux2->Casa;
				if(parcial >=10){
					vaium=1;
					InsereNoBigNum(&resultado,parcial%10);
					Aux1->prox->Casa = Aux1->prox->Casa+vaium;
				}
					if(parcial < 10){
						InsereNoBigNum(&resultado, parcial);
						}
		 }

        //Anda com os ponteiros auxiliares pra frente.
		Aux1 = Aux1->prox;
		Aux2 = Aux2->prox;

    }

		return resultado;
}

BigNum subtrair(BigNum a, BigNum b){

 Apontador Aux1;
 Apontador Aux2;

 BigNum result;
 FBigNumVazia(&result);
 int parcial;

 Aux1 = a.primeiro->prox;
 Aux2 = b.primeiro->prox;

 //int tiraum;

    while(Aux1 != NULL && Aux2 != NULL){

			/** ESPAÇO PARA PROCESSAMENTO DE SINAIS A SER FEITA**/


			if(Aux1->prox != NULL && Aux2->prox ==NULL){ // 10-5
				ShiftDireita(&b, ContaDigitoBigNum(a)-ContaDigitoBigNum(b)); //Iguala o numero de digitos
imprimenormal(&b);

/**				if(Aux1->Casa < Aux2->Casa){
					Aux1->Casa = Aux1->Casa + 10;


					if(Aux1->prox->Casa == 0){
					    printf("entrei\n");

					    Aux1=Aux1->prox;

                        while(Aux1->Casa == 0){
                           printf("auqi agora\n");
                           Aux1->Casa = Aux1->Casa + 9;
printf("%d\n", Aux1->Casa);



                            /**if(Aux1->Casa != 0){

                                Aux1->Casa = Aux1->Casa - 1;
                                }**/ /**
                            Aux1 = Aux1->prox;
                        }
                        if(Aux1->Casa !=0){
printf("%d\n", Aux1->Casa);
                            Aux1->Casa = Aux1->Casa -1;
                        }

                            Aux1 = a.primeiro->prox;
printf("%d\n", Aux1->Casa);
                            while(Aux1 != NULL){

                        InsereNoBigNum(&result,Aux1->Casa - Aux2->Casa);
                        Aux1 = Aux1->prox;
                        Aux2 = Aux2->prox;
                            }

                        return result;
                        }
					}

					/**Aux1->prox->Casa = Aux1->prox->Casa - 1;  //Tira um do seguinte
					parcial = Aux1->Casa - Aux2->Casa; //Realiza a operação em si
					InsereNoBigNum(&result,parcial);
					//InsereNoBigNum(&result,Aux1->prox->Casa);
				//Aux1 = Aux1->prox;
				while(Aux1->prox != NULL){
					InsereNoBigNum(&result,Aux1->prox->Casa);
                    Aux1 = Aux1->prox;
                    printf("oi mae\n");
                    }**/ /**

				else if(Aux1->Casa >= Aux2->Casa){
					parcial = Aux1->Casa - Aux2->Casa;
					InsereNoBigNum(&result, parcial);
					while(Aux1->prox != NULL){
					InsereNoBigNum(&result,Aux1->prox->Casa);
                    Aux1 = Aux1->prox;
                    printf("oi\n");
                    }
					return result;
					}
			**/
			}




			if(Aux1->prox == NULL && Aux2->prox == NULL){  // 9 - 2
				if(Aux1->Casa >= Aux2->Casa){
					parcial = Aux1->Casa - Aux2->Casa ;
					InsereNoBigNum(&result,parcial);
				}
				/**if(Aux1->Casa < Aux2->Casa){ // 4 - 7
				}**/
			}

			if(Aux1->prox != NULL && Aux2->prox != NULL){ // 55-11
				if(Aux1->Casa < Aux2->Casa){
					Aux1->Casa = Aux1->Casa + 10;
					Aux1->prox->Casa = Aux1->prox->Casa - 1;  //Tira um do seguinte
					parcial = Aux1->Casa - Aux2->Casa; //Realiza a operação em si
					InsereNoBigNum(&result,parcial);
					//Aux1 = Aux1->prox;
					}
                    else if(Aux1->Casa >= Aux2->Casa){
					parcial = Aux1->Casa - Aux2->Casa;
					InsereNoBigNum(&result, parcial);
					}
			}

				Aux1 = Aux1->prox;
				Aux2 = Aux2->prox;

				printf("Rodei o while\n");
	}

    	return result;
}

BigNum multiplica (BigNum a, BigNum b){

//NA MULTIPLICACAO, A É SEMPRE MAIOR QUE B
Apontador Aux1;
Apontador Aux2;

BigNum produto;
BigNum parcial;
BigNum somatorio;

parcial = criar(0);
FBigNumVazia(&somatorio);
FBigNumVazia(&produto);



Aux2 = b.primeiro->prox;
Aux1 = a.primeiro->prox;

int shifts = 0;
int semiproduto;
int dezena = 0;

 /**PROCESSAMENTO DE SINAIS**/

	while(Aux1 != NULL && Aux2 != NULL){

		if(Aux1->prox != NULL && Aux2->prox !=NULL){  //22*33

			while(Aux2 != NULL){
				while(Aux1 != NULL){
					semiproduto = (Aux2->Casa * Aux1->Casa) + dezena;
						if(semiproduto >=10){

						dezena = semiproduto/10;

						InsereNoBigNum(&produto, semiproduto%10);
							if(Aux1->prox == NULL){
								InsereNoBigNum(&produto, semiproduto/10);
                              }
                            }	else{
								InsereNoBigNum(&produto, semiproduto);
								dezena = 0;
                                    }
							Aux1 = Aux1->prox;

				}


				Aux2 = Aux2->prox;
				Aux1 = a.primeiro->prox;
				ShiftEsquerda(&produto, shifts);
				shifts++;
				dezena = 0;


				somatorio = somar(produto,parcial);


				parcial = somatorio;
				FBigNumVazia(&produto);



			}
        return somatorio;
		}

		if(Aux1->prox != NULL && Aux2->prox ==NULL){  // 99*2

			dezena = 0;
			if(Aux2->Casa == 0){
			    InsereNoBigNum(&produto,0);
			    return produto;
			}
			while(Aux1 != NULL){
				semiproduto = Aux2->Casa * Aux1->Casa + dezena;
					dezena = 0;
					if(semiproduto >= 10){
					InsereNoBigNum(&produto,semiproduto%10);
					dezena = semiproduto/10;
						   if(Aux1->prox == NULL){
						       dezena = 0;
							InsereNoBigNum(&produto,semiproduto/10);
					}
						}

						else if(semiproduto<10){
						 InsereNoBigNum(&produto,semiproduto);
                            }

						else{
									InsereNoBigNum(&produto, semiproduto);
								}
								Aux1 = Aux1->prox;

					}
			 return produto;
		}

		if(Aux1->prox == NULL && Aux2->prox == NULL){   // 3*2
             semiproduto = Aux1->Casa * Aux2->Casa;
			 if(semiproduto >= 10){
				InsereNoBigNum(&produto, semiproduto%10);
				InsereNoBigNum(&produto,semiproduto/10);
				}
				else{
						InsereNoBigNum(&produto, semiproduto);
						}
			return produto;
		}


	}
	return somatorio;
}

BigNum dividir(BigNum a, BigNum b){
  
  BigNum Aux;
  BigNum quociente;
  FBigNumVazia(&Aux);
  
   
  
  Aux = subtrair(a,b);
  imprimenormal(&Aux);
  int contador = 1;
  
  while( ComparaBigNum( somar(Aux,b) , b ) != 1 ){
  Aux = subtrair(Aux,b);
  contador++;
  }
  InsereNoBigNum(&quociente,contador);
  
  return quociente;
}

BigNum Fatorial(int n){
    BigNum resultado;
    resultado = criar(n);
    int i=n;
    while(i>1){
        resultado = multiplica(resultado,criar(i-1));
        // imprimenormal(&resultado);Fins de Debug
    i--;
    }
    return resultado;

}

void IgualaDigitosBigNum(BigNum a, BigNum b){
int diferenca;
if(ContaDigitoBigNum(a) < ContaDigitoBigNum(b)){
    diferenca = ContaDigitoBigNum(b) - ContaDigitoBigNum(a);
    while(diferenca != 0){
    InsereNoBigNum(&a,0);
    diferenca--;
    }
}
    else{
        diferenca = ContaDigitoBigNum(a) - ContaDigitoBigNum(b);
    while(diferenca != 0){
    InsereNoBigNum(&b,0);
    diferenca--;
       }
    }
 }

int ContaDigitoBigNum(BigNum a){
    Apontador Aux1;
    int contador = 0;
    Aux1 = a.primeiro;
    while(Aux1 != NULL){
        contador++;
        Aux1 = Aux1->prox;
    }
    return contador-1;
}

int ProcessaSinal(BigNum a, BigNum b){

  if(ContaDigitoBigNum(a) > ContaDigitoBigNum(b)){ //20 e 5
    return 1; 
  }
    if(ContaDigitoBigNum(a) < ContaDigitoBigNum(b)){ // 20 e 150
      return 2;
    }
    if(ContaDigitoBigNum(a) == ContaDigitoBigNum(b)){
      if(a.ultimo->Casa > b.ultimo->Casa){ // 50 e 60
	return 1;
      }
      
    }
    
    
}






