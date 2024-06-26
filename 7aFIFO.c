#include<stdio.h>
#include<stdlib.h>

int main()
{
    int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    int temp[frames];

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t Frame1 \t Frame2 \t Frame3 \n");

    for(m=0;m<frames;m++)
    {
        temp[m] = -1;
    }

    for(m=0;m<pages;m++)
    {
        s=0;
        for(n=0;n<frames;n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
            
        }
        pageFaults++;

        if((pageFaults <= frames) && (s==0))
        {
            temp[m] = incomingStream[m];
        }

        else if(s==0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        printf("\n");

        printf("%d\t\t\t", incomingStream[m]);

        for(n=0;n<frames;n++)
        {
            if(temp[n] != -1)
                printf("%d\t\t\t",temp[n]);
            else
                printf("--\t\t\t");
        }

    }

    printf("\n\nTotal page faults : \t%d\n", pageFaults);

    return 0;
}