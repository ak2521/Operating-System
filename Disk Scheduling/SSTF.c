#include<stdio.h>
#include<stdlib.h>
struct list
{
 int cyl;
 int id;
 int flag;
};
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
void sstf(struct list* li,int n,int init)
{
 int i,j,k,min,next;
 int head;
 min=abs(li[0].cyl-init);
 next=0;
 for(i=1;i<n;i++)
 {
 if(min>(abs(init-li[i].cyl)))
 {
 min=abs(init-li[i].cyl);
 next=i;
 }
 }
 head=abs(li[next].cyl-init);
 li[next].flag=0;
 printf("\n%d ~> %d ",init,li[next].cyl);
 for(i=1;i<n;i++)
 {
 k=next;
 next=-1;
 min=99999;
 for(j=0;j<n;j++)
 {
 if(min>(abs(li[k].cyl-li[j].cyl)) && li[j].flag==-1)
 {
 min=abs(li[j].cyl-li[k].cyl);
 next=j;
 }
 }
 head+=abs(li[next].cyl-li[k].cyl);
 li[next].flag=k;
 printf("~> %d ",li[next].cyl);
 }
 printf("\n\nTotal no. of head movements = %d\n",head);
}int main()
{
 int ch,n,i,init,prev,direc,total;
 struct list* li;
 struct list* l;
 printf("\nEnter the no. of Request : ");
 scanf("%d",&n);
 li=malloc(sizeof(struct list)*(n));
 l=malloc(sizeof(struct list)*(n));
 printf("\nEnter the request : \n");
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
 sstf(l,n,init);
}
