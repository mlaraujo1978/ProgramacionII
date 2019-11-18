
#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct{
char nomBanda[30];
char nomDisco[30];
int anioDisco;
int cantVen;
}STR_BANDA;

typedef struct nodoL2{
    int cantVend;
    int posFile;
    struct nodoL2 *ste;
}STR_LIST2;

typedef struct nodoL1{
    int anioDisco;
    STR_LIST2 *cantVendida;   
    struct nodoL1 *ste;
}STR_LIST1;

FILE *openFile (const char *nameF, char const *openT);

void ImprimeFile (FILE * f);

STR_LIST1 *buscaAnio(STR_LIST1 *list, int anio);

STR_LIST1 *insertOrdenadoAnio(STR_LIST1 **list, int anio);

void insertOrdenadoCantDiscos(STR_LIST2 **list, int cantVen, int posFile);

STR_LIST1 * insertSinDuplicadosAnio(STR_LIST1 **list, int anio);

void creaListaPorAnioYCantVend(FILE * f, STR_LIST1 **list);
    
void imprimeListaBandas(FILE * f, STR_LIST1 *list);

#endif /* FUNCIONES_H */

