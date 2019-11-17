#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct nodoP{
    char letra;
    struct nodoP *ste;
}STR_PILA;

FILE * openFile(char nameF[15], char openT[4]);

STR_PILA *creaNodoP(STR_PILA **p, char letra);

void push(STR_PILA **p, char letra);

char pop(STR_PILA **p);

bool isEmpty(STR_PILA *p);

void procesaFilePalabras(FILE *fP, FILE *fNP, STR_PILA **pal,STR_PILA **palInv);

bool validaPalindromo(STR_PILA **pal,STR_PILA **palInv );

void imprimeFilePalindormos(FILE *fNP);

#endif /* FUNCIONES_H */

