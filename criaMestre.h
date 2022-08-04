/*
 * criaMestre.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */


/* Grava dados formatados num arquivo MESTRE */

#include <stdio.h> /* define FILE */
#include <stdlib.h>

void criaMestre(){
 FILE *fMestre; /* ponteiro para arquivo */

 fMestre = fopen("Mestre.dat","w");

 if(fMestre == NULL) {
     printf("\n Erro ao abrir o arquivo MESTRE");
     exit(1);
 }

 TCliente *c1 = Cliente(02,"João","21/04/1990");
 TCliente *c2 = Cliente(11,"Maria","02/07/1986");
 TCliente *c3 = Cliente(13,"Ana","05/07/1978");
 TCliente *c4 = Cliente(17,"Mário","05/02/1988");
 TCliente *c5 = Cliente(20,"Rosa","03/01/1945");
 TCliente *c6 = Cliente(21,"Raphael","27/10/1945");
 TCliente *c7 = Cliente(56,"Liz","30/09/2002");

 salvaCliente(c1, fMestre);
 salvaCliente(c2, fMestre);
 salvaCliente(c3, fMestre);
 salvaCliente(c4, fMestre);
 salvaCliente(c5, fMestre);
 salvaCliente(c6, fMestre);
 salvaCliente(c7, fMestre);

 fclose(fMestre);

}
