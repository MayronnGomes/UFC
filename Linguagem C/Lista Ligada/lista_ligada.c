#include <stdio.h>
#include <stdlib.h>
 
typedef struct no{
	int valor;
	struct no*prox;
}NO;
 
int tam = 0;
NO*inicio = NULL;
NO*fim = NULL;
 
int media(int tam)
{
	
	NO*aux = inicio;
	int soma = 0;
	for (int i = 0 ; i < tam -1 ; i++)
	{
		
		soma += aux -> valor;
		aux = aux -> prox;
		
	}
	
	return soma / (tam - 1);
	
}
 
void adicionar(int valor, int pos)
{
	
	if(pos >= 0 && pos <= tam)
	{
		
		NO*NOVO = malloc(sizeof(NO));
		NOVO -> valor = valor;
		NOVO -> prox = NULL;
		
		if (inicio == NULL)
		{
			
			inicio = NOVO;
			fim = NOVO;
			
		}
		else if (pos == 0)
		{
			
			NOVO -> prox = inicio;
			inicio = NOVO;
			
		}
		else if (pos == tam)
		{
			
			fim -> prox = NOVO;
			fim = NOVO;
			
		}
		else
		{
			
			NO*aux = inicio;
			for (int i = 0 ; i < pos - 1 ; i++)
			{
				
				aux = aux -> prox;
				
			}
			
			NOVO -> prox = aux -> prox;
			aux -> prox = NOVO;
			
		}
		
		tam++;
		if (tam > 1)
		{
			
		fim -> valor = media(tam);
		
		}
		
	}
	
}

void imprimir()
{
	
	NO*aux = inicio;
	printf("Imprimindo a Lista...\n");
	for (int i = 0 ; i < tam - 1 ; i++)
	{
		
		printf("%d ", aux -> valor);
		aux = aux -> prox;
		
	}
	
}

int busca()
{
	
	NO*aux = inicio;
	for (int i = 0 ; i < tam - 1 ; i++)
	{
		
		if (aux -> valor == fim -> valor)
		{
			
			return fim -> valor;
			
		}
		
		aux = aux -> prox;
		
	}
	
	return -1;
	
}

int main()
{
	
	adicionar (2, 0);
	adicionar (21, 0);
	adicionar (4, 1);
	adicionar (50, 3);
	imprimir();
	printf("\n\n%d", busca());
	return 0;
	
}
 
