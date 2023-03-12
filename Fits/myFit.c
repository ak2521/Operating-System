#include<stdio.h>
#include<stdlib.h>
struct node
{
	int P_capacity;
	struct node * next;
};
int k=1;
typedef struct node * Queue;
Queue rear;
Queue front; 
void enqueue()  
{  
    Queue ptr;  
    int item;   
      
    ptr = (Queue) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("Enter size of Process %d \n",k);  
        k++;
        scanf("%d",&item);  
        ptr -> P_capacity = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void  dequeue()  
{  
    Queue ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;
		exit(1);  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        free(ptr);  
    }  
}  


int firstFit(int blockSize[], int m,Queue front1, int n)
{
 int flag=0;
 int allocation[n];
  int i,j,q=0,x,d;
  Queue t;
  t=front1;
  for (i = 0; i <n; i++)
   allocation[i] = -1;
  i=0;
    
    if(front1 == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {    
        while(t != NULL)   
        {  
    	int c=0;
	    for(j=0;j<m;j++)
        {
            if(blockSize[j]>=t-> P_capacity && c==0)
			{
				c=1;
				allocation[i]=j;
				blockSize[j]-=t->P_capacity;
				q=q+blockSize[j];
				blockSize[j]=0;
				//dequeue();
			 } 
             
        }  
        i++;
        t= t -> next; 
    }
    
 Queue t1=front1;
 i=0;
 printf("FIRST FIT DIAGRAM\n");
  for(d=0;d<m;d++)
  {  	
  	printf("+------+\n");
    if(blockSize[d]==0)
   	{
   	if(allocation[i]!=-1)
   	printf("|%6d| at Block no : %d\n",t1->P_capacity,d+1);
   	else
   	{
   		printf("|%6d| Not Allocated\n",t1->P_capacity);
    flag=1;
   }
   t1=t1->next;
  i++;
  }
  else 
  printf("|      |\n");

}
   	printf("+------+\n");
  
  
  if(flag==1)
   return 10000;
  else{
   printf("\nThe wastage for First fit is:%d",q);
   return q;}
	}
}
  
  
  
  
  
int bestFit(int blockSize[], int m,Queue front1, int n)
{
 int flag=0;
 int allocation[n];
  int i,j,q=0,x,d;
  Queue t;
  t=front1;
  for (i = 0; i <n; i++)
   allocation[i] = -1;
  i=0;
    
    if(front1 == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {    
        while(t != NULL)   
        {  
   		int bestIdx = -1;
    	int c=0;
	    for(j=0;j<m;j++)
        {
            if (blockSize[j] >= t->P_capacity)
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
    		blockSize[bestIdx] -= t->P_capacity;
    		q+=blockSize[bestIdx];
    		blockSize[bestIdx]=0;
    		//dequeue();
   }
        i++;
        t= t -> next; 
    }
    
 Queue t1=front1;
 i=0;
 printf("BEST FIT DIAGRAM\n");
 for(d=0;d<m;d++)
  {  	
  	printf("+------+\n");
    if(blockSize[d]==0)
   	{
   	if(allocation[i]!=-1)
   	printf("|%6d| at Block no : %d\n",t1->P_capacity,d+1);
   	else
   	{
   		printf("|%6d| Not Allocated\n",t1->P_capacity);
    flag=1;
   }
   t1=t1->next;
  i++;
  }
  else 
  printf("|      |\n");

}
   	printf("+------+\n");
  
  
  if(flag==1)
   return 10000;
  else{
   printf("\nThe wastage for Best fit is:%d",q);
   return q;}
	}
}
  
  





int worstFit(int blockSize[], int m,Queue front1, int n)
{
 int flag=0;
 int allocation[n];
  int i,j,q=0,x,d;
  Queue t;
  t=front1;
  for (i = 0; i <n; i++)
   allocation[i] = -1;
  i=0;
    
    if(front1 == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {    
        while(t != NULL)   
        {  
        
  		int wstIdx = -1;
    	int c=0;
	    for(j=0;j<m;j++)
        {
            if (blockSize[j] >= t->P_capacity)
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
   		blockSize[wstIdx] -= t->P_capacity;
   		q+=blockSize[wstIdx];
   		blockSize[wstIdx]=0;
   	//	dequeue();
  		}
        i++;
        t= t -> next; 
    }
    
 Queue t1=front1;
 i=0;
 printf("WORST FIT DIAGRAM\n");
  for(d=0;d<m;d++)
  {  	
  	printf("+------+\n");
    if(blockSize[d]==0)
   	{
   	if(allocation[i]!=-1)
   	printf("|%6d| at Block no : %d\n",t1->P_capacity,d+1);
   	else
   	{
   		printf("|%6d| Not Allocated\n",t1->P_capacity);
    flag=1;
   }
   t1=t1->next;
  i++;
  }
  else 
  printf("|      |\n");

}
   	printf("+------+\n");
  
  if(flag==1)
   return 10000;
  else{
   printf("\nThe wastage for Worst fit is:%d",q);
   return q;}
	}
}
  
 void min(int w,int f,int b)
 {
    if (w <= f && w <= b)
        printf("\nWorst Fit algorithm suits best for this problem");        
    else if (f <= w && f <= b)
        printf("\nFirst Fit algorithm suits best for this problem");         
    else
        printf("\nBest Fit algorithm suits best for this problem");
} 








void main ()  
{  
			int n,i,a,b,w,f,b1;
			printf("Enter the no of processors ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
            	enqueue();  
            printf("Enter no. of blocks:");
 			scanf("%d",&b);
 			int wf[b],bf[b],ff[b];
 			printf("Enter the blocks's size: \n");
 			for(i=0;i<b;i++)
			 {
			 	printf("The Block %d : ",i+1);
  				scanf("%d",&a);
 				wf[i]=a;
  				bf[i]=a;
  				ff[i]=a;
             }
            printf("Worst Fit\n");
 			w=worstFit(wf,b,front,n);
 			printf("First Fit\n");
			f=firstFit(bf,b,front,n);
			printf("Best Fit\n");
 			b1=bestFit(ff,b,front,n);
 		    min(w,f,b1);
}  
