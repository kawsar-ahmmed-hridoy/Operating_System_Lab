#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5 

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty; // slot empty kina check korbe
sem_t full; // slot full kina check korbe
pthread_mutex_t mutex; 

void* producer(void* arg) {

    int item;
    for(int i=0;i<10;i++){ // We can use while(1). But it will produce infinite number.
        
        item=rand()%100; // produce a random item

        sem_wait(&empty); // wait for empty slot
        pthread_mutex_lock(&mutex); // Lock buffer

        buffer[in]=item;
        printf("Producer produced: %d\n", item);
        in=(in + 1)%SIZE;

        pthread_mutex_unlock(&mutex); // ekhn consumer er kaj hbe
        sem_post(&full); // signal that item is added

        sleep(1);
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {

    int item;
    for(int i=0;i<10;i++){
        sem_wait(&full); 
        pthread_mutex_lock(&mutex);

        item=buffer[out];
        printf("Consumer consumed: %d\n", item);
        out=(out+1)%SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(1);// by inreasing/decreasing this, we can increase/decrease 
        // numbers that will be consumed/produced.
    }
    pthread_exit(NULL);
}

int main() {
    
    pthread_t th1, th2;

    sem_init(&empty, 0, SIZE); // initially all are empty
    sem_init(&full, 0, 0);     // initially 0 slot is full
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&th1, NULL, producer, NULL);
    pthread_create(&th2, NULL, consumer, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

// we also can use functions instead of threads.