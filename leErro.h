/*
 * leErro.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */


/* Lê os dados formatados do arquivo ERRO */

#include <stdio.h> /* define FILE */
#include <stdlib.h>
//#include "cliente.h"

void imprimeErro(TCliente *cliente) {
    printf("\n**********************************************");
    printf("\nCliente de código ");
    printf("%d", cliente->codCliente);
    printf("\nNome: ");
    printf("%s", cliente->nome);
    printf("\nData de Nascimento: ");
    printf("%s", cliente->dataNascimento);
    printf("\n**********************************************");
}

TCliente *leClienteErro(FILE *in) {
    TCliente *cliente = (TCliente *) malloc(sizeof(TCliente));
    //fread retorna o total de elementos lidos com sucesso
    if (0 >= fread(&cliente->codCliente, sizeof(int), 1, in)) {
        free(cliente);
        return NULL;
    }
    fread(cliente->nome, sizeof(char), sizeof(cliente->nome), in);
    fread(cliente->dataNascimento, sizeof(char), sizeof(cliente->dataNascimento), in);
    return cliente;
}


void leErro(){
 FILE *fErro; /* ponteiro para arquivo */

 fErro = fopen("Erro.dat","r");

 if(fErro == NULL) {
     printf("\n Erro ao abrir o arquivo ERRO");
     exit(1);
 }

 TCliente *c;
 while ((c = leClienteErro(fErro)) != NULL)
	 imprimeErro(c);
 free(c);

 fclose(fErro);

}
