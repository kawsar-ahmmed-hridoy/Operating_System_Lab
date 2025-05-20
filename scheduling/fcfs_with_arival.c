#include<stdio.h>
#include<math.h>
//int MX=10;

int main(){

    int n=4;
    float avg_wt=0, avg_tat=0;
    int wt[4],tat[4],temp[5];

    int at[4]={0, 3, 3, 5}; //we can take them as input.
    int bt[4]={2, 4, 3, 5};

    temp[0]=at[0];

    for(int i=0;i<n;i++){

        wt[i]=0;
        tat[i]=0;

        if(temp[i]<at[i])temp[i]=at[i]; //max
        wt[i]= temp[i]-at[i];
        tat[i]=wt[i]+bt[i];

        temp[i+1]=temp[i]+bt[i];

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
