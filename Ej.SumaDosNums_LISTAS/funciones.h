#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct nodoL{
    int num;
    struct nodoL *ste;
}STR_LISTA;


STR_LISTA *creaNodo(STR_LISTA **list, int dato);

int MaxPosNodo (STR_LISTA *list);

void insertAtEnd (STR_LISTA **list, int dato);

STR_LISTA *readAt(STR_LISTA *list, int pos);

void cargaLista(STR_LISTA **list, int n, int numList[n]);
   
int sumaNumerosDeListas(STR_LISTA *list1, STR_LISTA *list2);

void creaListaConSuma(int suma,STR_LISTA *list1, STR_LISTA *list2,STR_LISTA **list3);


#endif /* FUNCIONES_H */

