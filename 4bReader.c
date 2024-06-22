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

    fd = open(myfifo,O_RDONLY);
    read(fd,buf,MAX_BUF);
    printf("Writer : %s\n", buf);
    close(fd);

    return 0;
}