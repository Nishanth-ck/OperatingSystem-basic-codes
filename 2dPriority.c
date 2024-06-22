#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,p[20],bt[20],wt[20],tat[20],pr[20],i,j,temp,pos,total=0;
    float avg_wt, avg_tat;

    printf("\nEnter the number of processes(<20)\n");
    scanf("%d",&n);

    printf("\nEnter the process burst time and priority:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d] \n: ",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority : ");
        scanf("%d",&pr[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n;i++)
    {
        pos = i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos = j;
        }

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;

    for(i=1;i<n;i++)
    {
        wt[i] = 0;
        for(j=0;j<i;j++)
            wt[i] += bt[j];
        total += wt[i];
    }

    avg_wt = (float)total/n;
    total = 0;
    printf("\nProcess \t Priority \t Burst Time \t Waiting Time \t Turnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d", p[i],pr[i],bt[i], wt[i], tat[i]);
    }

    avg_tat = (float)total/n;

    printf("\n\nAverage Waiting Time : %f", avg_wt);
    printf("\n\nAverage Turnaround Time : %f", avg_tat);

    return 0;
}