#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int buffer = 0;
sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg) {
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer++;
    printf("Produced: %d\n", buffer);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    return NULL;
}

void *consumer(void *arg) {
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    printf("Consumed: %d\n", buffer);
    buffer--;
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    return NULL;
}

int main() {
    pthread_t p, c;
    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}


/*gcc prog7.c -lpthread
./a.out*/
