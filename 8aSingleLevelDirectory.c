#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct 
{
    char dname[10];
    char fname[10][10];
    int fcnt;
} dir;

void main()
{
    int i,choice;
    char f[30];;

    dir.fcnt = 0;

    while(1)
    {
        printf("\n1.CREATE FILE \t 2.DELETE FILE \t 3.SEARCH FILE \t 4.DISPLAY FILE \t 5.EXIT\n");
        printf("\nEnter you choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                    printf("\nEntet the file name:\n");
                    scanf("%s",dir.fname[dir.fcnt]);
                    dir.fcnt++;
                    break;

            case 2 :
                    printf("\nEnter the file name:\n");
                    scanf("%s",f);

                    for(i=0;i<dir.fcnt;i++)
                    {
                        if(strcmp(f,dir.fname[i])==0)
                        {
                            printf("\nFile %s is deleted:",f);
                            strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                            break;
                        }
                    }

                    if(i == dir.fcnt)
                    {
                        printf("\nFile %s not found\n",f);
                    }
                    else
                    {
                        dir.fcnt--;
                    }
                    break;

            case 3 :
                    printf("\nEnter the file name:\n");
                    scanf("%s",f);

                    for(i=0;i<dir.fcnt;i++)
                    {
                        if(strcmp(f,dir.fname[i])==0)
                        {
                            printf("\nFile %s is found \n",f);
                            break;
                        }
                    }

                    if(i == dir.fcnt)
                    {
                        printf("\nFile %s is not found:\n",f);
                    }
                    break;

            case 4 :
                    if(dir.fcnt == 0)
                        printf("\nDirectory is empty\n");
                    else
                    {
                        printf("\nThe files are : --");
                        for (i = 0; i < dir.fcnt;i++)
                        {
                            printf("\t%s\n", dir.fname[i]);
                        }
                    }
                    break;

            default :
                exit(0);
        }
    }
}