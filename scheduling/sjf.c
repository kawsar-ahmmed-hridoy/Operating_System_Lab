#include<stdio.h>
#include<math.h>
//int MX=10;

int main(){

    int n=4;
    float avg_wt=0, avg_tat=0;
    int wt[4],tat[4];

    int p[4]={1, 2, 3, 4};
    int bt[4] = {2, 4, 3, 5};

    for(int i=0;i<n-1;i++){ //sorted according to brust time.
        for(int j=i+1;j<n;j++){
            if(bt[i]>bt[j]){

                int tmp=bt[i];
                bt[i]=bt[j];
                bt[j]=tmp;

                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }

    wt[0]=0;
    tat[0]=bt[0];

    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }

    printf("Process_ID\tWaiting_Time\tBrust_Time\tTurnaround_Time\n");

    for(int i=0;i<n;i++){

        avg_wt+=wt[i];
        avg_tat+=tat[i];

        printf("%d \t%d \t%d \t%d\n", p[i],wt[i],bt[i],tat[i]);
    }

    avg_wt/=4;
    avg_tat/=4;

    printf("Average waiting time: %f and Average turnaround time: %f\n", avg_wt, avg_tat);
}
