#include <stdio.h>
#define N 4

int main() {

    int bt[N]={5, 3, 8, 6};
    int p[N]={2, 1, 4, 3}; //Lower number means higher priority
    int wt[N]={0},tat[N],pid[N];

    for(int i=0;i<N;i++)pid[i]=i+1;

    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            if(p[j]<p[i]){

                int temp=p[i];
                p[i]=p[j];
                p[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                
                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;

            }
        }
    }

    for(int i=1;i<N;i++) wt[i]=wt[i-1]+bt[i-1];

    for(int i=0;i<N;i++) tat[i]=wt[i]+bt[i];

    float avg_wt = 0, avg_tat = 0;

    printf("Process_ID\tPriority\tBurst_Time\tWaiting_Time\tTurnaround_Time\n");
    
    for(int i=0;i<N;i++){

        avg_wt+=wt[i];
        avg_tat+=tat[i];

        printf("%d\t%d\t\t%d\t%d\t%d\n", pid[i], p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f\n", avg_wt/N);
    printf("Average Turnaround Time: %f\n", avg_tat/N);
    
    return 0;
}
