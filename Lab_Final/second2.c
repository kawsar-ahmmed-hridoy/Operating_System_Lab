/* Solve the following Critical Section problem with any synchronization technique.
# Solving with Mutex lock.*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;

int accountA = 500;
int accountB = 0;

void *transfer(void *arg)
{
    pthread_mutex_lock(&lock);
    int amount = *((int *)arg);
    if (accountA >= amount)
    {
        sleep(1);
        accountA -= amount;
        accountB += amount;
    }
    printf("Transfer %d: A=%d, B=%d (Total: %d)\n", amount, accountA, accountB, accountA + accountB);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);

    int amount1 = 100, amount2 = 500;

    pthread_create(&thread1, NULL, transfer, &amount1);
    pthread_create(&thread2, NULL, transfer, &amount2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final balances: A=%d, B=%d (Total: %d)\n", accountA, accountB, accountA + accountB);

    pthread_mutex_destroy(&lock);

    return 0;
}
