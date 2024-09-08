#include<stdio.h>
#include<stdlib.h>

typedef struct vertice{
    int chave;
    struct vertice * dir;
    struct vertice * esq;
}VERTICE;


VERTICE * raiz = NULL;
int tam = 0;

VERTICE* buscar(int x, VERTICE *aux){
    if(aux == NULL){
        return NULL;
    }else if (x == aux->chave){
        return aux;
    }else if(x < aux->chave){
        if(aux->esq == NULL){
            return aux;
        }else{
            return buscar(x, aux->esq);
        }
    }else{
        if(aux->dir == NULL){
            return aux;
        }else{
            return buscar(x, aux->dir);
        }
    }
}

void adicionar(int chave){
   VERTICE* aux = buscar(chave, raiz);
    if(aux != NULL && aux->chave == chave){
        printf("insercao invalida!\n");
    }else{
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        if(aux == NULL){
            raiz = novo;
        }else if(chave < aux->chave){
            aux->esq = novo;
        }else{
            aux->dir = novo;
        }
    }
}

void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    
    printf("%d ", aux->chave);
    
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}

int alt_recursiva(VERTICE *aux) {
	if (aux == NULL) 
	 return -1;
	
	int alt_esq = alt_recursiva(aux->esq);
	int alt_dir = alt_recursiva(aux->dir);
	
	if(alt_esq > alt_dir)
	 return alt_esq + 1;
	else
  return alt_dir + 1;
	
}

int altura_no(int chave) {
	VERTICE *aux = buscar(chave, raiz);
	if(aux == NULL)
	 return -1;
	else
	 return alt_recursiva(aux);
}

int nivel_no(int chave) {
	
	int nivel = 0;
	VERTICE *aux_raiz = raiz;
	VERTICE *aux = buscar(chave, raiz);
 if(aux == NULL || chave != aux->chave)
	 return -1;
	
 for(nivel; aux_raiz->chave != aux->chave; nivel++){
 	if(aux_raiz->chave < aux->chave)
 	 aux_raiz = aux_raiz->dir;
 	else
 		aux_raiz = aux_raiz->esq;
 }
	 
	return nivel;
	 
}

int main(){

    adicionar(8);
    adicionar(3);
    adicionar(2);
    adicionar(1);
    adicionar(6);
    adicionar(4);
    adicionar(7);
    adicionar(10);
    adicionar(14);
    adicionar(13);
    adicionar(5);
    adicionar(9);
    adicionar(11);
    adicionar(12);
    adicionar(15);
    adicionar(16);
    adicionar(17);
    adicionar(18);
    adicionar(19);
    adicionar(20);
    
    
    printf("\nImprimindo arvore...\n");
    in_ordem(raiz);
    for(int i = 1; i<21; i++){
     printf("\nAltura do No %d: %d\nNivel do No %d: %d", i, altura_no(i), i, nivel_no(i));
    }
    
    return 0;
}



