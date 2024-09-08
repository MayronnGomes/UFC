# Árvore Binária de Busca

Este projeto consiste em um programa em C que implementa uma árvore binária de busca. O programa permite a inserção de nós, a impressão da árvore em ordem, e calcula a altura e o nível de cada nó na árvore.

## Funcionalidades

- **Adicionar Nó**: Insere um novo nó na árvore binária de busca.
- **Imprimir em Ordem**: Imprime os valores dos nós da árvore em ordem crescente.
- **Calcular Altura**: Calcula a altura de um nó específico.
- **Calcular Nível**: Calcula o nível (profundidade) de um nó específico.

## Estrutura do Código

1. **Definição da Estrutura**:
   ```c
   typedef struct vertice {
       int chave;
       struct vertice *dir;
       struct vertice *esq;
   } VERTICE;
   ```
   Define um nó da árvore binária com uma chave e ponteiros para os filhos direito e esquerdo.

2. **Função `buscar`**:
   Procura um nó com a chave especificada e retorna o nó encontrado ou NULL se não existir.

3. **Função `adicionar`**:
   Adiciona um novo nó com a chave fornecida à árvore binária de busca. Exclui a inserção se a chave já existir.

4. **Função `in_ordem`**:
   Imprime os valores dos nós da árvore em ordem crescente.

5. **Função `alt_recursiva`**:
   Calcula a altura de um nó usando uma abordagem recursiva.

6. **Função `altura_no`**:
   Calcula a altura de um nó específico.

7. **Função `nivel_no`**:
   Calcula o nível (profundidade) de um nó específico.

8. **Função `main`**:
   Insere vários nós na árvore e exibe a árvore em ordem. Calcula e imprime a altura e o nível de cada nó.

## Como Usar

1. Compile o código com um compilador C. Por exemplo, usando `gcc`:
   ```sh
   gcc -o arvore ABB.c
   ```

2. Execute o programa:
   ```sh
   ./arvore
   ```

3. O programa imprimirá a árvore em ordem e exibirá a altura e o nível dos nós de 1 a 20.

## Exemplo de Saída

```
Imprimindo arvore...
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
Altura do No 1: 0
Nivel do No 1: 0
Altura do No 2: 1
Nivel do No 2: 1
...
Altura do No 20: 4
Nivel do No 20: 4
```

Neste exemplo, a árvore é impressa em ordem e para cada nó, a altura e o nível são exibidos.

## Observações

- O programa assume que os valores inseridos são únicos.
- O código pode ser modificado para tratar outros casos de uso ou para adicionar novas funcionalidades.
