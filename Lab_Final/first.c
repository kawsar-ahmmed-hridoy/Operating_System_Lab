/*Q1. Write a  multithreaded  program to compute the  sum of  an integer array  by splitting it into  two halves  . 
Use two threads to calculate the sum of each half independently. The main thread will combine the 
results and print the partial sums and the total. Ensure dynamic memory allocation for thread results to 
avoid undefined behavior.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>

int g,h;

typedef struct{
    int *a;
    int st,en;
}arr;

void *sum(void *arg){
    arr *b=(arr *)arg;
    int sum=0;

    for(int i=b->st;i<b->en;i++)sum+=b->a[i];

    if(b->st==0)g=sum;
    else h=sum;
}

int main(){

    int n;scanf("%d",&n);
    int *a=malloc(n*sizeof(int));

    for (int i=0;i<n;i++)scanf("%d",&a[i]);
    pthread_t th1,th2;
    int mid=n/2;

    arr fst={a,0,mid};
    arr snd={a,mid,n};

    pthread_create(&th1,NULL,sum,&fst);
    pthread_create(&th2,NULL,sum,&snd);

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    printf("Sum of the first half: %d\n",g);
    printf("Sum of the second half: %d\n",h);
    printf("Total sum: %d\n",g+h);
    
}
