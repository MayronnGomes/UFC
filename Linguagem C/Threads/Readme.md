# Programa com Threads em C

Este projeto é um programa em C que utiliza threads para executar tarefas simultâneas. Cada thread executa uma tarefa que imprime o tempo decorrido e verifica se o nome da tarefa começa com uma letra maiúscula. Dependendo da verificação, a thread retorna um código de sucesso ou erro.

## Funcionalidades

- **Criação de Threads**: Cria múltiplas threads para executar tarefas simultaneamente.
- **Execução de Tarefas**: Cada thread imprime uma mensagem a cada segundo e verifica a condição do nome.
- **Coleta de Resultados**: Coleta e exibe os resultados de cada thread após a execução.

## Estrutura do Código

1. **Definição de Constantes e Estruturas**:
   ```c
   #define N_THREADS 5

   int ERRO_TH = 404;
   int SUCESSO_TH = 333;

   typedef struct param_t {
       int nst, nt;
       char *nome;
   } PARAM;
   ```
   Define constantes para códigos de erro e sucesso, além de uma estrutura para parâmetros das threads.

2. **Função `codigo_tarefa`**:
   ```c
   void codigo_tarefa(struct param_t *PARAM)
   {
       for(int ns = 0; ns < 10; ns++) {
           sleep(1);
           printf("Tarefa %d - %s: passaram %d segundos\n", PARAM->nt, PARAM->nome, ns+1);
       }
       if(isupper(PARAM->nome[0]) != 0) {
           pthread_exit(&SUCESSO_TH);
       } else {
           pthread_exit(&ERRO_TH);
       }
   }
   ```
   Executa a tarefa da thread, imprimindo mensagens e verificando se o nome da tarefa começa com uma letra maiúscula.

3. **Função `main`**:
   ```c
   int main(void)
   {
       pthread_t vetor[N_THREADS];
       PARAM THREADS[N_THREADS];
       char *nomes[N_THREADS] = {"Penta", "campeao", "Fortaleza", "esporte", "clube"};
       int *retorno[N_THREADS];

       for(int i = 0; i < N_THREADS; i++) {
           THREADS[i].nome = nomes[i];
           THREADS[i].nst = 10;
           THREADS[i].nt = i+1;
       }

       printf("Inicio\n");

       for(int i = 0; i < N_THREADS; i++) {
           pthread_create(&vetor[i], NULL, (void *) codigo_tarefa, (void *) &THREADS[i]);
       }

       for(int i = 0; i < N_THREADS; i++) {
           pthread_join(vetor[i], (void **) &retorno[i]);
       }

       for(int i = 0; i < N_THREADS; i++) {
           printf("\nTarefa %d - %s - retornou %d", i+1, THREADS[i].nome, *retorno[i]);
       }

       printf("\n\nFim\n");
       return 0;
   }
   ```
   Cria e gerencia as threads, coleta seus resultados e exibe informações sobre cada tarefa.

## Como Usar

1. Compile o código com um compilador que suporte threads POSIX, como `gcc`:
   ```sh
   gcc -o threads threads.c -pthread
   ```

2. Execute o programa:
   ```sh
   ./threads
   ```

3. O programa criará cinco threads, cada uma executando uma tarefa e imprimindo o tempo decorrido. Após a execução, os resultados de cada thread serão exibidos.

## Exemplo de Saída

```
Inicio
Tarefa 1 - Penta: passaram 1 segundos
Tarefa 1 - Penta: passaram 2 segundos
...
Tarefa 5 - clube: passaram 10 segundos

Tarefa 1 - Penta - retornou 333
Tarefa 2 - campeao - retornou 404
...
Tarefa 5 - clube - retornou 404

Fim
```

Neste exemplo, as threads imprimem o tempo decorrido e retornam um código dependendo se o nome da tarefa começa com uma letra maiúscula.

## Observações

- Certifique-se de compilar com a flag `-pthread` para incluir a biblioteca de threads POSIX.
- O programa foi projetado para fins educacionais e pode ser adaptado para outras aplicações que envolvem threads.
