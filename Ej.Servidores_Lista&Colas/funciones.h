#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
    int id;
    int cantCiclos;
    char tipo[3+1];
}STR_PEDIDO;

typedef struct nodoQ{
    STR_PEDIDO pedido;
    struct nodoQ *ste;
}STR_NODOQ;

typedef struct{
    STR_NODOQ *frente;
    STR_NODOQ *fin;
    int cantPedidos;
    int cantCPU;
    int cantES;
    int maxCcES;
}STR_Q;

typedef struct nodoL{
    STR_Q q;
    struct nodoL *ste;
}STR_LISTA;


void create(STR_LISTA **lista);

STR_LISTA * creaNodoLista(STR_LISTA **lista);

STR_LISTA *BuscaNodoMenorCantPedidos(STR_LISTA *lista);

void insertAtEnd(STR_LISTA **lista,STR_PEDIDO pedido);

void crearCola(STR_Q *q);

bool isEmpty (STR_Q *q);

void addQ(STR_Q *q, STR_PEDIDO pedido);

STR_PEDIDO removeQ (STR_Q *q);

STR_PEDIDO ingresaPedido (STR_PEDIDO pedido);

void ingresaPedidoenCola (STR_LISTA **lista, STR_PEDIDO pedido, int n, int m);

void imprimeEstadisticasPedidos(STR_LISTA *lista);

#endif /* FUNCIONES_H */

