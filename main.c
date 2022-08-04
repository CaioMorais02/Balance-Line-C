/*
 * main.c
 *
 *  Created on: Nov 1, 2020
 *      Author: raphael oliveira
 */

#include "cliente.h"
#include "transacao.h"

#include "criaMestre.h"
#include "leMestre.h"

#include "criaTransacoes.h"
#include "leTransacoes.h"

#include "balanceLine.h"

#include "leNovoMestre.h"
#include "leErro.h"

int main(){

	//**********************
	//Criando arquivo Mestre
	//**********************
	criaMestre();

	//**********************
	//Lendo o arquivo Mestre
	//**********************
	printf("\n===IMPRIMINDO O ARQUIVO MESTRE===");
	leMestre();

	//**********************
	//Criando arquivo Transações
	//**********************
	criaTransacoes();

	//**********************
	//Lendo o arquivo Transações
	//**********************
	printf("\n===IMPRIMINDO O ARQUIVO DE TRANSAÇÕES===");
	leTransacoes();


	FILE *fMestre, *fTransacoes, *fNovoMestre, *fErro; /* ponteiro para arquivos */

	fMestre = fopen("Mestre.dat","r");
	fTransacoes = fopen("Transacoes.dat","r");

	fNovoMestre = fopen("NovoMestre.dat","w");
	fErro = fopen("Erro.dat","w");

	 if((fMestre == NULL) || (fTransacoes == NULL)) {
	     printf("\n Erro ao abrir o arquivo");
	     exit(1);
	 }

	balanceLine(fMestre, fTransacoes, fNovoMestre, fErro);

	fclose(fMestre);
	fclose(fTransacoes);
	fclose(fNovoMestre);
	fclose(fErro);

	//IMPRIMIR O NOVO ARQUIVO MESTRE
	printf("\n===IMPRIMINDO O NOVO ARQUIVO MESTRE===");
	leNovoMestre();

	//IMPRIMIR O ARQUIVO DE ERRO
	printf("\n===IMPRIMINDO O ARQUIVO DE ERRO===");
	leErro();
	
	return 0;
}
