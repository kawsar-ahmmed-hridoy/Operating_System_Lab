#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
int sharedMemory=1;
void* thread1(){
    int x=sharedMemory;
    printf("Current value of shared memory: %d\n",x);
    x++;
    printf("Current value of register: %d\n",x);
    sleep(1);
    sharedMemory=x;
    printf("Current value of shared memory: %d\n",sharedMemory);
    pthread_exit(NULL);
}

void* thread2(){
    int x=sharedMemory;
    printf("Current value of shared memory: %d\n",x);
    x--;
    printf("Current value of register: %d\n",x);
    sleep(1);
    sharedMemory=x;
    printf("Current value of shared memory: %d\n",sharedMemory);
    pthread_exit(NULL);
}

int main(){

    printf("Main thread.\n");
    pthread_t th1,th2;

    pthread_create(&th1, NULL, &thread1, NULL);
    pthread_create(&th2, NULL, &thread2, NULL);
    
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("Final value of shared memory is: %d\n", sharedMemory);

    return 0;
}

//The race condition returns either 0 or 2. To handle this so that
// multiple result could come, we use deadlock(mutex lock, semaphor)