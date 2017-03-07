/* dfs and bfs using adj list*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int a[MAX];
int rear=-1;
int front=-1;


int isemptyqueue()
{
	return front==-1?1:0;
}

int isfullqueue()
{
   return (rear==MAX-1)?1:0;	
} 

void enqueue(int p)
 { 
	if(isfullqueue())
	   {
	   printf("QUEUE is FULL\n");
	   return;
       }
      a[++rear]=p;
	  if(front==-1)
	     front=0;  
 }


int dequeue()
 {
 	int p;
	if(isemptyqueue())
	   {
	   	printf("queue is empty\n");
	   	return 0;
	   }
    if(rear==front)
	   {
	   	p=a[front];
	   	rear=front=-1;
	   }	   
	else
	  {
	  	p=a[front++];
	  }   
	 return p; 
 }
 
 
  
struct node
{
    int data;
    struct node*next;	
};


struct headnode
{
struct node*x;	
};


struct adjlist
{
int v;
struct headnode*m;	
};



struct adjlist*initgraph()
{
 int i;	
 struct adjlist*p=(struct adjlist*)malloc(sizeof(struct adjlist));
 printf("enter the number the vertex\n");
 scanf("%d",&p->v);
 p->m=(struct headnode*)malloc(sizeof(struct headnode)*p->v);
 for(i=0;i<p->v;i++)
     p->m[i].x=NULL;
	 
 return p;	 	
}


struct node*newnode(int n)
{
   struct node*t=(struct node*)malloc(sizeof(struct node));
    t->data=n;
	t->next=NULL;
	return t;	
}


struct adjlist*creategraph(struct adjlist*g)
{

    int n,i,d,f;
	struct node*temp;	
    printf("Enter the number of edges\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
  	  printf("enter the name of edges\n");
  	  scanf("%d %d",&d,&f);
  	  temp=newnode(d);
  	  temp->next=g->m[f].x;
  	  g->m[f].x=temp;
  	  
  	  temp=newnode(f);
  	  temp->next=g->m[d].x;
  	  g->m[d].x=temp;
    }	
      return g;
}


void printgraph(struct adjlist*p)
{
	int i;
	struct node*m;
   for(i=0;i<p->v;i++)
       {
       	printf("The %dth row is as: ",i);
         m=p->m[i].x;
		 while(m)
		   {
		    printf(" %d",m->data);
			m=m->next;	
		   }
		   printf("\n");	
	   } 	
}


int arr[10];

void dfs(struct adjlist*p,int n)
{
    printf(" %d",n);
    arr[n]=1;
    struct node*k=p->m[n].x;
  	  while(k)
  	   {
  	    if(arr[k->data]!=1)
		   {
		    dfs(p,k->data); 	
		   }	
		   k=k->next;
	   }
	  printf("\n"); 
}


/*
void bfs(struct adjlist*p,int n)
{
	
	struct node*t;
	enqueue(p->m[n].x);

	while(!isemptyqueue())
	  {
	  
	   t=dequeue();
	   
	   printf("after dequeue=>%d",t->data);
	    if(arr[t->data]!=1)
		  {
		  	printf(" %d",t->data);
		  	arr[t->data]=1;
		  }	
		  t=t->next;
		  while(t)
		   {
		   	enqueue(t);
		   	t=t->next;
		   }
	  }	
}
*/




void bfs(struct adjlist*p,int n)
{
	struct node*x;
	enqueue(n);
	while(!isemptyqueue())
        {
    		n=dequeue();
    		if(arr[n]!=1)
    		   printf(" %d",n);
    		  arr[n]=1;
			x=p->m[n].x;
		    while(x)
			 {
			   if(arr[x->data]!=1)	
			   enqueue(x->data);
			   x=x->next;	
			 }	   
			   
		}	
}





int main() 
{
struct adjlist*p=initgraph();	
p=creategraph(p);
//printgraph(p);
//dfs(p,0);
bfs(p,0);
return 0;
}
