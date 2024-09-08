#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    
    char caract;
    struct no * prox;
    
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;

void adicionar(char c)
{    

    NO * novo = malloc(sizeof(NO));
    novo->caract = c;
    novo->prox = NULL;
                
    if(inicio == NULL){
          
        inicio = novo;
        fim = novo;

    }else if(tam > 0){
            
        fim->prox = novo;
        fim = novo;
    }

    tam++;
    
}

void fila(char *frase) 
{
    for(int i = 0; frase[i] != '\0' ; i++)
    {
        adicionar(frase[i]);
    }
}

void imprimir() 
{
    char consoante[119];
    int count = 0;
    printf("\nfrase criptografada: ");
    for(int i = 0; i<tam ; i++)
    {
        if(inicio->caract >= 'a' && inicio->caract <='z')
        {
            if(inicio->caract == 'a' || inicio->caract == 'e' || inicio->caract == 'i' || inicio->caract == 'o' || inicio->caract == 'u')
            {
                if(count > 0)
                {
                    for(int j = (count - 1); j>=0 ; j--)
                        printf("%c", consoante[j]);
                }
                printf("%c", inicio->caract);
                count = 0;
            }else{
                consoante[count] = inicio->caract;
                count++;
            }
        }else{
            if(count > 0)
                {
                    for(int j = (count - 1); j>=0 ; j--)
                        printf("%c", consoante[j]);
                }
            printf("%c", inicio->caract);
            count = 0;
        }
        inicio = inicio->prox;
    }
}

int main()
{
    char frase[120];
    printf("Informe a frase a ser criptografada (max 120 caracteres): ");
    scanf("%119[^\n]", frase);

    fila(frase);
    imprimir();

    return 0;
}

