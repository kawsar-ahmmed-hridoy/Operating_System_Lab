#include<stdio.h>
#include<math.h>
//int MX=10;

int main(){

    int n=4; //can use scanf("%d",&n);
    float avg_wt=0, avg_tat=0;
    int wt[4],tat[4]; // can use user define input. initialize bt[MX];

    int bt[4] = {2, 4, 3, 5};

    wt[0]=0;
    tat[0]=bt[0];

    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }

    printf("Waiting_Time\tBrust_Time\tTurnaround_Time\n");

    for(int i=0;i<n;i++){

        avg_wt+=wt[i];
        avg_tat+=tat[i];

        printf("%d \t%d \t%d\n", wt[i],bt[i],tat[i]);
    }

    avg_wt/=4;
    avg_tat/=4;

    printf("Average waiting time: %f and Average turnaround time: %f\n", avg_wt, avg_tat);
}
