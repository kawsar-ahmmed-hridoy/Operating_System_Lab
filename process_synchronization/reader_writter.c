#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
pthread_mutex_t writeLock;   // Ensures mutual exclusion for writers

int rd_cnt=0; // check how many readers are reading.

void* reader(void* arg) {

    while(1){ // we can bound it by ensuring a fixed number

        pthread_mutex_lock(&mutex);

        rd_cnt++;
        if (rd_cnt == 1) {
            pthread_mutex_lock(&writeLock); // reading er somoy writter der lock kore dey.
        }
        pthread_mutex_unlock(&mutex);

        // Critical section (Reading)
        printf("%d Reader is reading...\n", rd_cnt);
        sleep(1);

        // Exit section
        pthread_mutex_lock(&mutex);

        rd_cnt--;
        if (rd_cnt == 0) {
            pthread_mutex_unlock(&writeLock); // ekhn writter likhte parbe.
        }
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    return NULL;
}

void* writer(void* arg) {

    while (1) {
        pthread_mutex_lock(&writeLock); // Writer locks the resource

        // Critical section (Writing)
        printf("Writer is writing...\n");
        sleep(2);

        pthread_mutex_unlock(&writeLock); // Unlock after writing

        sleep(2);
    }
    return NULL;
}

int main() {

    pthread_t r1, r2, w1;

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&writeLock, NULL);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&r2, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);

    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&writeLock);

    return 0;
}
