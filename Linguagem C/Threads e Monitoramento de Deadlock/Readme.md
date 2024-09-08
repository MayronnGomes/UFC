# Programa com Threads e Monitoramento de Deadlock em C

Este programa em C cria várias threads que acessam e manipulam variáveis compartilhadas, protegidas por mutexes, para evitar condições de corrida. Uma thread de vigilância é usada para monitorar e identificar possíveis deadlocks no sistema.

## Funcionalidades

- **Criação de Threads**: Três threads executam tarefas que manipulam variáveis compartilhadas.
- **Proteção com Mutexes**: Mutexes são usados para proteger o acesso às variáveis compartilhadas.
- **Monitoramento de Deadlock**: Uma thread adicional verifica se as threads estão em um estado de deadlock e encerra o programa se necessário.

## Estrutura do Código

1. **Definição de Variáveis e Mutexes**:
   ```c
   #define MAX_TEXTO 1000

   static pthread_t t1;   // Identificador da thread t1
   static pthread_t t2;   // Identificador da thread t2 
   static pthread_t t3;   // Identificador da thread t3 
   static pthread_t vigia; // Identificador da thread vigia 

   static char texto1[MAX_TEXTO];
   static pthread_mutex_t mutex_texto1 = PTHREAD_MUTEX_INITIALIZER;

   static char texto2[MAX_TEXTO];
   static pthread_mutex_t mutex_texto2 = PTHREAD_MUTEX_INITIALIZER;

   static char texto3[MAX_TEXTO];
   static pthread_mutex_t mutex_texto3 = PTHREAD_MUTEX_INITIALIZER;

   static int cont1 = 0, cont2 = 0, cont3 = 0;
   static pthread_mutex_t mutex_cont1 = PTHREAD_MUTEX_INITIALIZER;
   static pthread_mutex_t mutex_cont2 = PTHREAD_MUTEX_INITIALIZER;
   static pthread_mutex_t mutex_cont3 = PTHREAD_MUTEX_INITIALIZER;
   ```
   Define variáveis compartilhadas e mutexes para sincronização.

2. **Funções de Tarefas**:
   - **Tarefa 1**: Manipula `texto1` e `texto2`.
     ```c
     static void codigo_tarefa_1(void) {
         for(int i = 0; i < 1000; i++) {
             pthread_mutex_lock(&mutex_texto1);
             printf("Tarefa 1 pegou o texto 1\n");
             strcpy(texto1, "qwerty111");
             sleep(1);
             
             pthread_mutex_lock(&mutex_texto2);
             printf("Tarefa 1 pegou o texto 2\n");
             strcpy(texto2, texto1);
             sleep(1);
             
             printf("Tarefa 1 vai soltar texto 2 e 1\n");
             pthread_mutex_unlock(&mutex_texto2);
             pthread_mutex_unlock(&mutex_texto1);
             
             pthread_mutex_lock(&mutex_cont1);
             cont1 = 0;
             pthread_mutex_unlock(&mutex_cont1);
         }
     }
     ```

   - **Tarefa 2**: Manipula `texto2` e `texto3`.
     ```c
     static void codigo_tarefa_2(void) {
         for(int i = 0; i < 1000; i++) {
             pthread_mutex_lock(&mutex_texto2);
             printf("Tarefa 2 pegou o texto 2\n");
             strcpy(texto2, "qwerty222");
             sleep(1);
             
             pthread_mutex_lock(&mutex_texto3);
             printf("Tarefa 2 pegou o texto 3\n");
             strcpy(texto3, texto2);
             sleep(1);
             
             printf("Tarefa 2 vai soltar texto 3 e 2\n");
             pthread_mutex_unlock(&mutex_texto3);
             pthread_mutex_unlock(&mutex_texto2);
             
             pthread_mutex_lock(&mutex_cont2);
             cont2 = 0;
             pthread_mutex_unlock(&mutex_cont2);
         }
     }
     ```

   - **Tarefa 3**: Manipula `texto3` e `texto1`.
     ```c
     static void codigo_tarefa_3(void) {
         for(int i = 0; i < 1000; i++) {
             pthread_mutex_lock(&mutex_texto3);
             printf("Tarefa 3 pegou o texto 3\n");
             strcpy(texto3, "qwerty333");
             sleep(1);
             
             pthread_mutex_lock(&mutex_texto1);
             printf("Tarefa 3 pegou o texto 1\n");
             strcpy(texto1, texto3);
             sleep(1);
             
             printf("Tarefa 3 vai soltar texto 1 e 3\n");
             pthread_mutex_unlock(&mutex_texto1);
             pthread_mutex_unlock(&mutex_texto3);
             
             pthread_mutex_lock(&mutex_cont3);
             cont3 = 0;
             pthread_mutex_unlock(&mutex_cont3);
         }
     }
     ```

   - **Tarefa Vigilante**: Monitora o sistema para detectar deadlocks.
     ```c
     static void codigo_tarefa_vigia(void) {
         while(1) {
             sleep(1);
             if ((cont1 == 2) || (cont2 == 3) || (cont3 == 4)) {
                 printf("O codigo entrou em um Deadlock\n");
                 exit(EXIT_FAILURE);
             }
             pthread_mutex_lock(&mutex_cont1);
             pthread_mutex_lock(&mutex_cont2);
             pthread_mutex_lock(&mutex_cont3);
             cont1++;
             cont2++;
             cont3++;
             pthread_mutex_unlock(&mutex_cont1);
             pthread_mutex_unlock(&mutex_cont2);
             pthread_mutex_unlock(&mutex_cont3);
         }
     }
     ```

3. **Função Principal**:
   ```c
   int main(void) {
       printf("Inicio\n");
   
       pthread_create(&t1, NULL, (void *) codigo_tarefa_1, NULL);
       pthread_create(&t2, NULL, (void *) codigo_tarefa_2, NULL);
       pthread_create(&t3, NULL, (void *) codigo_tarefa_3, NULL);
       pthread_create(&vigia, NULL, (void *) codigo_tarefa_vigia, NULL);
   
       pthread_join(t1, NULL);
       pthread_join(t2, NULL);
       pthread_join(t3, NULL);
       pthread_join(vigia, NULL);
   
       printf("Fim\n");
       return 0;
   }
   ```
   Cria e gerencia as threads, aguarda sua conclusão e exibe mensagens de início e fim.

## Como Usar

1. Compile o código com um compilador que suporte threads POSIX, como `gcc`:
   ```sh
   gcc -o monitoramento monitoramento.c -pthread
   ```

2. Execute o programa:
   ```sh
   ./monitoramento
   ```

3. O programa cria três threads que manipulam variáveis compartilhadas e uma thread de vigilância que monitora e verifica deadlocks.

## Observações

- Certifique-se de compilar com a flag `-pthread` para incluir a biblioteca de threads POSIX.
- O programa é projetado para ilustrar o uso de mutexes e a detecção de deadlocks em um ambiente de threads.
