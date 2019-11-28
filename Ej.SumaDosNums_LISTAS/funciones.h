/* 
 * File:   funciones.h
 * Author: lourdes
 *
 * Created on 27 de noviembre de 2019, 20:20
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H



typedef struct nodoL{
    int num;
    struct nodoL *ste;
}STR_LISTA;


STR_LISTA *creaNodo(STR_LISTA **list, int dato);

void insertAtEnd (STR_LISTA **list, int dato);

void cargaLista(STR_LISTA **list);

int cuentaNodos (STR_LISTA *list);

STR_LISTA *BuscaNodoPos(STR_LISTA *list, int pos);

int sumaLista(STR_LISTA *list, int cantNodos);

int sumaNumerosDeListas(STR_LISTA *list1, STR_LISTA *list2);

void creaListaConSuma(int suma,STR_LISTA *list1, STR_LISTA *list2,STR_LISTA **list3);

void imprimeLista(STR_LISTA *list); 



#endif /* FUNCIONES_H */

