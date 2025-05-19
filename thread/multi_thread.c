#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void* thread1(){
    printf("Thread 1\n");
    for(int i=1;i<=5;i++){
        printf("%d\n",i);
        sleep(1); // sleep kom beshi dile duita parallelly execute hbe.
    }
    pthread_exit(NULL);//no necessary. as void always return NULL.
}

void* thread2(){
    printf("Thread 2\n");
    char s[]="Hridoy";
    for(int i=0;i<=5;i++){
        printf("%c\n",s[i]);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){

    printf("This is Main thread.\n");
    pthread_t th1,th2; 
    
    pthread_create(&th1, NULL, &thread1, NULL);// argument pathaile second null e argument address hbe.
    pthread_join(th1, NULL);// It will pause main thread & execute child thread.
    
    pthread_create(&th2, NULL, &thread2, NULL);
    pthread_join(th2, NULL);

    printf("Both thread execution is finished.\n");
    
    return 0;
}
