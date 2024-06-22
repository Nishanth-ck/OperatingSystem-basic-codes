#include<stdio.h>
#include<stdlib.h>

void firstFit(int blockSize[],int m,int processSize[],int n)
{
    int i,j,allocation[n];

    for (i = 0; i < n;i++)
    {
        allocation[i] = -1;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\t\tProcess Size\t\tBlock No.\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t\t\t%d\t\t\t", i + 1, processSize[i]);
        if(allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated\n");
        printf("\n");
    }
}

int main()
{
    int blockSize[] = {100,500,200,300,50};
    int processSize[] = {212, 190, 112, 250, 400};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize,m,processSize,n);

    return 0;
}