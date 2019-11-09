/* 
 * File:   main.c
 * Author: lourdes
 * Created on 8 de noviembre de 2019, 19:18
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

typedef struct{
    int codTrans;
    int ctaOri;
    int ctaDes;
    int monto;
    int tipoC;
}STR_REG;

typedef struct{
    int codT;
    int tipoC;
}STR_TRANSDEN; 

typedef struct nodoL{
    struct nodoL *ste;
    STR_TRANSDEN transDenun;
}STR_LISTA;

STR_LISTA * insertAtEnd(STR_LISTA **lista,STR_TRANSDEN transDenun ){

    STR_LISTA *nodoL=(STR_LISTA*)malloc(sizeof(STR_LISTA));
    nodoL->transDenun=transDenun;
    nodoL->ste=NULL;
    
    STR_LISTA *listAux=*lista;
    
    while(listAux!=NULL && listAux->ste!=NULL){
    
        listAux=listAux->ste;        
    }
    
    if(listAux==NULL){
        *lista=nodoL;
    }
    else{
        listAux->ste=nodoL;  
    }

return nodoL;    
}

FILE * openFile(char nF[15], char oT[4]){

    FILE* f=fopen(nF, oT);
    if(f==NULL){
        printf("El archivo no se pudo abrir");
        exit(1);    
    }
    return f;
}

void inicializaFileBin (FILE * f, int numtrans){
    
    f=openFile("transaccines.data","rb+");
    
    STR_REG trans;
    
    fseek(f,(sizeof(STR_REG))*(numtrans-1), SEEK_SET);
    fread(&trans,sizeof(STR_REG),1,f);
    fseek(f,(sizeof(STR_REG))*(numtrans-1), SEEK_SET);    
    trans.codTrans=0;   
    trans.ctaOri=0;
    trans.ctaDes=0;
    trans.monto=0;
    
    fwrite(&trans,sizeof(STR_REG), 1, f);
  
    fclose(f);
}

void imprimeFile (FILE * f, char nF[10], char oT[4]){

STR_REG trans;   

f= openFile(nF, oT);  

    fread(&trans, sizeof(STR_REG), 1, f);   
        while(!feof(f)){

        printf("N° Transaccion: %d\t Cuenta Origen: %d\t Cuenta Destino: %d\t Monto: %d Tipo trans.: %d\n", trans.codTrans, trans.ctaOri, trans.ctaDes, trans.monto, trans.tipoC);

        fread(&trans, sizeof(STR_REG), 1, f);
    }
fclose(f);  
 }
void cargaListaTransDenunciadas(STR_LISTA **lista,FILE *f){

    f=openFile("transDenunciadas.txt", "r+");
    
    STR_TRANSDEN transDenun;
    
    char *linea=(char*)malloc(sizeof(char)*6);
    char *dato=(char*)malloc(sizeof(char)*6);
    
    int i=0;
    int j=0;
    int cantIte=0;
    
        while(fgets(linea,6+1,f)!=NULL){
                                            
            while(*linea){  
                
                while(*linea && *linea!=','&& *linea!='.'){
                    
                    *(dato+i)=*(linea);
                    linea++;
                    i++;
                    j++;
                }
                
                cantIte++;
                i=0;
                          
                if(cantIte==1){
                    transDenun.codT=atoi(dato);
                    //printf("\nCodTrans: %d\t",transDenun.codT);
                };
                if(cantIte==2){
                    transDenun.tipoC=atoi(dato);
                    //printf("\nTipoTrans: %d\t",transDenun.tipoC);
                };
                linea++;
                j++;
                memset(dato,'\0',6);
                
            }
                  
           insertAtEnd(lista,transDenun);
           cantIte=0;
           linea=linea-j;
           j=0;
           
        }
    return;
}

STR_LISTA *search(STR_LISTA *lista, int dato){

    STR_LISTA *listAux=lista;
    
    while(listAux!=NULL && listAux->transDenun.codT != dato){
        listAux=listAux->ste;
    }
        
    return listAux;
}


void procesoControlFraude (STR_LISTA *lista, FILE *fB, FILE *fTS){

fB=openFile("transacciones.data","rb+");
fTS=openFile("sospechoso.txt","w+");
fclose(fTS);

STR_REG reg;

fread(&reg, sizeof(STR_REG),1,fB);

        while (!feof(fB)){
            
            STR_LISTA *nodoL=search(lista,reg.codTrans);
            
            if(nodoL==NULL){
                
            printf("N° Transaccion: %d\t Cuenta Origen: %d\t Cuenta Destino: %d\t Monto: %d Tipo trans.: %d\n", reg.codTrans, reg.ctaOri, reg.ctaDes, reg.monto, reg.tipoC);
            }
        
            else{
                if(reg.codTrans == nodoL->transDenun.codT){
            
                if (nodoL->transDenun.tipoC==2){
                
                    reg.codTrans=-1;   
                    reg.ctaDes=-1;
                    reg.ctaOri=-1;
                    reg.monto=-1;
                    reg.tipoC=-1;
                    
                    fseek(fB, (sizeof(STR_REG))*(-1), SEEK_CUR);
                    fwrite(&reg, sizeof(STR_REG),1,fB);
                }
                
                if (nodoL->transDenun.tipoC==1){
                    
                    fTS=openFile("sospechoso.txt","a+");
                    fprintf(fTS,"%d,%d,%d,%d,%d\n",reg.codTrans,reg.ctaOri,reg.ctaDes,reg.monto, reg.tipoC);
                    fclose(fTS);
                    
                    reg.tipoC=1;
                    fseek(fB, (sizeof(STR_REG))*(-1), SEEK_CUR);
                    fwrite(&reg, sizeof(STR_REG),1,fB);
                
                }
                
            }
        }   
        fread(&reg, sizeof(STR_REG),1,fB);
        }

fclose(fB);
}


void imprimeLista (STR_LISTA *lista){

   while(lista!=NULL){
    
        printf("\nCodTrans: %d\t",lista->transDenun.codT);
        printf("\nTipoTrans: %d\t",lista->transDenun.tipoC);
    
        lista=lista->ste;
    }
   return;
}

int main(int argc, char** argv) {
    
    FILE *fT=NULL;
    
    FILE *fB=NULL;
    
    FILE *fTS=NULL;
    
    STR_LISTA *lista=NULL;
    
    cargaListaTransDenunciadas(&lista, fT);
    
    //imprimeLista (lista);
    
    procesoControlFraude (lista, fB, fTS);
    
    //imprimeFile (fB,"transacciones.data", "rb+"); 

    return (EXIT_SUCCESS);
}

