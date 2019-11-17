/* 
 * File:   main.c
 * Author: lourdes
 * Created on 16 de noviembre de 2019, 17:59
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char** argv) {
    
 FILE *fNotas=NULL;
  FILE *fAsistencias=NULL;
   FILE *fAprobados=NULL;
   
   STR_LISTA *notas=NULL;
   STR_LISTA *asistencias=NULL;
   
   
   int opcion=0;

                printf("\n.:Menu:.\n");
                 printf("1-Procesa File Notas: \n");
                  printf("2-ProcesaNotas: \n");
                   printf("3-Procesa File Asistencias: \n");
                    printf("4-Genera File Aprobados: \n");
                     printf("5-Imprime File Aprobados: \n");
                      printf("Ingrese una opción del 1 al 5, 0 para terminar:\t");
                        scanf("%d",&opcion);                           
                           

        while(opcion>0){
                                
            switch(opcion){
                    case 1:
                        ProcesaFileNotas(fNotas,&notas);   
                        break;
                    case 2:
                        revisaNotas(&notas);
                        break;
                    case 3:
                        ProcesaFileAsistencias(fAsistencias,&asistencias);
                        break;
                    case 4:
                        GeneraFileAprobados(fAprobados,notas,asistencias);
                        break;   
                    case 5:
                        ImprimeFile(fAprobados);        
                    default:
                        printf(".: Opcion erronea.:\n");    
                        break;
            }
                printf("\n.:Menu:.\n");
                 printf("1-Procesa File Notas: \n");
                  printf("2-ProcesaNotas: \n");
                   printf("3-Procesa File Asistencias: \n");
                    printf("4-Genera File Aprobados: \n");
                     printf("5-Imprime File Aprobados: \n");
                      printf("Ingrese una opción del 1 al 5, 0 para terminar:\t");
                        scanf("%d",&opcion);  
        }
                        
  return (EXIT_SUCCESS);

}
