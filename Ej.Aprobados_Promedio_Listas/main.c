/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 17 de noviembre de 2019, 11:01
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
                   printf("2-Procesa File Asistencias: \n");
                    printf("3-Genera File Aprobados: \n");
                     printf("4-Imprime File Aprobados: \n");
                      printf("5-Imprime File Notas Aprobados: \n");
                       printf("6-Imprime File Asistencias: \n");
                        printf("Ingrese una opción del 1 al 5, 0 para terminar:\t");
                         scanf("%d",&opcion);  

        while(opcion>0){
                                
            switch(opcion){
                    case 1:
                        ProcesaFileNotas(fNotas,&notas);   
                        break;
                    case 2:
                        ProcesaFileAsistencias(fAsistencias,&asistencias);
                        break;
                    case 3:
                        GeneraFileAprobados(fAprobados,notas,asistencias);
                        break;   
                    case 4:
                        ImprimeFile(fAprobados);
                        break;
                    case 5:    
                        ImprimeFileNotas(fNotas);
                        break;
                    case 6:    
                        ImprimeFileAsistencias(fAsistencias);
                        break;
                    default:
                        printf(".: Opcion erronea.:\n");    
                        break;
            }
                 printf("\n.:Menu:.\n");
                  printf("1-Procesa File Notas: \n");
                   printf("2-Procesa File Asistencias: \n");
                    printf("3-Genera File Aprobados: \n");
                     printf("4-Imprime File Aprobados: \n");
                      printf("5-Imprime File Notas Aprobados: \n");
                       printf("6-Imprime File Asistencias: \n");
                        printf("Ingrese una opción del 1 al 5, 0 para terminar:\t");
                         scanf("%d",&opcion);   
        }
                        
  return (EXIT_SUCCESS);

}
