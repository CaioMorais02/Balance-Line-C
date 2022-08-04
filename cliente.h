/*
 * cliente.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */

#include <stdio.h> /* define FILE */
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codCliente;
	char nome[40];
	char dataNascimento[12];
}TCliente;

TCliente *Cliente(int cod, char *nome, char *dataNascimento){
	TCliente *cliente = (TCliente *) malloc(sizeof(TCliente));
    //inicializa espaço de memória com ZEROS para os valores inteiros
    if (cliente) memset(cliente, 0, sizeof(TCliente));
    //copia valores para os campos de cliente
    cliente->codCliente = cod;
    strcpy(cliente->nome, nome);
    strcpy(cliente->dataNascimento, dataNascimento);
    return cliente;
}


void salvaCliente(TCliente *cliente, FILE *out) {
	fwrite(&cliente->codCliente, sizeof(int), 1, out);
	fwrite(cliente->nome, sizeof(char), sizeof(cliente->nome), out);
	fwrite(cliente->dataNascimento, sizeof(char), sizeof(cliente->dataNascimento), out);
}
