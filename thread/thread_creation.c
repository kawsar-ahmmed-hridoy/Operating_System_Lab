#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

// to run: gcc thread_creation.c -o thread_creation -pthread
// ./thread_creation

void* childThread(){
    printf("This is childThread\n");// thread is nothing but function.
}

int main(){

    pthread_t th1; //this will store info about the thread.
    pthread_create(&th1, NULL, &childThread, NULL);

    printf("Main thread is ready to execute the childThread\n");

    pthread_join(th1, NULL);// It will pause main thread & execute child thread.

    printf("childThread execution finished\n");
    sleep(3); //just checking that it is working properly.

    return 0;
}