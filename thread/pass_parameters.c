#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char * status;
void* thread1(void *item){
    int x= *(int*)item;
    if(x%2)printf("Odd Number: %d\n",x);
    else printf("Even Number: %d\n",x);

    pthread_exit("Successfully executed.");
}

void* thread2(void *array){
    int *b=(int*)array;
    int x=0;
    for(int i=0;i<5;i++)x+=b[i];
    printf("The sum of the array is: %d\n", x);

    pthread_exit("Sum calculated successfully.");
}

struct item
{
    int x;
    char *y;
};

void* thread3(void *st){
    struct item *temp = (struct item*)st;
    printf("First: %d & Second: %s\n", temp->x, temp->y);

    pthread_exit("Structure worked successfully.");
}

int main(){

    printf("This is Main thread.\n");

    int n=5; //int n; cin>>n;
    int a[5]={5, 7, 10, 4, 2}; //for(i-->5)cin>>a[i];
    struct item str={17,"Hridoy"};

    pthread_t th1,th2,th3; 
    void *status;

    pthread_create(&th1, NULL, &thread1, (void *)&n); //passed value
    pthread_join(th1, &status);
    printf("Thread 1 status: %s\n", (char*)status);
    
    pthread_create(&th2, NULL, &thread2, (void *)a); //don't use &. passed array
    pthread_join(th2, &status);
    printf("Thread 2 status: %s\n", (char*)status);

    pthread_create(&th3, NULL, &thread3, (void *)&str); //passed struct
    pthread_join(th3, &status);
    printf("Thread 3 status: %s\n", (char*)status);

    printf("All threads execution are finished.\n");
    
    return 0;
}
