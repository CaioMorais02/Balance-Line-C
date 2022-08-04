/*
 * transacao.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */

#include <stdio.h> /* define FILE */
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codCliente;
	char tipoTransacao;
	char valor01[40];
	char valor02[40];
}TTransacao;

TTransacao *Transacao(int cod, char tipo, char *valor01, char *valor02){
	TTransacao *transacao = (TTransacao *) malloc(sizeof(TTransacao));
    //inicializa espaço de memória com ZEROS para os valores inteiros
    if (transacao) memset(transacao, 0, sizeof(TTransacao));
    //copia valores para os campos de transacao
    transacao->codCliente = cod;
    transacao->tipoTransacao = tipo;
    strcpy(transacao->valor01, valor01);
    strcpy(transacao->valor02, valor02);
    return transacao;
}

void salvaTransacao(TTransacao *transacao, FILE *out) {
	fwrite(&transacao->codCliente, sizeof(int), 1, out);
	fwrite(&transacao->tipoTransacao, sizeof(char), 1, out);
	fwrite(transacao->valor01, sizeof(char), sizeof(transacao->valor01), out);
	fwrite(transacao->valor02, sizeof(char), sizeof(transacao->valor02), out);
}
