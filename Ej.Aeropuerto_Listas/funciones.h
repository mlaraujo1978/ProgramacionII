/* 
 * File:   funciones.h
 * Author: lourdes
 *
 * Created on 13 de noviembre de 2019, 10:05
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
int ordIng;
char tipo[10];
char codigo[6];
int pasArribo;
int ordDesp;
int pasDesp;
}STR_AVION;

typedef struct nodoP{
 STR_AVION avion;
 struct nodoP *ste;
}STR_PILA;

typedef struct nodoL{
    STR_AVION avion;
    struct nodoL *ste;  
}STR_LISTA;


FILE * OpenFile (const char *nameF, const char *openT);

STR_LISTA * creaNodoP (STR_LISTA **lista, STR_AVION avion);

STR_AVION deleteFirst(STR_LISTA **lista);

STR_AVION insertInfront(STR_LISTA **lista, STR_AVION avion);

void imprimeListaZonaEspera (STR_LISTA *zE);

void procesaArribos(FILE *fA,FILE *fM,STR_LISTA **zE);

void OrdenaAvionesZonaEspera (STR_LISTA **zE, STR_AVION avion);

void actualizaFileMovimientos(FILE *fP, FILE *fM,STR_AVION avion);

void procesaPartidas(FILE *fP, FILE *fM);

void procesaDespegues(STR_LISTA **zE,STR_LISTA **despegue, FILE *fM);

void ImprimeFileMovimientos (FILE *fM);


#endif /* FUNCIONES_H */

