/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 2 de noviembre de 2019, 12:13
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char** argv) {

    FILE *fA =NULL;
   
    FILE *fC=NULL;
   
    FILE *fS=NULL;
        
    STR_NODOC *listC=NULL;
           
    int opcion=0;
    
         printf("\n.:Menu:.\n");
           printf("1-Carga Lista con los datos de las carreras y legajos de archivo txt: \n");
              printf("2-Genera archivo de salida.txt con los datos de carreras, lejagos y alumnos: \n");
                  printf("3-Imprime archivo de salida txt: \n");                         
                      printf("4-Imprime archivo binario con datos de alumnos:\t");
                        printf("Ingrese una opción del 1 al 4, 0 para terminar:\t");
                            scanf("%d",&opcion);                          
                                      
    
    while (opcion>0){
        
        switch(opcion){
    
            case 1:
                CargaListasconDatosFile(fC, &listC);
                break;
            case 2:
                GeneraFileSalida(fA, fS,listC);
                break;
            case 3:
                ImprimeFile (fS, "salida.txt", "r+");
                break;
            case 4:
                ImprimeFile (fA, "alumnos.data", "rb+");
                break;
               
        }      
         printf("\n.:Menu:.\n");
           printf("1-Carga Lista con los datos de las carreras y legajos de archivo txt: \n");
              printf("2-Genera archivo de salida.txt con los datos de carreras, lejagos y alumnos: \n");
                  printf("3-Imprime archivo de salida txt: \n");                         
                      printf("4-Imprime archivo binario con datos de alumnos:\t");
                        printf("Ingrese una opción del 1 al 4, 0 para terminar:\t");
                            scanf("%d",&opcion);                          
                                                  
    }    
return (EXIT_SUCCESS);
}

