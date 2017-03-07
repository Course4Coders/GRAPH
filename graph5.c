#include<stdio.h>
#include<stdlib.h>

int a[10][10],list[20],stack[20],ind[20],s,k,top=-1,n;

void topsort(int n,int a[][10])
{
int i,j;
for(i=1;i<=n;i++)
{
s=0;
for(j=1;j<=n;j++)
{
s=s+a[j][i];
}
ind[i]=s;
}
for(i=1;i<=n;i++)
{
if(ind[i]==0)
stack[++top]=i;
}
while(top!=-1)
{
i=stack[top--];
list[k++]=i;
for(j=1;j<=n;j++)
{
if(a[i][j]==1)
{
ind[j]--;
if(ind[j]==0)
stack[++top]=j;
}
}
}
}

void read()
{
int i,j,v1,v2;
printf("Enter the no of vertiices\n");
scanf("%d",&n);
printf("Enter the 2 vertices between which there is an edge and -1,-1 to terminate\n");
scanf("%d%d",&v1,&v2);
while(v1!=-1 && v2!=-1)
{
a[v1][v2]=1;
scanf("%d%d",&v1,&v2);
}
}

int main()
{
int i,flag=1;
read();
topsort(n,a);
for(i=0;i<n;i++)
{
if(list[i]==0)flag=0;

if(flag==1)
{
printf("Topological sorted vertices are\n");
for(i=0;i<n;i++)
printf("%d\n",list[i]);
}
else
printf("Topological sorting is not possible\n");
}
system("PAUSE");
return (0);
}
