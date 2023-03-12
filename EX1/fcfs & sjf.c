#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
        int pno;
        int bt;
        int wt;
        int tat;
        struct node *next;
        };
typedef struct node *queue;
void display(queue rear){
        queue t=rear->next;
        while(t){
                printf("%d\t",t->pno);
                printf("%d\n",t->bt);
                t=t->next;
        }
        printf("\n");
}
void enqueue(int pn,int b,queue rear){
        queue temp,t;
        temp=(queue)malloc(sizeof(queue));
        temp->pno=pn;
        temp->bt=b;
        t=rear;
                while(t->next)
             t=t->next;
            temp->next=t->next;
            t->next=temp;
        }
void dequeue(queue rear){
        queue temp;
        temp=(queue)malloc(sizeof(queue));
        temp=rear;
        rear=rear->next;
        free(temp);
}
int count(queue rear){
        queue t;
        t=rear;
        int c=0;
 while(t->next){
         c++;
         t=t->next;}
        return c;
}
void fcfs(queue rear){
        int n;
        int i;
        int j;
        printf("---------------------------------------------------\n");
        printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
        printf("---------------------------------------------------");
        queue t;
        t=rear;
        t->bt=0;
        t->wt=0;
        int a=0;
        int b=0;
        while(t->next)
        {
                a+=t->bt;
                b=a+t->next->bt;
            t->wt=0;
        t->wt+=a;
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",t->next->pno,t->next->bt,a,b);
        dequeue(t);
        t=t->next;
        }
        dequeue(t);
}
void sjf(queue rear){
        queue t,temp;
        temp=rear;
        int n,i;
        n=count(rear);
    for(i=0;i<n;i++){
        t=rear;
        while(t->next)
        {
        if(t->bt>t->next->bt){
                temp->bt=t->bt;
                t->bt=t->next->bt;
 t->next->bt=temp->bt;
                temp->pno=t->pno;
                t->pno=t->next->pno;
                t->next->pno=temp->pno;
                        }
                t=t->next;
    }
        }
        t=rear;
        fcfs(t);
}
int main(){
        int choice;
        queue rear=(queue)malloc(sizeof(queue));
        rear->next=NULL;
        int p;
        int b;
        while(1){
        printf("\n1.Add New Proccessor\t2.FCFS\t3.SJF\t4.Display\t5.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                        {
                                printf("Enter the processor no.:");
                                scanf("%d",&p);
                                printf("Enter the burst time:");
                                scanf("%d",&b);
                                enqueue(p,b,rear);
                                break;
                        }
                case 2:
                        {
                                fcfs(rear);
                                exit(1);
                        }
                case 3:
                        {
                                sjf(rear);
                                exit(1);
                        }
                case 4:
                        {
 display(rear);
                                break;
                        }
                case 5:{
                        exit(0);
                }
        }
 }
 return 0;
}
