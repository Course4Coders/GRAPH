/*union-find algorithm for finding there is circle in UNDIRECTED_graph or not*/

#include <stdio.h>
#include <stdlib.h>



struct edge
{
int src;
int des;	
};



struct graph
{
int v;
int e;
struct edge *x;	
};


struct graph*creategraph()
{
struct graph*g=(struct graph*)malloc(sizeof(struct graph));

printf("enter the number of vertex\n");
scanf("%d",&g->v);

printf("enter the number of edge\n");
scanf("%d",&g->e);

g->x=(struct edge*)malloc(sizeof(struct edge)*g->e);

return g;
}


int find(int parent[],int i)
{
	if(parent[i]==-1)
	   return i;
	
	return find(parent,parent[i]);   
}

void xunion(int parent[],int i,int j)
{
	i=find(parent,i);
	j=find(parent,j);
	
	parent[i]=j;
}

int iscycle(struct graph*g)
{
  int parent[g->v],i,m,n;
  
  for(i=0;i<g->v;i++)
      {
        parent[i]=-1;	
	  }
	  	
	for(i=0;i<g->e;i++)
	   {
	     m=find(parent,g->x[i].src);
		 n=find(parent,g->x[i].des);
		 
		 if(m==n)
		   return 1;
		 xunion(parent,m,n);  	
	   }  
	 return 0;  
}

int main() 
{
	struct graph*g=creategraph();
	
  	
	g->x[0].src=0; 
	g->x[0].des=1;
	
	g->x[1].src=1;
	g->x[1].des=2;
	
	g->x[2].src=4;
	g->x[2].des=3;
	
	g->x[3].src=0;
	g->x[3].des=4;
	
		
	g->x[4].src=2;
	g->x[4].des=3;
	
	
     if(iscycle(g))
        {
         printf("Diagram contain cycle\n");	
		}
	 else
	    {
	     printf("Diagram doesn't contain cycle\n");	
		} 	
	
	return 0;
}
