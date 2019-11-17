/* 
 * File:   funciones.h
 * Author: lourdes
 *
 * Created on 17 de noviembre de 2019, 15:13
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
typedef struct nodoP{
    int dato;
    struct nodoP *ste;
}STR_PILA;

typedef struct nodoQ{
    int dato;
    struct nodoQ *ste;
}STR_NODOQ;

typedef struct{
    STR_NODOQ *frente;
    STR_NODOQ *fin;
}STR_Q;

void inicializaCola(STR_Q *q);
STR_NODOQ *creaNodoQ(STR_NODOQ *nodoq, int dato);
void add (STR_Q *q, int dato);
int removeUno(STR_Q *q);
bool isEmptyQ(STR_Q *q);
void creaColaA(STR_Q *colA,int numCA[4]);
void creaColaB(STR_Q *colB,int numCB[4]); 
STR_PILA *creaNodoP(STR_PILA **p, int dato);
void push(STR_PILA **p, int dato);
int pop(STR_PILA **p);
bool isEmptyP(STR_PILA *p);
void creaColAInversa(STR_Q *colA);
void GeneraPilaconColas(STR_Q *colA,STR_Q *colB,STR_PILA **p);
void imprimePila(STR_PILA **p);

#endif /* FUNCIONES_H */

