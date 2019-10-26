/* 
 * File:   funciones.h
 * Author: lourdes
 *
 * Created on 26 de octubre de 2019, 13:57
 */
#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
char nomYape[34+1];
int legajo;
short int div;
}STR_ALU;

typedef struct nodo{
int legajo;
int pos;
struct nodo* ste;
}STR_NODO;

FILE * openFile(char nF[15], char oT[4]);

void IniciaFileBin (FILE * f,char nF[15], char oT[4]);
    
void ImprimeFile (FILE * f, char nF[10], char oT[4]);

void createlist(STR_NODO **list);

void ingresaDatoenListado (STR_NODO **list, FILE *f);

STR_NODO *insertOrdered(STR_NODO **list, int legajo, int pos);
       
void printList(STR_NODO *list);

int deleteFirst(STR_NODO **list);

void generaFileOrdenado(FILE *f, STR_NODO **list,FILE *fO);

#endif /* FUNCIONES_H */

