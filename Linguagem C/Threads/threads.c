#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

#define	N_THREADS	5

int ERRO_TH = 404;
int SUCESSO_TH = 333;

typedef struct param_t 
{
	int nst, nt;
	char *nome;
}PARAM;

void codigo_tarefa(struct param_t *PARAM);

int main(void)
{
	pthread_t vetor[N_THREADS];
 PARAM THREADS[N_THREADS];
 char *nomes[N_THREADS] = {"Penta", "campeao","Fortaleza", "esporte", "clube"}; 
 int *retorno [N_THREADS];

 for(int i = 0; i < N_THREADS; i++)
 {
  THREADS[i].nome = nomes[i];
  THREADS[i].nst = 10;
  THREADS[i].nt = i+1;
 }

	printf("Inicio\n");

	for(int i = 0; i < N_THREADS; i++)
 {
		pthread_create(&vetor[i], NULL, (void *) codigo_tarefa, (void *) &THREADS[i]);
 }
	
	for(int i = 0; i < N_THREADS; i++)
 {
		pthread_join(vetor[i], (void **) &retorno[i]);
 }

 for(int i = 0; i < N_THREADS; i++)
 {
  printf("\nTarefa %d - %s - retornou %d", i+1, THREADS[i].nome, *retorno[i]);
 }

	printf("\n\nFim\n");
	return(0);
}

void codigo_tarefa(struct param_t *PARAM)
{
 
	for( int ns = 0; ns < 10; ns++)
 {
		sleep(1);
		printf("Tarefa %d - %s: passaram %d segundos\n", PARAM->nt, PARAM->nome, ns+1);
	}

 if(isupper(PARAM->nome[0]) != 0)
 {
  pthread_exit(&SUCESSO_TH);
 }
 else
 {
  pthread_exit(&ERRO_TH);
 }
 
}