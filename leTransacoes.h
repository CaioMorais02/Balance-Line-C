/*
 * leTransacoes.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */


/* Lê os dados formatados do arquivo TRANSAÇÕES */

#include <stdio.h> /* define FILE */
#include <stdlib.h>

void imprimeTransacao(TTransacao *transacao) {
    printf("\n**********************************************");
    printf("\nCliente de código ");
    printf("%d", transacao->codCliente);
    printf("\nTipo da Transação: ");
    printf("%c", transacao->tipoTransacao);
    printf("\nValor 01: ");
    printf("%s", transacao->valor01);
    printf("\nValor 02: ");
    printf("%s", transacao->valor02);
    printf("\n**********************************************");
}

TTransacao *leTransacao(FILE *in) {
	TTransacao *transacao = (TTransacao *) malloc(sizeof(TTransacao));
    //fread retorna o total de elementos lidos com sucesso
    if (0 >= fread(&transacao->codCliente, sizeof(int), 1, in)) {
        free(transacao);
        return NULL;
    }
    fread(&transacao->tipoTransacao, sizeof(char), 1, in);
    fread(transacao->valor01, sizeof(char), sizeof(transacao->valor01), in);
    fread(transacao->valor02, sizeof(char), sizeof(transacao->valor02), in);
    return transacao;
}


void leTransacoes(){
 FILE *fTransacao; /* ponteiro para arquivo */

 fTransacao = fopen("Transacoes.dat","r");

 if(fTransacao == NULL) {
     printf("\n Erro ao abrir o arquivo TRANSAÇÕES");
     exit(1);
 }

 TTransacao *t;
 while ((t = leTransacao(fTransacao)) != NULL)
	 imprimeTransacao(t);
 free(t);

 fclose(fTransacao);

}
