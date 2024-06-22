#include<stdio.h>
#include<stdlib.h>

int main()
{
    int MAX[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
    int i, j, p, r, count, process;
    count = 0;

    printf("\nEnter the number of processes:\n");
    scanf("%d", &p);

    for (i = 0; i < p;i++)
        completed[i] = 0;

    printf("\n\nEnter the number of resources:\n");
    scanf("%d", &r);

    printf("\n\nEnter the Max Matrix for each process:\n");
    for (i = 0; i < p;i++)
    {
        printf("\nEnter process %d :", i + 1);
        for (j = 0; j < r;j++)
            scanf("%d", &MAX[i][j]);
    }

    printf("\n\nEnter the Allocation for each process:\n");
    for (i = 0; i < p;i++)
    {
        printf("\nEnter process %d :", i + 1);
        for (j = 0; j < r;j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("\n\nEnter the available resources:\n");
    for (i = 0; i < r;i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < p;i++)
        for (j = 0;j<r;j++)
            need[i][j] = MAX[i][j] - alloc[i][j];


    do
    {
        printf("\nMax Matrix: \t Allocation Matrix : \n");
        for(i=0;i<p;i++)
        {
            for (j = 0;j<r;j++)
                printf("%d", MAX[i][j]);
            printf("\t\t");

            for (j = 0; j < r;j++)
                printf("%d", alloc[i][j]);
            printf("\n");
        }

        process = -1;

        for (i = 0; i < p;i++)
        {
            if(completed[i]==0)
            {
                process = i;
                for (j = 0; j < r;j++)
                {
                    if(avail[j] < need[i][j])
                    {
                        process = -1;
                        break;
                    }
                }
            }

            if(process != -1)
                break;
        }

        if(process != -1)
        {
            printf("\nProcess %d runs to completion ! \n", process + 1);

            safeSequence[count] = process + 1;
            count++;

            for (j = 0; j < r;j++)
            {
                avail[j] += alloc[process][j];
                alloc[process][j] = 0;
                MAX[process][j] = 0;
                completed[process] = 1;
            }
        }

    } while (count !=p && process != -1);
    
    if(count == p)
    {
        printf("\nThe system is in a safe state ! \n");
        printf("\nSae Sequence : < ");

        for (i = 0; i < p;i++)
            printf("%d",safeSequence[i]);
        printf(" > \n");
    }
    else
    {
        printf("\nThe system is in an unsafe state !");
    }

    return 0;
}