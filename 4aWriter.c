#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char buf[MAX_BUF];
    char *myfifo = "/home/bmsit/1by22cs123/myfifo";

    mkfifo(myfifo,0666);
    printf("\nRun the reader process to read the file:\n");

    fd = open(myfifo,O_WRONLY);
    write(fd,"HI,sizeof("HI"));
    close(fd);

    unlink(myfifo);

    return 0;
}