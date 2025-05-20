#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<semaphore.h>

int sharedMemory=1;
sem_t sm;

void* thread1(){

    sem_wait(&sm);
    
    int x=sharedMemory;
    printf("Current value of shared memory: %d\n",x);
    x++;
    printf("Current value of register: %d\n",x);
    sleep(1);
    sharedMemory=x;
    printf("Updated value of shared memory: %d\n",sharedMemory);

    sem_post(&sm);

}

void* thread2(){

    sem_wait(&sm);

    int x=sharedMemory;
    printf("Current value of shared memory: %d\n",x);
    x--;
    printf("Current value of register: %d\n",x);
    sleep(1);
    sharedMemory=x;
    printf("Updated value of shared memory: %d\n",sharedMemory);

    sem_post(&sm);
}

int main(){

    printf("Main thread.\n");

    sem_init(&sm, 0, 1);// first one address, second one (0 for thread, 1 2 3.. for processes), thrid one value of semaphore


    pthread_t th1,th2;
    pthread_create(&th1, NULL, &thread1, NULL);
    pthread_create(&th2, NULL, &thread2, NULL);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("Final value of shared memory is: %d\n", sharedMemory);
    sem_destroy(&sm);

    return 0;
}
