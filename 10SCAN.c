#include<stdio.h>
#include<stdlib.h>

int request[50];
int SIZE;
int pre;
int head;
int uptrack;
int downtrack;

struct max
{
    int up;
    int down;
} kate[50];

int dist(int a,int b)
{
    if(a>b)
        return a-b;
    return b - a;
}

void sort(int n)
{
    int i,j;

    for (i = 0; i < n - 1;i++)
    {
        for (j = 0; j < n - i - 1;j++)
        {
            if(request[j] > request[j+1])
            {
                int temp = request[j];
                request[j] = request[j+1];
                request[j + 1] = temp;
            }
        }
    }

    i=0;
    j=0;
    while(request[i] != head)
    {
        kate[j].down = request[i];
        j++;
        i++;
    }
    downtrack = j;

    i++;
    j=0;
    while(i<n)
    {
        kate[j].up = request[i];
        j++;
        i++;
    }
    uptrack = j;
}

void scan(int n)
{
    int i;
    int seekcount = 0;

    printf("\nSEEK SEQUENCE:\n");
    sort(n);

    if(pre < head)
    {
        for (i = 0; i < uptrack;i++)
        {
            printf("%d ", head);
            seekcount = seekcount + dist(head, kate[i].up);
            head = kate[i].up;
        }

        for(i=downtrack-1;i>0;i--)
        {
            printf("%d ", head);
            seekcount = seekcount + dist(head, kate[i].down);
            head = kate[i].down;
        }
    }

    else
    {
        for(i=downtrack-1;i>=0;i--)
        {
            printf("%d ", head);
            seekcount = seekcount + dist(head, kate[i].down);
            head = kate[i].down;
        }

        for (i = 0; i < uptrack-1;i++)
        {
            printf("%d ", head);
            seekcount = seekcount + dist(head, kate[i].up);
            head = kate[i].up;
        }
    }

    printf("%d\nTOTAL DISTANCE : %d\n", head, seekcount);
}

int main()
{
    int i,n;

    printf("\nENTER THE DISK SIZE:\n");
    scanf("%d",&SIZE);
    printf("\nENTER THE NUMBER OF REQUEST SEQUENCE:\n");
    scanf("%d",&n);
    printf("\nENTER THE REQUEST SEQUENCE:\n");
    for(i=0;i<n;i++)
        scanf("%d",&request[i]);
    printf("\nENTER THE CURRENT HEAD:\n");
    scanf("%d",&head);

    request[n] = head;
    request[n+1] = SIZE-1;
    request[n + 2] = 0;

    printf("\nENTER THE PRE REQUEST:\n");
    scanf("%d", &pre);

    scan(n + 3);

    return 0;
}