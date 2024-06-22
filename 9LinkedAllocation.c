#include<stdio.h>
#include<stdlib.h>

void main()
{
    int f[50],p,i,st,len,j,c,k,a;

    for(i=0;i<50;i++)
        f[i] = 0;

    printf("\nEnter how many blocks already allocated:\n");
    scanf("%d",&p);

    printf("\nEnter blocks already allocated:\n");
    for (i = 0; i < p;i++)
    {
        scanf("%d", &a);
        f[a] = 1;
    }

    x :
        printf(" Enter the starting block and length:\n");
        scanf("%d %d",&st,&len);

        k = len;

        if(f[st]==0)
        {
            for (j = st; j < (st + k);j++)
            {
                if(f[j] == 0)
                {
                    f[j] = 1;
                    printf("%d ----------> %d\n", j, f[j]);
                }

                else
                {
                    printf("%d block already allocated:\n",j);
                    k++;
                }
            }
        }

        else
        {
            printf("%d starting block is already allocated\n",st);
            printf("Do you want to enter more files (YES - 1, NO - 0)");
            scanf("%d",&c);
            if(c==1)
                goto x;
            else
                exit(0);
        }
}