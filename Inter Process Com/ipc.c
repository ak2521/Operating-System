#include<stdio.h>
#include<stdlib.h>
#include <errno.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main()
{
  int x;
  int pid;
  int shmid;
  printf("%ld\n",sizeof(int));
  shmid =  shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0777);
  if (shmid == -1)
  {
          perror("shmget() failed: ");
          exit (1);
  }
  else
  {
    printf("shmget() returns shmid = %d.\n", shmid);
}


      pid = fork(); // creating child process
      if(pid == 0)
      {
        printf("Enter the number");
        scanf("%d",&x);
        int *pi_child;
        pi_child = shmat(shmid, NULL, 0);
        if (pi_child == (void *)-1)
        {
                perror("shmat() failed at child: ");
                exit (1);
        }
      *(pi_child) = x;
      shmdt(pi_child);
      exit(0);
    }
    else
    {
      wait(NULL);
    }
  int *ppi_child;
  ppi_child = shmat(shmid,NULL,0);
  if (ppi_child == (void *)-1)
  {
          perror("shmat() failed at child: ");
          exit (1);
  }

if(*(ppi_child)%2==0)
      printf("%d\t is even",*(ppi_child));
      else
      printf("ODD");
  shmdt(ppi_child);
  return 0;

}
