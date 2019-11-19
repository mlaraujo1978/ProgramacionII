/* 
 * File:   main.c
 * Author: lourdes
 * Created on 7 de noviembre de 2019, 13:11
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include "funciones.h"

int main(int argc, char** argv) {

STR_LISTA *lista;
create(&lista);

int n=2;
int m=2;

STR_PEDIDO pedido;

int opcion;

        printf("\n.:Menu:.\n");
        printf("1-Ingresa Pedido: \n");
        printf("2-Ingresa Pedidos en Cola: \n");
        printf("3-Imprime estadisticas de Pedidos: \n");
        printf("Ingrese una opción del 1 al 3, 0 para terminar:\t");
        scanf("%d",&opcion);                           

 
        while(opcion>0){
            
            
            switch(opcion){
            
                case 1:
                    pedido=ingresaPedido(pedido);
                break;
                case 2:
                    ingresaPedidoenCola (&lista, pedido, n, m);
                break;
                case 3:
                    imprimeEstadisticasPedidos(lista);
                break; 
                default:
                   printf(".: Opcion erronea.:\n"); 
                break;   
            }
        
                printf("\n.:Menu:.\n");
                printf("1-Ingresa Pedido: \n");
                printf("2-Ingresa Pedidos en Cola: \n");
                printf("3-Imprime estadisticas de Pedidos: \n");
                printf("Ingrese una opción del 1 al 3, 0 para terminar:\t");
                scanf("%d",&opcion);   
        
        
        }

return (EXIT_SUCCESS);
}



