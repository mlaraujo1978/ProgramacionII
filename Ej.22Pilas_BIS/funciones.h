/* 
 * File:   funciones.h
 * Author: lourdes
 *
 * Created on 28 de octubre de 2019, 09:44
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct nodo{
int legajo;
struct nodo* ste;
}STR_NODO;

void createlist(STR_NODO **list);

void ingresaDatoenList(STR_NODO **list); 

STR_NODO *insertOrdered(STR_NODO **list, int legajo);

STR_NODO * insertAtEnd(STR_NODO **list, int dato);
       
void printList(STR_NODO *list);

int deleteFirst(STR_NODO **list);

void creaListC(STR_NODO **listA, STR_NODO **listB);

#endif /* FUNCIONES_H */

