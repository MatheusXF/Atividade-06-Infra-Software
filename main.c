#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>


int p,c,n,b;
sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int *buffer;
pthread_mutex_t mutex;

void *producer(void *id)
{   
    int x = 0;
    int produto;

    while(1) {
        produto = (x * 2) + 1;
        x++;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = produto;
        printf("Produtor %d produzindo %d na posicao %d\n", *((int *)id),buffer[in],in);
        in = (in+1)%b;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        if (x > n)
            x = 0;
    }
}
void *consumer(void *id)
{   
    while(1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int produto = buffer[out];
        printf("Consumidor %d consumindo %d na posicao %d\n",*((int *)id),produto, out);
        out = (out+1)%b;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main()
{   
    scanf("%d %d %d %d",&p,&c,&n,&b);

    buffer = malloc(b * sizeof(int));
    pthread_t pro[p],con[c];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,b);
    sem_init(&full,0,0);

    int idProdutor[p], idConsumidor[c];
    for (int i =0; i < p; i++) {
        idProdutor[i] = i;
    }
    for (int i =0; i < c; i++) {
        idConsumidor[i] = i;
    }

    for(int i = 0; i < p; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&idProdutor[i]);
    }
    for(int i = 0; i < c; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&idConsumidor[i]);
    }

    for(int i = 0; i < p; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < c; i++) {
        pthread_join(con[i], NULL);
    }
    return 0;  
}