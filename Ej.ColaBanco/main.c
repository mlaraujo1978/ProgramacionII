/* 
 * File:   main.c
 * Author: lourdes
 *
 * Created on 18 de octubre de 2019, 11:40
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "funciones.h"

main(int argc, char** argv) {

    STR_QUEUE colaP;
    crear(&colaP);
    STR_QUEUE colaC;
    crear(&colaC);
    STR_QUEUE colaA;
    crear(&colaA);
    
    
    FILE *fAt=NULL;
    fAt=OpenFile("archivoAtencion","w+");
    fclose(fAt);
       
    int opcion;
   
    printf(".: Menu: :. \n");
    printf(".:(1) Ingresa un nuevo cliente.:\n");
    printf(".:(2) Procesa cola de atencion.:\n");
    printf(".:(3) imprime archivo de clientes atendidos.:\n");
    printf(".:Por favor marcar la opción solicitada, (0) para finalizar: .:\t");
    scanf("%d", &opcion);

   while(opcion>0){
       
   switch(opcion){
                    case 1:
                        cargaDatosenCola(&colaP, &colaC, &colaA);
                        break;
                    case 2:
                        procesaColas(&colaP,&colaC,fAt);
                        break;
                    case 3:
                        imprimiFileAtencion(fAt);
                        break;
                    default:
                    printf(".: Opcion erronea.:\n");    
                        break;
    }
    printf(".: Menu: :. \n");
    printf(".:(1) Ingresa un nuevo cliente.:\n");
    printf(".:(2) Procesa cola de atencion.:\n");
    printf(".:(3) imprime archivo de clientes atendidos.:\n");
    printf(".:Por favor marcar la opción solicitada, (0) para finalizar: .:\t");
    scanf("%d", &opcion);
}
      
return (EXIT_SUCCESS);
}