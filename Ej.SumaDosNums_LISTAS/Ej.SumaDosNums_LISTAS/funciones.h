#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct nodoL{
    double num;
    struct nodoL *ste;
}STR_LISTA;


STR_LISTA *creaNodo(STR_LISTA **list, double dato);

int MaxPosNodo (STR_LISTA *list);

void insertAtEnd (STR_LISTA **list, double dato);

STR_LISTA *readAt(STR_LISTA *list, double pos);

void cargaLista(STR_LISTA **list, int n, double numList[n]);
   
double sumaNumerosDeListas(STR_LISTA *list1, STR_LISTA *list2);

void creaListaConSuma(double suma,STR_LISTA *list1, STR_LISTA *list2,STR_LISTA **list3);


#endif /* FUNCIONES_H */

