#include <stdio.h>

#define N 5

int main() {

    int p[N] = {1, 2, 3, 4, 5};
    int at[N] = {0, 3, 3, 8, 13};
    int bt[N] = {10, 6, 4, 3, 5};
    int rt[N];

    int wt[N] = {0}, tat[N] = {0}, ct[N] = {0};
    int done = 0, cur_t = 0, tq = 4;
    float avg_wt = 0, avg_tat = 0;

    for (int i = 0; i < N; i++) {
        rt[i] = bt[i];
    }

    while (done < N) {
        int cng = 0;
        for (int i = 0; i < N; i++) {
            if (at[i] <= cur_t && rt[i] > 0) {
                cng = 1;
                if (rt[i] > tq) {
                    cur_t += tq;
                    rt[i] -= tq;
                } else {
                    cur_t += rt[i];
                    wt[i] = cur_t - at[i] - bt[i];
                    rt[i] = 0;
                    ct[i] = cur_t;
                    tat[i] = ct[i] - at[i];
                    done++;
                }
            }
        }

        if (!cng)
            cur_t++;
    }

    printf("Process_ID\tArrival_Time\tBurst_Time\tWaiting_Time\tTurnaround_Time\n");
    for (int i = 0; i < N; i++) {

        avg_wt += wt[i];
        avg_tat += tat[i];

        printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    avg_wt /= N;
    avg_tat /= N;

    printf("\nAverage Waiting Time: %f\n", avg_wt);
    printf("Average Turnaround Time: %f\n", avg_tat);

    return 0;
}
