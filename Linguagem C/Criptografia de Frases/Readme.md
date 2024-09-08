# Criptografia de Frase

Este projeto consiste em um programa em C que criptografa uma frase invertendo as consoantes e preservando as vogais e caracteres não alfabéticos em suas posições originais.

## Funcionalidades

- **Adicionar Caracteres**: Adiciona caracteres à estrutura de lista encadeada.
- **Criptografar Frase**: Processa uma string de entrada, invertendo as consoantes e mantendo a ordem das vogais e caracteres não alfabéticos.
- **Imprimir Resultado**: Exibe a frase criptografada.

## Estrutura do Código

1. **Definição da Estrutura**:
   ```c
   typedef struct no {
       char caract;
       struct no *prox;
   } NO;
   ```
   Define um nó da lista encadeada que contém um caractere e um ponteiro para o próximo nó.

2. **Função `adicionar`**:
   Adiciona um novo caractere ao final da lista encadeada.

3. **Função `fila`**:
   Processa a string de entrada e adiciona cada caractere à lista encadeada.

4. **Função `imprimir`**:
   Imprime a frase criptografada com as consoantes invertidas.

5. **Função `main`**:
   Solicita ao usuário uma frase, a processa e imprime o resultado criptografado.

## Como Usar

1. Compile o código com um compilador C. Por exemplo, usando `gcc`:
   ```sh
   gcc -o criptografia criptografia.c
   ```

2. Execute o programa:
   ```sh
   ./criptografia
   ```

3. Digite a frase a ser criptografada (máximo de 120 caracteres) quando solicitado.

## Exemplo de Uso

```
Informe a frase a ser criptografada (max 120 caracteres): hello world
frase criptografada: holle wrold
```

Neste exemplo, as consoantes foram invertidas, enquanto as vogais e espaços foram preservados.

## Observações

- O programa suporta apenas entradas de até 120 caracteres.
- O código assume que a entrada contém apenas caracteres ASCII.
