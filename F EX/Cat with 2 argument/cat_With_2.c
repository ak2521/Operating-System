#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
       int f=0,n,n1;
       char l[80],l1[80];
       struct stat s1,s2;
       if(argc!=3)
       {
               printf("Mismatch argument");
               exit(1);
       }
       if(access(argv[1],F_OK))
       {
               printf("File Exist");
               exit(1);
       }
       if(stat(argv[1],&s1)<0)
       {
               printf("Stat ERROR");
               exit(1);
       }
       if(access(argv[2],F_OK))
       {
               printf("File Exist");
               exit(1);
       }
       if(stat(argv[2],&s2)<0)
       {
               printf("Stat ERROR");
               exit(1);
       }
       if(S_ISREG(s1.st_mode)<0)
       {
               printf("Not a Regular FILE");
               exit(1);
       }
       if(S_ISREG(s2.st_mode)<0)
       {
               printf("Not a Regular FILE");
               exit(1);
       }
       if(geteuid()==s1.st_uid)
               if(s1.st_mode & S_IRUSR)
                       f=1;
       else if(getegid()==s1.st_gid)
               if(s1.st_mode & S_IRGRP)
                       f=1;
       else if(s1.st_mode & S_IROTH)
               f=1;
        if(geteuid()==s2.st_uid)
               if(s2.st_mode & S_IRUSR)
                       f1=1;
       else if(getegid()==s2.st_gid)
               if(s2.st_mode & S_IRGRP)
                       f1=1;
       else if(s2.st_mode & S_IROTH)
               f1=1;
       if(!f)
       {
               printf("Permission denied");
               exit(1);
       }
        if(!f1)
       {
               printf("Permission denied");
               exit(1);
       }
       f=open(argv[1],O_RDONLY);
       while((n=read(f,l,80))>0)
               write(1,l,n);
        
       f1=open(argv[2],O_RDONLY);
       while((n1=read(f1,l1,80))>0)
               write(1,l1,n1);
}
