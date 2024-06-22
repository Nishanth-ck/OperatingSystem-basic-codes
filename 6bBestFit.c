#include<stdio.h>
#include<stdlib.h>

void bestFit(int blockSize[],int m,int processSize[],int n)
{
    int i,j,allocation[n];

    for(i=0;i<n;i++)
    {
        allocation[i] = -1;
    }

    for(i=0;i<n;i++)
    {
        int bestIdx = -1;

        for (j = 0; j < m;j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                    if(bestIdx == -1)
                        bestIdx = j;
                    else if(blockSize[bestIdx] > blockSize[j])
                        bestIdx = j;
            }
        }

        if(bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\t\tProcess Size\t\tBlock No.\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t",i+1,processSize[i]);
        if(allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
    int blockSize[] = { 100, 50, 25, 430, 600};
    int processSize[] = {20, 45, 100, 426};

    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    bestFit(blockSize,m,processSize,n);

    return 0;
}
