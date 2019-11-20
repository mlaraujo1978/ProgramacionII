
#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
char nomYape[34+1];
long int legajo;
short int div;
}STR_ALU;

typedef struct nodoL2{
long int legajo;
int pos;
struct nodoL2* ste;
}STR_LISTA2;


typedef struct nodoL1{
short int div;
STR_LISTA2 *legajo;
struct nodoL1* ste;
}STR_LISTA1;

FILE * openFile(const char *nameF, const char *openF);
  
void imprimeFile (FILE * f);

STR_LISTA1 *insertOrdenadoDiv(STR_LISTA1 **list, int div);
       
void insertOrdenadoLegajo(STR_LISTA2 **list, int legajo, int pos);

STR_LISTA1 *BuscaNodoDiv(STR_LISTA1 *list, int div);

STR_LISTA1 *insertSinDuplicadosDiv(STR_LISTA1 **list, int div);

void cargaListaOrdenadaDivyLegajo(FILE *f,STR_LISTA1 **list);

void ImprimeListas(FILE* f,STR_LISTA1 *list);

#endif /* FUNCIONES_H */

