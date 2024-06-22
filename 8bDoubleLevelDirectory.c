#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct 
{
    char dname[10];
    char fname[10][10];
    int fcnt;
}dir[10];

void main()
{
    int i,choice,dcnt,k;
    char f[30],d[30];
    dcnt = 0;

    while(1)
    {
        printf("\n1.CREATE DIRECTORY\t2.CREATE FILE\t3.DELETE FILE\t4.SEARCH FILE\t5.DISPLAY\t6.EXIT\n");
        printf("\nEnter you choice:\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                    printf("\nEnter the name of the directory to create\n");
                    scanf("%s", dir[dcnt].dname);
                    dir[dcnt].fcnt = 0;
                    dcnt++;
                    printf("\nDirectory created\n");
                    break;

            case 2 :
                    printf("\nEnter the directory name:\n");
                    scanf("%s", d);

                    for(i=0;i<dcnt;i++)
                    {
                        if(strcmp(d,dir[i].dname)==0)
                        {
                            printf("\nDirectory Found\n");
                            printf("\nEnter the name of the file\n");
                            scanf("%s", dir[i].fname[dir[i].fcnt]);
                            dir[i].fcnt++;
                            printf("\nFile Created\n");
                        }
                    }

                    if(i==dcnt)
                    {
                        printf("Directory %s not found\n",d);
                    }
                    break;

            case 3 :
                    printf("\nEnter the name of the directory\n");
                    scanf("%s", d);

                    for (i = 0; i < dcnt;i++)
                    {
                        if(strcmp(d,dir[i].dname)==0)
                        {
                            printf("\nDirectory found\n");
                            printf("\nEnter the name of the file:\n");
                            scanf("%s",f);

                            for (k = 0; k < dir[i].fcnt;k++)
                            {
                                if(strcmp(f,dir[i].fname[k])==0)
                                {
                                    printf("\nFile %s deleted\n",f);
                                    dir[i].fcnt--;
                                    strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt]);
                                    break;
                                }
                            }

                            if(k==dir[i].fcnt)
                            {
                                printf("\nFile %s not found\n");
                                break;
                            }
                        }
                    }

                    if(i==dcnt)
                    {
                        printf("\nDirectory %s not found\n");
                    }
                    break;

            case 4 :
                    printf("\nEnter the name of the directory\n");
                    scanf("%s", d);

                    for (i = 0; i < dcnt;i++)
                    {
                        if(strcmp(d,dir[i].dname)==0)
                        {
                            printf("\nDirectory found\n");
                            printf("\nEnter the name of the file:\n");
                            scanf("%s",f);

                            for (k = 0; k < dir[i].fcnt;k++)
                            {
                                if(strcmp(f,dir[i].fname[k])==0)
                                {
                                    printf("\nFile %s is found\n",f);
                                    break;
                                }
                            }

                            if(k==dir[i].fcnt)
                            {
                                printf("\nFile %s not found\n");
                                break;
                            }
                        }
                    }

                    if(i==dcnt)
                    {
                        printf("\nDirectory %s not found\n");
                    }
                    break;

            case 5 :
                    if(dcnt ==0)
                        printf("\nNo Directories are present:\n");
                    else
                    {
                        printf("\nDirectory \t Files \n");
                        for(i=0;i<dcnt;i++)
                        {
                            printf("\n%s\t\t", dir[i].dname);

                            for (k = 0; k < dir[i].fcnt;k++)
                                printf("\t%s", dir[i].fname[k]);
                        }
                    }
                    break;

            default :
                exit(0);
        }
    }
}
