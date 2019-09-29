/*
*/

/* 
 * File:   main.c
 * Author: Lourdes
 *
 * Created on 13 de septiembre de 2019, 13:01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct{
    char nombre [30];
    //int edad;
    int dni;
    //char correo[20];
    //int cDias;
}STR_CLIENTE;

typedef struct{
    int id;
    char estado[15];
    STR_CLIENTE cliente;
}STR_HAB;

FILE * AbrirArchivoW(){
    FILE *reserva=fopen("reserva.b","w+b");
        if(reserva==NULL){
       printf("Error al abrir el archivo reservas.");
       exit(1);
    }
    return reserva;
}

FILE * AbrirArchivoRMas(){
    FILE *reserva=fopen("reserva.b","r+b");
        if(reserva==NULL){
       printf("Error al abrir el archivo reservas.");
       exit(1);
    }
    return reserva;
}

void inicializarHabitaciones(FILE *archivo){
    STR_HAB habitacion;
        strcpy(habitacion.estado,"RESERVADA");  
        strcpy(habitacion.cliente.nombre,"PEPE PEREZ");
        //strcpy(habitacion.cliente.correo,"");
    for(int i=0;i<10;i++){
        habitacion.id=i+1;
        //habitacion.cliente.edad=0;
        habitacion.cliente.dni=1055036;
        //habitacion.cliente.cDias=0;
     fwrite(&habitacion,sizeof(STR_HAB),1,archivo);
    }
fclose(archivo);
}

void tomarReserva (FILE * archivo){
    STR_HAB habitacion;
    int hab;  
       
    printf("Indique el numero de habitacion (del 1 al 10)si desea una en particular, 0 para asignación automatica, 0 -1 para terminar\t");fflush(stdin);
    scanf("%d",&hab);
    
    while(hab>=0 && hab<11){
    
    if(hab>=1 && hab<11){
    
    fseek(archivo,(hab-1)*(sizeof(STR_HAB)),SEEK_SET);   
    fread(&habitacion , sizeof(STR_HAB), 1 ,archivo);
    
    if( (strcmp(habitacion.estado,"RESERVADA"))==0){
    printf("La habitacion se encuentra RESERVADA.\n");fflush(stdin);
        }
    else       {    
    strcpy(habitacion.estado,"RESERVADA");
    printf("Ingrese su nombre:\n");fflush(stdin);
    scanf("%s", habitacion.cliente.nombre);
    printf("Ingrese su DNI:\n");fflush(stdin);
    scanf("%d", &habitacion.cliente.dni); 
    
    fseek(archivo,(hab-1)*(sizeof(STR_HAB)),SEEK_SET);
    fwrite(&habitacion,sizeof(habitacion),1,archivo); 
    }
    }
           
    if(hab==0){ 
    int reg=0;
    
    fread(&habitacion , sizeof(STR_HAB), 1 ,archivo);    
    
    while(!feof(archivo) && (strcmp(habitacion.estado,"RESERVADA")==0)){  
    reg++;    
    fread(&habitacion , sizeof(STR_HAB), 1 ,archivo); 
    }
    
    if(feof(archivo)){
    printf("No hay habitaciones disponibles por el momento.\n");  
    }
    
    reg++;
    printf("La habitacion reservada es la numero: %d\n",reg);fflush(stdin);
    strcpy(habitacion.estado,"RESERVADA");
    printf("Ingrese su nombre:\n");fflush(stdin);
    scanf("%s", habitacion.cliente.nombre);
    printf("Ingrese su DNI:\n");fflush(stdin);
    scanf("%d", &habitacion.cliente.dni);
    
    fseek(archivo,(reg-1)*(sizeof(STR_HAB)),SEEK_SET);
    fwrite(&habitacion,sizeof(habitacion),1,archivo);
    }
    
    fseek(archivo,0,SEEK_SET);
    printf("Indique el numero de habitacion (del 1 al 10)si desea una en particular, 0 si no, 0 -1 para terminar\t");fflush(stdin);
    scanf("%d",&hab);
    }
    
fclose(archivo);
}

void eliminaReserva(FILE * archivo){
STR_HAB habitacion;

printf("Diga su numero de habitacion:\n");fflush(stdin);
scanf("%d", &habitacion.id);

if(habitacion.id>0 && habitacion.id<11){

fseek(archivo,(habitacion.id-1)*(sizeof(STR_HAB)),SEEK_SET);

fread(&habitacion,sizeof(STR_HAB),1,archivo);

strcpy(habitacion.estado,"LIBRE"); 
strcpy(habitacion.cliente.nombre," "); 
habitacion.cliente.dni=0;

fseek(archivo,(habitacion.id-1)*(sizeof(STR_HAB)),SEEK_SET);
fwrite(&habitacion,sizeof(habitacion),1,archivo); 

fclose(archivo);
}
else{
  printf("El numero de habitacion es erroneo:\n");fflush(stdin);
}
}

void imprimirArchivo(FILE *archivo){
    
   STR_HAB habitacion;
   fseek(archivo,0,SEEK_SET);
   fread(&habitacion,sizeof(habitacion),1, archivo);
   while(!feof(archivo)){
   printf("Id:%d\t Estado:%s\t Nombre: %s\t  DNI: %d\n", habitacion.id, habitacion.estado, habitacion.cliente.nombre, habitacion.cliente.dni);
   fread(&habitacion,sizeof(habitacion),1,archivo);
   }
   fclose(archivo);

}





int main(int argc, char** argv) {
   STR_CLIENTE cliente;
   STR_HAB habitacion;
   FILE *reserva=NULL;
   int opcion;
   
   printf("Menu: \n");
   printf("(1) Inicializa archivo.\n");
   printf("(2) Reserva una habitacion.\n");
   printf("(3) Elimina una reserva de habitacion.\n");
   printf("(4) Imprimi lista con estado actual de las habitaciones\n");
   printf("Por favor marcar la opción solicitada, (0) para finalizar: \t");
   scanf("%d", &opcion);

   while(opcion>0){
       
   switch(opcion){
                    case 1:
                       reserva=AbrirArchivoW();
                       inicializarHabitaciones(reserva);
                       break;
                    case 2:
                    reserva=AbrirArchivoRMas();
                    tomarReserva(reserva);
                        break;
                    case 3:
                    reserva=AbrirArchivoRMas();
                    eliminaReserva(reserva);
                        break;
                    case 4:
                    reserva=AbrirArchivoRMas();
                    imprimirArchivo(reserva); 
                        break;
                    default:
                    printf(" Opcion erronea.\n");    
                        break;
            }
   printf("Menu: \n");
   printf("(1) Inicializa archivo.\n");
   printf("(2) Reserva una habitacion.\n");
   printf("(3) Elimina una reserva de habitacion.\n");
   printf("(4) Imprimi lista con estado actual de las habitaciones\n");
   printf("Por favor marcar la opción solicitada, (0) para finalizar: \t");
   scanf("%d", &opcion);
         }
      return (EXIT_SUCCESS);
}