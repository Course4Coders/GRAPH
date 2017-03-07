/* adjacency list for undirected graph */


#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data;
    struct node* next;	
};
 

struct headadd
{
    struct node*m;	
};


struct adjlist
{
int v;
struct headadd*x;	
};






struct adjlist* initgraph()
{
int i;	
struct adjlist*z=(struct adjlist*)malloc(sizeof(struct adjlist));	
printf("enter number of node\n");
scanf("%d",&z->v);
z->x=(struct headadd*)malloc(sizeof(struct headadd)*z->v);

for(i=0;i<z->v;i++)
z->x[i].m=NULL;	
	
return z;	  
}


struct node*newnode(int n)
{
	struct node*z=(struct node*)malloc(sizeof(struct node));
	z->data=n;
	z->next=NULL;
	return z;
}


struct adjlist* creategraph(struct adjlist*z)
   {
   	int n,i,a,b;
   	struct node*temp;
     printf("enter the number of edges\n");
	 scanf("%d",&n);
       for(i=0;i<n;i++)
	      {
	        printf("enter the edges\n");
			scanf("%d %d",&a,&b);
			
		    temp=newnode(a);
			temp->next=z->x[b].m;
			z->x[b].m=temp;
			
			temp=newnode(b);
			temp->next=z->x[a].m;
			z->x[a].m=temp;		
		  }	    	 
		  return z;
   }
   
   void printgraphlist(struct adjlist*z)
   {
   	int i;
   	struct node*m;
   	 for(i=0;i<z->v;i++)
   	     {
   	     	m=z->x[i].m;
   	      while(m)
			  {
			  	printf(" %d",m->data);
			  	m=m->next;
			  }	
			  printf("\n");
		 }
   }

int main() 
{
struct adjlist*p=initgraph();
struct adjlist*m=creategraph(p);
printgraphlist(m);  	
return 0;
}
