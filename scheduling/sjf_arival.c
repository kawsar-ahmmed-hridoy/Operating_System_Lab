#include <stdio.h>
#include<math.h>
const int N=4;

int main(){

    int p[4]={1, 2, 3, 4}, at[4]={0, 2, 4, 5}, bt[4]={2, 4, 3, 5};
    int ct[N], wt[N], tat[N], done[N];
    int completed=0, cur_t=0;
    float avg_wt=0, avg_tat=0;

    for(int i=0;i<N;i++)done[i]=0;

    while(completed<N){
        int idx=-1,min_bt=1e9;

        for(int i=0;i<N;i++){
            if(!done[i] && at[i]<=cur_t && bt[i]<min_bt){
                min_bt=bt[i];
                idx=i;
            }
        }

        if(idx!=-1){
            wt[idx]=cur_t-at[idx];
            if(wt[idx]<0)wt[idx]=0;

            ct[idx]=cur_t+bt[idx];
            tat[idx]=ct[idx]-at[idx];

            cur_t=ct[idx];
            done[idx]=1;
            completed++;
        }else{
            cur_t++;
        }
    }

    printf("Process_ID\tArrival_Time\tBurst_Time\tWaiting_Time\tTurnaround_Time\n");

    for(int i=0;i<N;i++){

        avg_wt+=wt[i];
        avg_tat+=tat[i];

        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }

    avg_wt /= N;
    avg_tat /= N;

    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);

    return 0;
}
