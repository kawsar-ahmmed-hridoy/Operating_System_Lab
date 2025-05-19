#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

void* childThread(){
    printf("This child thread will go no more.\n");
    sleep(10);
    printf("This wont be executed if cancel is called.");

    pthread_exit(NULL);
}

int main(){

    printf("Main thread.\n");
    pthread_t th1; 
    pthread_create(&th1, NULL, &childThread, NULL);
    sleep(2);

    pthread_cancel(th1);//child execution off hoye jabe.

    pthread_join(th1, NULL);

    printf("Cancellation ocurred.\n");

    return 0;
}
