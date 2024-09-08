#include <stdio.h>
#include <stdlib.h>

typedef struct ImoveisDaRua{
	char *complemento;
	char imovelComercial;
	int numero;
	struct ImoveisDaRua *prox;
}IDR;

IDR * inicio = NULL;

void imprimir(){
    
    IDR * aux = inicio;
    printf("\n Imprimindo lista ...\n");
    for(int i =0 ; i<3; i++){
        
        printf("%d ", aux->numero);
        aux = aux->prox;
    }
    
    printf("\n");
    
}


int main(){
	IDR* casa342 = malloc(sizeof(IDR));
	inicio = casa342;
	IDR* apartamento17 = malloc(sizeof(IDR));
	casa342 -> imovelComercial = 'N';
	IDR* mercantil1 = malloc(sizeof(IDR));
	mercantil1 -> numero = 1;
	mercantil1 -> complemento = "Casa Comercial, 521 m²";
	apartamento17 -> imovelComercial = 'N';
	casa342 -> numero = 342;
	apartamento17 -> numero = 17;
	apartamento17 -> complemento = "Predio, 4 andares, 182 m²";
	mercantil1 -> imovelComercial = 'N';
	casa342 -> complemento = "Casa, 284 m²";
	
	casa342 -> prox = apartamento17;
	apartamento17 -> prox = mercantil1;
	mercantil1 -> prox = NULL;
	
	imprimir();
	
	return 0;
}
 
