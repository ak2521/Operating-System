#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
        int pno;
        int bt;
        int wt;
        int tat;
        int prior;
        struct node *next;
        };
typedef struct node *queue;
void display(queue rear){
        queue t=rear->next;
        while(t){
                printf("%d\t",t->pno);
                printf("%d\t",t->bt);
                printf("%d\n",t->prior);
                t=t->next;
        }
        printf("\n");
}
void enqueue(int pn,int b,int pr,queue rear){
        queue temp,t;
        temp=(queue)malloc(sizeof(queue));
        temp->pno=pn;
        temp->bt=b;
        temp->prior=pr;
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
void prior(queue rear){
        queue t,temp;
        temp=rear;
        int n,i,j;
        n=count(rear);
    for(i=0;i<n;i++){
        t=rear;
        while(t->next)
        {
        if(t->prior>t->next->prior){
                temp->bt=t->bt;
                t->bt=t->next->bt;
                t->next->bt=temp->bt;
                temp->prior=t->prior;
                t->prior=t->next->prior;
                t->next->prior=temp->prior;
                temp->pno=t->pno;
                t->pno=t->next->pno;
                t->next->pno=temp->pno;
                        }
                t=t->next;
    }
        }
        printf("--------------------------------------------------------------\n");
        printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
        printf("----------------------------------------------------------------");
        t=rear;
        t->bt=0;
        t->wt=0;
        int a=0,y;
        int b=0,h=0,arr[20];
        int tot=0,tot1=0;
        int l=0;
        while(t->next)
        {
                a+=t->bt;
                b=a+t->next->bt;
   t->wt=0;
        t->wt+=a;
        printf("\nP[%d]\t\t%d\t\t%d\t%d\t\t%d",t->next->pno,t->next->bt,t->next->prior,a,b);
        arr[h]=t->pno;
        h++;
        dequeue(t);
        tot = tot +a;
        tot1=tot1+b;
        l++;
        t=t->next;
        }
        if (arr[i]==0)
        arr[i]=5;
        printf("\n");
        for(y=1;y<=h;y++)
        {
        printf("|%d|",arr[y]);
        }
        printf("\nThe average waiting time %f",(float)tot/l);
        printf("\nThe average trun around time %f\n",(float)tot1/l);
        dequeue(t);
}
int main(){
        int choice;
        queue rear=(queue)malloc(sizeof(queue));
        rear->next=NULL;
        int p;
        int b;
        int pr;
        while(1){
        printf("\n1.Add New Proccessor\t2.Priority\t3.Display\t4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                        {
                                printf("Enter the processor no.:");
                                scanf("%d",&p);
                                printf("Enter the burst time:");
                                scanf("%d",&b);
                                printf("Enter the priority:");
                                scanf("%d",&pr);
                                enqueue(p,b,pr,rear);
                                break;
            break;
                        }
                case 2:
                        {
                                prior(rear);
                                exit(1);
                        }
                case 3:
                        {
                                display(rear);
                                break;
                        }
                case 4:{
                        exit(0);
                        break;
                }
        }
 }
 return 0;
}