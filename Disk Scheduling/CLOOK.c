#include<stdio.h>
#include<stdlib.h>
struct list
{
 int cyl;
 int id;
 int flag;
};
int findMin(struct list* l,int n,int cyl)
{
 int i;
 for(i=0;i<n;i++)
 {
 if(cyl<=l[i].cyl)
 return i-1;
 }
}
int findMax(struct list* l,int n,int cyl)
{
 int i;
 for(i=0;i<n;i++)
 {
 if(cyl<=l[i].cyl)
 return i;
 }
}
void copy(struct list* l,struct list* l1,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
 l1[i].cyl=l[i].cyl;
 l1[i].id=l[i].id;
 l1[i].flag=l[i].flag;
 }
}
void sort(struct list* l,int n)
{
 int i,j;
 struct list temp;
 for(i=0;i<n-1;i++)
 {
 for(j=i+1;j<n;j++)
 {
 if(l[i].cyl>l[j].cyl)
 {
 temp=l[i];
 l[i]=l[j];
 l[j]=temp;
 }
 }
 }
}
void clook(struct list* li,int n,int init,int direc)
{
 int i,j,k,min,next;
 int head;
 sort(li,n);
 if(direc==0)
 {
 next=findMin(li,n,init);
 head=abs(li[next].cyl-init);
 printf("\n%d ~> %d ",init,li[next].cyl);
 for(i=next;i>0;i--)
 {
 head+=abs(li[i].cyl-li[i-1].cyl);
 printf("~> %d ",li[i-1].cyl);
 }
 head+=abs(li[0].cyl-li[n-1].cyl);
 printf("~> %d ",li[n-1].cyl);
 next=findMax(li,n,init);
 for(i=n-1;i>next;i--)
 {
 head+=abs(li[i].cyl-li[i-1].cyl);
 printf("~> %d ",li[i-1].cyl);
 }
 printf("\n\nTotal no. of head movements = %d\n",head);
 }
 else
 {
 next=findMax(li,n,init);
 head=abs(li[next].cyl-init);
 printf("\n%d ~> %d ",init,li[next].cyl);
 for(i=next;i<n-1;i++)
 {
 head+=abs(li[i].cyl-li[i+1].cyl);
 printf("~> %d ",li[i+1].cyl);
 }
 head+=abs(li[0].cyl-li[n-1].cyl);
 next=findMin(li,n,init);
 printf("~> %d ",li[0].cyl);
 for(i=0;i<next;i++)
 {
 head+=abs(li[i].cyl-li[i+1].cyl);
 printf("~> %d ",li[i+1].cyl);
 }
 printf("\n\nTotal no. of head movements = %d\n",head);
 }
}
int main()
{
 int ch,n,i,init,prev,direc,total;
 struct list* li;
 struct list* l;
 printf("\nEnter the no. of Request : ");
 scanf("%d",&n);
 li=malloc(sizeof(struct list)*(n));
 l=malloc(sizeof(struct list)*(n));
 printf("\nEnter the Request\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&li[i].cyl);
 li[i].id=i;
 li[i].flag=-1;
 }
 printf("\nEnter the total no. of cylinders : ");
 scanf("%d",&total);
 printf("\nEnter the current head position : ");
 scanf("%d",&init);
 printf("\nEnter the prev head position : ");
 scanf("%d",&prev);
 if((init-prev)<0)
 direc=0;
 else
 direc=1;
copy(li,l,n);
 clook(l,n,init,direc);
}
