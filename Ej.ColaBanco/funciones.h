#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
   int dni;
   char nomYape[15];
   char tipoC[2];
   char sexo[2];
   char embara[2];
   int  tOp;
}STR_CLIENTE;

typedef struct nodo{
    STR_CLIENTE cli;
  struct nodo *ste;  
}STR_NODO;

typedef struct{
    STR_NODO *frente;
    STR_NODO *fin;
    int cant;  
}STR_QUEUE;

FILE * OpenFile(char nF[15],char oT[4]);

void crear (STR_QUEUE *q);

void cargaDatosenCola (STR_QUEUE *cP, STR_QUEUE *cC,STR_QUEUE *cA );
  
void add (STR_QUEUE *q, STR_CLIENTE cliente);
    
STR_CLIENTE remove1 (STR_QUEUE *q);
 
void procesaColas(STR_QUEUE *qP, STR_QUEUE *qC, FILE *f);

void imprimiFileAtencion(FILE *f);




#endif	// FUNCIONES_H

