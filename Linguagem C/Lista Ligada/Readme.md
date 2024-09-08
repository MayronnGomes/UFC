# Código em C - Lista Ligada

Este programa em C implementa uma lista ligada simples com operações básicas como adição de elementos, cálculo da média dos valores e busca de um valor na lista.

## Estrutura do Código

1. **Definição da Estrutura de Dados e Variáveis Globais**:
   ```c
   #include <stdio.h>
   #include <stdlib.h>
   
   typedef struct no {
       int valor;
       struct no* prox;
   } NO;
   
   int tam = 0;
   NO* inicio = NULL;
   NO* fim = NULL;
   ```

2. **Função para Calcular a Média dos Valores**:
   ```c
   int media(int tam) {
       NO* aux = inicio;
       int soma = 0;
       for (int i = 0; i < tam - 1; i++) {
           soma += aux->valor;
           aux = aux->prox;
       }
       return soma / (tam - 1);
   }
   ```

3. **Função para Adicionar um Elemento na Lista**:
   ```c
   void adicionar(int valor, int pos) {
       if (pos >= 0 && pos <= tam) {
           NO* NOVO = malloc(sizeof(NO));
           NOVO->valor = valor;
           NOVO->prox = NULL;
           
           if (inicio == NULL) {
               inicio = NOVO;
               fim = NOVO;
           } else if (pos == 0) {
               NOVO->prox = inicio;
               inicio = NOVO;
           } else if (pos == tam) {
               fim->prox = NOVO;
               fim = NOVO;
           } else {
               NO* aux = inicio;
               for (int i = 0; i < pos - 1; i++) {
                   aux = aux->prox;
               }
               NOVO->prox = aux->prox;
               aux->prox = NOVO;
           }
           
           tam++;
           if (tam > 1) {
               fim->valor = media(tam);
           }
       }
   }
   ```

4. **Função para Imprimir a Lista**:
   ```c
   void imprimir() {
       NO* aux = inicio;
       printf("Imprimindo a Lista...\n");
       for (int i = 0; i < tam - 1; i++) {
           printf("%d ", aux->valor);
           aux = aux->prox;
       }
   }
   ```

5. **Função para Buscar um Valor na Lista**:
   ```c
   int busca() {
       NO* aux = inicio;
       for (int i = 0; i < tam - 1; i++) {
           if (aux->valor == fim->valor) {
               return fim->valor;
           }
           aux = aux->prox;
       }
       return -1;
   }
   ```

6. **Função Principal**:
   ```c
   int main() {
       adicionar(2, 0);
       adicionar(21, 0);
       adicionar(4, 1);
       adicionar(50, 3);
       imprimir();
       printf("\n\n%d", busca());
       return 0;
   }
   ```

## Descrição

- **Estrutura `NO`**: Representa um nó na lista ligada, contendo um valor e um ponteiro para o próximo nó.
- **Variáveis Globais**: `inicio` e `fim` são ponteiros para o início e o fim da lista, respectivamente. `tam` mantém o número de elementos na lista.
- **Função `media`**: Calcula a média dos valores da lista (exceto o último elemento).
- **Função `adicionar`**: Adiciona um novo valor na posição especificada e atualiza o valor do último nó com a média dos valores da lista.
- **Função `imprimir`**: Imprime todos os valores da lista.
- **Função `busca`**: Busca o valor do último nó na lista e retorna esse valor se encontrado, ou -1 se não encontrado.

## Compilação e Execução

Compile o código usando um compilador C, como `gcc`:

```sh
gcc -o lista_ligada lista_ligada.c
```

Execute o programa:

```sh
./lista_ligada
```

O programa adiciona alguns valores à lista, imprime a lista e realiza uma busca pelo valor do último nó.
