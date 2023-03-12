#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
int psize;
struct node *next;};
typedef struct node *queue;
void enqueue(queue rear,int p){
 queue temp,t;
 temp=(queue)malloc(sizeof(queue));
 temp->psize=p;
 t=rear;
 while(t->next)
  t=t->next;
 temp->next=t->next;
 t->next=temp;
}
void dequeue(queue rear){
  queue temp =rear;
  temp= temp->next;
}
int firstFit(int blockSize[], int m,queue rear, int n)
{
 int flag=0;
 int allocation[n];
  int i,j,q=0;
  queue t;
  t=rear;
  for (i = 0; i <n; i++)
   allocation[i] = -1;
  i=0;
 while(t->next)
 {
  t=t->next;
  for (j = 0; j < m; j++)
  {
   if (blockSize[j] >= t->psize)
   {
    allocation[i] = j;
    blockSize[j] -= t->psize;
    q+=blockSize[j];
    blockSize[j]=0;
    dequeue(t);
    break;
   }
  }
  i++;
 }
 t=rear;
 i=0;
 printf("Process No.\tProcess Size\tBlock no.\n");
  while(t->next){
   t=t->next;
   printf("%d\t\t%d\t\t",i+1,t->psize);
   if (allocation[i] != -1)
    printf("%d\n",allocation[i] + 1);
   else{
    printf("Not Allocated\n");
    flag=1;
   }
  i++;
  }
  if(flag==1)
   return 10000;
  else{
   printf("\nThe wastage for first fit is:%d",q);
   return q;}
}
int bestFit(int blockSize[], int m,queue rear,int n){
  int flag=0;
  int allocation[n];
  int i,j,q=0;
  queue t;
  t=rear;
  for (i = 0; i <n; i++)
   allocation[i] = -1;
  i=0;
  while(t->next)
  {
   t=t->next;
   int bestIdx = -1;
   for (j=0; j<m; j++)
   {
    if (blockSize[j] >= t->psize)
    {
     if (bestIdx == -1)
      bestIdx = j;
     else if (blockSize[bestIdx] > blockSize[j])
      bestIdx = j;
    }
   }
  if (bestIdx != -1)
   {
    allocation[i] = bestIdx;
    blockSize[bestIdx] -= t->psize;
    q+=blockSize[bestIdx];
    blockSize[bestIdx]=0;
    dequeue(t);
   }
   i++;
  }
  t=rear;
  i=0;
 printf("Process No.\tProcess Size\tBlock no.\n");
  while(t->next){
   t=t->next;
   printf("%d\t\t%d\t\t",i+1,t->psize);
   if (allocation[i] != -1)
    printf("%d\n",allocation[i] + 1);
   else{
    printf("Not Allocated\n");
    flag=1;
   }
  i++;
  }
  if(flag==1)
   return 10000;
  else{
   printf("\nThe wastage for best fit is:%d",q);
   return q;}
 }
int worstFit(int blockSize[], int m, queue rear,int n)
{
 queue t;
 t=rear;
 int allocation[n];
 int i,j,flag=0;
 for(i=0;i<n;i++)
  allocation[i]=-1;
 i=0;
 int q=0;
 while(t->next)
 {
  t=t->next;
  int wstIdx = -1;
  for (j=0; j<m; j++)
  {
   if (blockSize[j] >= t->psize)
   {
    if (wstIdx == -1)
     wstIdx = j;
    else if (blockSize[wstIdx] < blockSize[j])
     wstIdx = j;
   }
  }
  if (wstIdx != -1)
  {
   allocation[i] = wstIdx;
   blockSize[wstIdx] -= t->psize;
   q+=blockSize[wstIdx];
   blockSize[wstIdx]=0;
   dequeue(t);
  }
 i++;
 }
 printf("\nProcess No.\tProcess Size\tBlock no.\n");
 t=rear;
 i=0;
  while(t->next){
  t=t->next;
  printf("%d\t\t%d\t\t",i+1,t->psize);
  if (allocation[i] != -1)
   printf("%d\n",allocation[i]+1);
  else{
   printf("Not Allocated\n");
   flag=1;
  }
 i++;
 }
 if(flag==1)
   return 10000;
 else{
  printf("\nThe wastage for worst fit is:%d",q);
   return q;
  }
}
void min(int w,int f,int b){
 if (w <= f && w <= b)
  printf("\nWorst Fit algorithm suits best for this problem");
         
    else if (f <= w && f <= b)
        printf("\nFirst Fit algorithm suits best for this problem");
         
    else
        printf("\nBest Fit algorithm suits best for this problem");
        }
void main()
{
 queue rear=(queue)malloc(sizeof(queue));
 rear->next=NULL;
 int w,f,b1,i,l,p,b,a;
 printf("Enter no. of process:");
 scanf("%d",&p);
 printf("Enter the process's sizes:");
 int g=0;
 for(i=0;i<p;i++){
  g++;
  scanf("%d",&l);
  enqueue(rear,l);
 }
 printf("Enter no. of blocks:");
 scanf("%d",&b);
 int bw[b],bf[b],bb[b];
 printf("Enter the blocks's size:");
 for(i=0;i<b;i++){
  scanf("%d",&a);
  bb[i]=a;
  bf[i]=a;
  bw[i]=a;
 }
 printf("Worst Fit\n");
 w=worstFit(bw,b,rear,g);
 printf("First Fit\n");
 f=firstFit(bf,b,rear,g);
 printf("Best Fit\n");
 b1=bestFit(bb,b,rear,g);
 min(w,f,b1);
}
