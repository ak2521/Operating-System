#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
       int f=0,n;
       char l[80];
       struct stat s;
       if(argc!=2)
       {
               printf("Mismatch argument");
               exit(1);
       }
       if(access(argv[1],F_OK))
       {
               printf("File Exist");
               exit(1);
       }
       if(stat(argv[1],&s)<0)
       {
               printf("Stat ERROR");
               exit(1);
       }
       if(S_ISREG(s.st_mode)<0)
       {
               printf("Not a Regular FILE");
               exit(1);
       }
       if(geteuid()==s.st_uid)
               if(s.st_mode & S_IRUSR)
                       f=1;
       else if(getegid()==s.st_gid)
               if(s.st_mode & S_IRGRP)
                       f=1;
       else if(s.st_mode & S_IROTH)
               f=1;
       if(!f)
       {
               printf("Permission denied");
               exit(1);
       }
       f=open(argv[1],O_RDONLY);
       while((n=read(f,l,80))>0)
               write(1,l,n);
}