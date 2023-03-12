#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *list;
int pos=0;
void display(list head)
{
	list t=head;
	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}  
}
void insert(int no,list head)
{   int i;
	list temp,t;
	temp=(list)malloc(sizeof(struct node));
	temp->data=no;
	t=head;
	pos++;
	for(i=0;i<pos-1;i++)
	{
		t=t->next;
	}
	temp->next=t->next;
	t->next=temp;
	display(head);
}
int search(int x,list head)
{  
	list t=head;
	while(t!=NULL)
	{
		if(t->data==x)
		 return 1;
		t=t->next;
	}
    if(t==NULL)
    return 0;
	
}

list prevelementaddr(int x,list head)
{
	list t=head;
	while(t->next!=NULL)
	{
		if(t->next->data==x)
		   return t;
		else
		   t=t->next;
	}
	return t;
}


int main()
{
	list head;
	int choice;
	head=(list)malloc(sizeof(struct node));
	head->next=NULL;
	int x;
	printf("Enter the first element to inserted\n");
	scanf("%d",&x);
	head->data=x;
    while(1)
	{    
		printf("enter your choice 1=insert 2=search 3=exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{   
				    int x,p;
				    printf("enter the no to be insert\n");
				    scanf("%d",&x);
					insert(x,head);
					break;
				}
			case 2:
				{
					int i,x;
					printf("enter the no to be search\n");
					scanf("%d",&x);
					i=search(x,head);
					if(i==1)
					printf("%d is present\n",x);
					else
					printf("%d is not present\n",x);
					break;
				}
				case 3:
					exit(1);
		}
		
	}
}
