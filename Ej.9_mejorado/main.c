#include "funciones.h"

int main() {
    STR_NODO *pila = NULL;
    int nNum []= {7, 4, 1, 5, 3, 2, 6};
    
    printf("\nLos numeros a ordenar son : ");
   
    for(int i=0;i<7;i++){

        printf("  [%i] ", nNum[i]);
        push(&pila, nNum[i]);
    }
    
    ordenarPila(&pila);

    printf("\n  ...::: PRINTEO PILA ORDENADA :::...\n");
        
        while(pila != NULL) {
        printf("\tNum en PILA: [%i]\n", pop(&pila));
    }
}