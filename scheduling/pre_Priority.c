#include <stdio.h>
#define N 4

int main() {

    //at[N]={0, 3, 2, 7};
    int bt[N] = {5, 3, 8, 6};
    int p[N]  = {2, 1, 4, 3};
    int rt[N];
    int wt[N] = {0}, tat[N];
    int pid[N], completed = 0;
    int cur_t = 0, prev = -1;

    for (int i = 0; i < N; i++) {
        pid[i] = i + 1;
        rt[i] = bt[i];
    }

    while (completed < N) {

        int idx = -1, highest_priority = 1e9;

        for (int i = 0; i < N; i++) {
            if (rt[i] > 0 && p[i] < highest_priority) { //logic at[i]<=cur_t &&
                highest_priority = p[i];
                idx = i;
            }
        }

        if (idx != -1) {
            rt[idx]--;
            cur_t++;

            if (rt[idx] == 0) {
                completed++;
                tat[idx] = cur_t; // tat[idx]-=at[idx];
                wt[idx] = tat[idx] - bt[idx];
                // if(wt[idx]<0)wt[idx]=0;
            }
        } else {
            cur_t++;
        }
    }

    float avg_wt = 0, avg_tat = 0;
    printf("Process_ID\tPriority\tBT\tWT\tTAT\n");

    for (int i = 0; i < N; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t\t%d\t\t%d\t%d\t%d\n", pid[i], p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt / N);
    printf("Average Turnaround Time: %.2f\n", avg_tat / N);

    return 0;
}
