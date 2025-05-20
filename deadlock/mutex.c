#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int sharedMemory=1;
pthread_mutex_t mtx;

void* thread1(){

    printf("Thread1 is trying to acquire lock\n");
    pthread_mutex_lock(&mtx);
    printf("Thread1 acquired lock\n");

    int x=sharedMemory;
    printf("Current value of shared memory: %d\n",x);
    x++;
    printf("Current value of register: %d\n",x);
    sleep(1);
    sharedMemory=x;
    printf("Updated value of shared memory: %d\n",sharedMemory);

    pthread_mutex_unlock(&mtx);
    printf("Thread1 released lock\n");

}

void* thread2(){

    printf("Thread2 is trying to acquire lock\n");
    pthread_mutex_lock(&mtx);
    printf("Thread2 acquired lock\n");

    int x=sharedMemory;
    printf("Current value of shared memory: %d\n",x);
    x--;
    printf("Current value of register: %d\n",x);
    sleep(1);
    sharedMemory=x;
    printf("Updated value of shared memory: %d\n",sharedMemory);

    pthread_mutex_unlock(&mtx);
    printf("Thread2 released lock\n");

}

int main(){

    printf("Main thread.\n");

    pthread_mutex_init(&mtx, NULL);

    pthread_t th1,th2;
    pthread_create(&th1, NULL, &thread1, NULL);
    pthread_create(&th2, NULL, &thread2, NULL);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("Final value of shared memory is: %d\n", sharedMemory);
    pthread_mutex_destroy(&mtx);

    return 0;
}

