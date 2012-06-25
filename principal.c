/*========================================================================================================================================
TRABALHO PRATICO 0 - AEDSIII
@ARLEI LOPES DA SILVA

*PRINCIPAL.C - Arquivo principal do programa que implementa um simulador de elevador
========================================================================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "simulador.h"

int main(int argc, char** argv)
{
	/*arquivos*/
	FILE* arquivo_ambiente;
	FILE* arquivo_requisicoes;
	FILE* arquivo_requisicoes_atendidas;
	
	/*nomes de arquivos*/
	char* nome_arquivo_ambiente;
	char* nome_arquivo_requisicoes;
	char* nome_arquivo_requisicoes_atendidas;
	
	char linha_comando;
	
	T_simulador* simulador;	//simulador
	T_elevador* elevador;	//elevador
	int t;

	/*variaveis para medida de tempo de execucao*/
	float tempo_execucao;
	float tempo_usuario;
	float tempo_sistema;
	struct timeval t_inicio;
	struct timeval t_fim;
	struct rusage uso_recursos;
	struct timeval t_usuario;
	struct timeval t_sistema;

	gettimeofday(&t_inicio, NULL);
	
	/*Leitura dos parametros de linha de comando*/
	while((linha_comando = (getopt(argc,argv,"a:r:s:"))) != -1)
	{
		switch(linha_comando)
		{
			case 'a' :  nome_arquivo_ambiente = optarg;
				break;

			case 'r' : nome_arquivo_requisicoes = optarg;
				break;

			case 's' : nome_arquivo_requisicoes_atendidas = optarg;
				break;
	
			default: printf("Parametro invalido %c\n", linha_comando);
				exit(1);
		}
	}

	/*Impressao dos parametros no terminal*/
	printf("nome_arquivo_ambiente			-	%s\n", nome_arquivo_ambiente);
	printf("nome_arquivo_requisicoes		-	%s\n", nome_arquivo_requisicoes);
	printf("nome_arquivo_requisicoes_atendidas	-	%s\n", nome_arquivo_requisicoes_atendidas);


	/*Abertura de arquivos*/
	arquivo_ambiente = fopen(nome_arquivo_ambiente, "r");
	arquivo_requisicoes = fopen(nome_arquivo_requisicoes, "r");
	arquivo_requisicoes_atendidas = fopen(nome_arquivo_requisicoes_atendidas, "w");

	/*Verificacao dos arquivos*/
	if(! arquivo_ambiente)
	{
		printf("Erro ao abrir o arquivo de ambiente!\n");
		exit(1);
	}

	if(! arquivo_requisicoes)
	{
		printf("Erro ao abrir o arquivo de requisicoes!\n");
		exit(1);
	}

	if(! arquivo_requisicoes_atendidas)
	{
		printf("Erro ao abrir o arquivo de requisicoes atendidas!\n");
		exit(1);
	}

	elevador = cria_elevador(arquivo_ambiente);	
	simulador = inicia_simulador();			
	carrega_requisicoes(simulador, arquivo_requisicoes);	//carrga todas as requisicoes do arquivo de requisicoes no simulador
	
	t = 0;	//inicializa o temporizador

	//Itera enquanto houver requisicoes a ser geradas pelo simulador ou atendidas pelo elevador
	while(simulador->n_requisicoes > 0 || elevador->n_registros > 0)
	{
	//	printf("\n=============================TEMPO = %d=======================================\n", t);	//imprime temporizador
		opera_elevador(elevador, t, arquivo_requisicoes_atendidas);	
		registra_requisicoes(simulador, elevador, t);			//registra requisicoes do dado instante na memoria do elevador
		
	//	imprime_status_elevador(elevador, stdout);			//imprime condicao do elevador
	//	imprime_status_simulador(simulador, stdout);			//imprime condicao do simulador
	
		t++;	//atualiza temporizador
	//	printf("\n=============================================================================\n");
	}

	encerra_simulador(simulador);	
	encerra_elevador(elevador); 	

	/*Fecha arquivos*/
	fclose(arquivo_ambiente);
	fclose(arquivo_requisicoes);
	fclose(arquivo_requisicoes_atendidas);

	gettimeofday(&t_fim, NULL);

	getrusage(RUSAGE_SELF, &uso_recursos);
	
	t_usuario = uso_recursos.ru_utime;
	t_sistema = uso_recursos.ru_stime;

	tempo_usuario = (float) t_usuario.tv_sec + (float) t_usuario.tv_usec / 1000000;
	tempo_sistema = (float) t_sistema.tv_sec + (float) t_sistema.tv_usec / 1000000;
	
	tempo_execucao = (t_fim.tv_sec-t_inicio.tv_sec)*1000000;
	tempo_execucao = (tempo_execucao+(t_fim.tv_usec-t_inicio.tv_usec))/1000000;

	printf("PROGRAMA ENCERRADO CORRETAMENTE\n");
	
	printf("tempo de execucao:	%f\n", tempo_execucao);
	printf("tempo de usuario:	%f\n", tempo_usuario);
	printf("tempo de sistema:	%f\n", tempo_sistema);

	return 0;
}

