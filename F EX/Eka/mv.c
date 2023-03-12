#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
int fd1,fd2;
char buf[60];
char *p="/f2";
fd1=open("f2",O_RDWR);
fd2=open("f6",O_RDWR);
read(fd1,buf,sizeof(buf));
write(fd2,buf,sizeof(buf));
remove(p);
}