#include<stdio.h>
int n,adj[20][20],queue[20],visited[20];
int front=0,rear=0,j,s,i;
void bfs(int s);
void main()
{
printf("\nenter the no of vertices\n");
scanf("%d",&n);
printf("\nenter the graph in matrix form:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&adj[i][j]);
printf("\nenter the source vertex\n");
scanf("%d",&s);
bfs(s);
queue[0]=s;
visited[s]=1;
printf("\nthe reachable nodes from %d is:\n",s);
for(i=0;i<n;i++)
if(visited[i]==1)
printf(" %d ",i);
}
void bfs(int s)
{
if(front<=rear)
{
for(i=0;i<n;i++)
if(adj[s][i]==1 && visited[i]==0)
{
queue[++rear]=i;
visited[i]=1;
}
bfs(queue[front++]);
}
}
