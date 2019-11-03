
#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
int legajo;
char nYa[40+1];
char dir[60+1];
char email[20+1];
}STR_ALU;

typedef struct{
char codigoC[3+1];
char legajo[4+1];
char nombreC[40+1];
}STR_CARRERA;

typedef struct nodoA{
int legajo;
struct nodoA *ste;
}STR_NODOA;

typedef struct nodoC{
int codigoC;
char nombreC[40+1];
STR_NODOA *alum;
struct nodoC *ste;
}STR_NODOC;

FILE * openFile(char nF[15], char oT[4]);

void IniciaFileBin (FILE * f,char nF[15], char oT[4]);
  
void ImprimeFile (FILE * f, char nF[10], char oT[4]);

STR_NODOC * search(STR_NODOC *list, STR_CARRERA carrera);

STR_NODOC *insertOrderedC(STR_NODOC **list,STR_CARRERA carrera);

STR_NODOC * insertWithoutDuplicates(STR_NODOC **list, STR_CARRERA carrera);

void insertOrderedA(STR_NODOA **list, int legajo);
 
void printList(STR_NODOC *listC);

void printListA(STR_NODOA *listA);
   
void CargaListasconDatosFile(FILE *f, STR_NODOC **list);

#endif	// FUNCIONES_H

