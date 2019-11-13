/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 10 de noviembre de 2019, 11:15
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funciones.h"

int main(int argc, char** argv) {

FILE *fArribos=NULL;
FILE *fPartidas=NULL;
FILE *fMovimientos=NULL;

STR_LISTA *zonaE=NULL;
STR_LISTA *despegue=NULL;

STR_AVION avion;

int opcion=0;

                printf("\n.:Menu:.\n");
                 printf("1-Procesa Arribos: \n");
                  printf("2-Imprime orden aviones en Zona Espera: \n");
                   printf("3-Procesa Partidas: \n");
                    printf("4-Procesa Despegues: \n");
                     printf("5-Imprime itinerario de los aviones: \n");
                      printf("Ingrese una opción del 1 al 5, 0 para terminar:\t");
                        scanf("%d",&opcion);                           
                           

        while(opcion>0){
                                
            switch(opcion){
                    case 1:
                        procesaArribos(fArribos,fMovimientos,&zonaE);   
                        break;
                    case 2:
                        imprimeListaZonaEspera(zonaE);
                        break;
                    case 3:
                        procesaPartidas(fPartidas, fMovimientos);
                        break;
                    case 4:
                        procesaDespegues(&zonaE, &despegue, fMovimientos);
                        break;   
                    case 5:
                        ImprimeFileMovimientos (fMovimientos);        
                    default:
                        printf(".: Opcion erronea.:\n");    
                        break;
            }
        
                printf("\n.:Menu:.\n");
                 printf("1-Procesa Arribos: \n");
                  printf("2-Imprime orden aviones en Zona Espera: \n");
                   printf("3-Procesa Partidas: \n");
                    printf("4-Procesa Despegues: \n");
                     printf("5-Imprime itinerario de los aviones: \n");
                      printf("Ingrese una opción del 1 al 5, 0 para terminar:\t");
                        scanf("%d",&opcion);                     
                       
        }

return (EXIT_SUCCESS);
}


