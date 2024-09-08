#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex_saldo = PTHREAD_MUTEX_INITIALIZER;

double saldo = 0.0;


void codigo_tarefa_1(void);
void codigo_tarefa_2(void);

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


