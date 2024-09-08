# Código em C - Manipulação de Saldo com Threads

Este programa em C utiliza threads e mutexes para manipular um valor de saldo compartilhado de forma segura. O saldo é alterado por duas tarefas diferentes, e o programa imprime o saldo inicial e final após a execução das threads.

## Estrutura do Código

1. **Definição das Variáveis e Mutex**:
   ```c
   #include <stdio.h>
   #include <unistd.h>
   #include <pthread.h>
   #include <stdlib.h>

   pthread_mutex_t mutex_saldo = PTHREAD_MUTEX_INITIALIZER;

   double saldo = 0.0;
   ```

2. **Funções de Tarefa**:
   ```c
   void codigo_tarefa_1(void);
   void codigo_tarefa_2(void);

   void codigo_tarefa_1(void)
   {
       double saldo_velho;
       double saldo_novo;
       sleep(1);

       for(int ns = 0; ns < 10; ns++) 
       {
           pthread_mutex_lock(&mutex_saldo);

           if(saldo < 20)
           {
               saldo = saldo - saldo;
           }
           else
           {
               saldo_velho = saldo;
               saldo_novo = saldo_velho - 20;
               printf("Saldo passou de %0.2lf para o valor de %0.2lf\n", saldo_velho, saldo_novo);
               saldo = saldo_novo;
           }    
           pthread_mutex_unlock(&mutex_saldo);
       }
   }

   void codigo_tarefa_2(void)
   {
       double saldo_velho;
       double saldo_novo;
       sleep(1);
       
       for(int ns = 0; ns < 10; ns++) 
       {
           pthread_mutex_lock(&mutex_saldo);    
           saldo_velho = saldo;
           saldo_novo = saldo_velho + 20;
           printf("Saldo passou de %0.2lf para o valor de %0.2lf\n", saldo_velho, saldo_novo);
           saldo = saldo_novo;
           pthread_mutex_unlock(&mutex_saldo);    
       }
   }
   ```

3. **Função Principal**:
   ```c
   int main(void)
   {
       printf("Inicio\n");
       printf("Saldo inicial %0.2lf\n", saldo);

       pthread_t vetor[8];

       for(int i = 0; i < 8; i++)
       {
           if(i < 4)
           {
               pthread_create(&(vetor[i]), NULL, (void *) codigo_tarefa_2, NULL);
           }
           else
           {
               pthread_create(&(vetor[i]), NULL, (void *) codigo_tarefa_1, NULL);
           }
       }
       
       for(int i = 0; i < 8; i++)
       {
           pthread_join(vetor[i], NULL);
       }

       printf("Saldo final ficou %0.2lf\n", saldo);
       printf("Fim\n");
       return(0);
   }
   ```

## Descrição

- **Variáveis Globais**:
  - `saldo`: Valor compartilhado entre threads.
  - `mutex_saldo`: Mutex para garantir acesso seguro ao saldo.

- **Funções de Tarefa**:
  - `codigo_tarefa_1()`: Decrementa o saldo em 20 unidades, se possível.
  - `codigo_tarefa_2()`: Incrementa o saldo em 20 unidades.

- **Função Principal**:
  - Cria 8 threads: as primeiras 4 threads executam `codigo_tarefa_2`, e as últimas 4 threads executam `codigo_tarefa_1`.
  - Aguarda a conclusão das threads e imprime o saldo final.

## Compilação e Execução

Compile o código usando um compilador C, como `gcc`:

```sh
gcc -o manipulacao_saldo manipulacao_saldo.c -lpthread
```

Execute o programa:

```sh
./manipulacao_saldo
```

O programa cria threads que alteram o saldo e imprime o saldo inicial e final.
