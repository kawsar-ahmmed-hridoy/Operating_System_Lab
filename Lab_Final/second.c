/* Solve the following Critical Section problem with any synchronization technique.
# Solving with Semaphore.*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t s;

int accountA = 500;
int accountB = 0;
void *transfer(void *arg)
{
    sem_wait(&s);
    int amount = *((int *)arg);
    if (accountA >= amount)
    {
        sleep(1);
        accountA -= amount;
        accountB += amount;
    }
    printf("Transfer %d: A=%d, B=%d (Total: %d)\n",amount, accountA, accountB, accountA + accountB);
    sem_post(&s);
    
}

int main()
{
    pthread_t thread1, thread2;
    sem_init(&s,0,1);
    int amount1 = 100, amount2 = 500;

    pthread_create(&thread1, NULL, transfer, &amount1);
    pthread_create(&thread2, NULL, transfer, &amount2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final balances: A=%d, B=%d (Total: %d)\n",accountA, accountB, accountA + accountB);
    sem_destroy(&s);
    
}
