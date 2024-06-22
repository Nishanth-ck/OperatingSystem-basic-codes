#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;

    printf("\nEnter the total number of processes:\n");
    scanf("%d",&n);

    printf("\nEner the burst time of processes:\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d] : ",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0] = 0;
    for(i=1;i<n;i++)
    {
        wt[i] = 0;
        for(j=0;j<i;j++)
        wt[i] += bt[j];
    }

    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time:");
    for(i=0;i<n;i++)
    {
        tat[i] = bt[i]+wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    avwt = avwt/i;
    avtat = avtat/i;
    printf("\n\nAverage Waiting Time : %d",avwt);
    printf("\n\nAverage Turnaround Time : %d",avtat);
    return 0;

}