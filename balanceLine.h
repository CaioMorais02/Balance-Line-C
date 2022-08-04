/*
 * balanceLine.h
 *
 *  Modified on: Sep 12, 2021
 *      Author: raphael oliveira
 */


#include <stdio.h> /* define FILE */
#include <stdlib.h>

void balanceLine(FILE *fMestre, FILE *fTransacao, FILE *fNovoMestre, FILE *fErro){
	TCliente *m;
	TTransacao *t;

	int terminou = 1;
	int avanceM = 1;
	int avanceT = 1;

	rewind(fTransacao);
	rewind(fMestre);

	while (terminou != 0){

        //Mecanismo de controle da struct Mestre
        if (avanceM != 0){
            if ((m = leCliente(fMestre)) == NULL){
                return;
            }
        }

        //Mecanismo de controle da struct Transação
        if (avanceT != 0){
            if ((t = leTransacao(fTransacao)) == NULL){
                return;
            }
        }

        //Se a chave do Mestre for menor que a Transação
        if (m->codCliente < t->codCliente){
            //Salve Mestre
            salvaCliente((Cliente(m->codCliente, m->nome, m->dataNascimento)), fNovoMestre);

            //Avance Mestre
            avanceM = 1;
            avanceT = 0;
        }

        //Se a chave da Transação for menor que a do Mestre
        else if (t->codCliente < m->codCliente){
            //Se for para incluir
            if (t->tipoTransacao == 'I'){
                salvaCliente((Cliente(t->codCliente, t->valor01, t->valor02)), fNovoMestre);
            }

            //Senão, coloque em Erro
            else {
                salvaCliente(Cliente(t->codCliente, t->valor01, t->valor02), fErro);
            }

            //Avance Transação
            avanceM = 0;
            avanceT = 1;
        }

        //Se as chaves forem iguais
        else if (m->codCliente == t->codCliente){
            //Se a tipagem for para modifcar
            if (t->tipoTransacao == 'M'){
                //Modificar nome
                if (strcmp(t->valor01, "Nome") == 0){
                    salvaCliente((Cliente(m->codCliente, t->valor02, m->dataNascimento)), fNovoMestre);
                }
                //Modificar data de nascimento
                else if (strcmp(t->valor01, "Data") == 0){
                    salvaCliente((Cliente(m->codCliente, m->nome, t->valor02)), fNovoMestre);
                }
            }

            else if (t->tipoTransacao == 'I'){
                    salvaCliente(Cliente(t->codCliente, t->valor01, t->valor02), fErro);
                }

            avanceM = 1;
            avanceT = 1;
        }

        if (t == NULL || m == NULL){
            terminou = 1;
        }

    }
}

