/*
 * leMestre.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */


/* Lê os dados formatados do arquivo MESTRE */

#include <stdio.h> /* define FILE */
#include <stdlib.h>

void imprimeCliente(TCliente *cliente) {
    printf("\n**********************************************");
    printf("\nCliente de código ");
    printf("%d", cliente->codCliente);
    printf("\nNome: ");
    printf("%s", cliente->nome);
    printf("\nData de Nascimento: ");
    printf("%s", cliente->dataNascimento);
    printf("\n**********************************************");
}

TCliente *leCliente(FILE *in) {
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


void leMestre(){
 FILE *fMestre; /* ponteiro para arquivo */

 fMestre = fopen("Mestre.dat","r");

 if(fMestre == NULL) {
     printf("\n Erro ao abrir o arquivo MESTRE");
     exit(1);
 }

 TCliente *c;
 while ((c = leCliente(fMestre)) != NULL)
	 imprimeCliente(c);
 free(c);

 fclose(fMestre);

}
