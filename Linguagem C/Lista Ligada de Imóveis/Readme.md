# Código em C - Lista Ligada de Imóveis

Este programa em C implementa uma lista ligada simples para armazenar informações sobre imóveis em uma rua. A lista é impressa para exibir os números dos imóveis.

## Estrutura do Código

1. **Definição da Estrutura de Dados**:
   ```c
   #include <stdio.h>
   #include <stdlib.h>

   typedef struct ImoveisDaRua {
       char *complemento;
       char imovelComercial;
       int numero;
       struct ImoveisDaRua *prox;
   } IDR;

   IDR *inicio = NULL;
   ```

2. **Função para Imprimir a Lista**:
   ```c
   void imprimir() {
       IDR *aux = inicio;
       printf("\nImprimindo lista...\n");
       for (int i = 0; i < 3; i++) {
           printf("%d ", aux->numero);
           aux = aux->prox;
       }
       printf("\n");
   }
   ```

3. **Função Principal**:
   ```c
   int main() {
       IDR* casa342 = malloc(sizeof(IDR));
       inicio = casa342;
       IDR* apartamento17 = malloc(sizeof(IDR));
       casa342->imovelComercial = 'N';
       IDR* mercantil1 = malloc(sizeof(IDR));
       mercantil1->numero = 1;
       mercantil1->complemento = "Casa Comercial, 521 m²";
       apartamento17->imovelComercial = 'N';
       casa342->numero = 342;
       apartamento17->numero = 17;
       apartamento17->complemento = "Predio, 4 andares, 182 m²";
       mercantil1->imovelComercial = 'N';
       casa342->complemento = "Casa, 284 m²";
       
       casa342->prox = apartamento17;
       apartamento17->prox = mercantil1;
       mercantil1->prox = NULL;
       
       imprimir();
       
       return 0;
   }
   ```

## Descrição

- **Estrutura `IDR`**: Representa um imóvel com um número, um complemento, uma indicação se é comercial ou não, e um ponteiro para o próximo imóvel na lista.
- **Variável Global `inicio`**: Ponteiro para o início da lista ligada.
- **Função `imprimir`**: Imprime os números dos imóveis na lista, limitando a impressão aos três primeiros imóveis.
- **Função `main`**: Cria e inicializa três imóveis, estabelece as conexões entre eles e imprime a lista.

## Compilação e Execução

Compile o código usando um compilador C, como `gcc`:

```sh
gcc -o lista_imoveis lista_imoveis.c
```

Execute o programa:

```sh
./lista_imoveis
```

O programa cria uma lista de imóveis e imprime os números dos três primeiros imóveis.
