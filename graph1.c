
/*for undirected graph by adjacency matrix*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct adjmat
{
int v;
int e;
int **adj;	
};


struct adjmat* graph()
{
	int i,j,w,m,n;
	 char x,y;
struct adjmat *z=(struct adjmat*)malloc(sizeof(struct adjmat));	
printf("Enter the number of vertex and edge\n");
scanf("%d %d",&z->v,&z->e);
z->adj=(int**)malloc(sizeof(int*)*z->v);
for(i=0;i<z->v;i++)
    {
     z->adj[i]=(int*)malloc(sizeof(int)*z->v); 	
	}
	for(i=0;i<z->v;i++)
	   {
	   	for(j=0;j<z->v;j++)
	   	    {
	   	     z->adj[i][j]=0;	
			}
	   }
	
   for(i=0;i<z->e;i++)
	  {
              printf("Enter the edges of graph and their weight\n");
			  scanf(" %c %c %d",&x,&y,&w); 
			  x=toupper(x);
			  y=toupper(y);
			  
			  m=x-'A';
			  n=y-'A';
			 // printf("\n%d %d\n",m,n);
			  z->adj[m][n]=w;
			  z->adj[n][m]=w;  	  	  	
	  }
	  return z;
}


void printgraph(struct adjmat*z)
  {
  	int i,j;
  	printf("\nOutput for undirected graph:-\n");
  	  for(i=0;i<z->v;i++)
  	        {
  	      	 for(j=0;j<z->v;j++)
  	      	     {
  	      	       printf(" %d ",z->adj[i][j]);	
				 }
				 printf("\n");
			}
  }


int main() 
{
struct adjmat*m=graph();
printgraph(m);	
return 0;
}
