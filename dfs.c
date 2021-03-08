#include<stdio.h>
int n,i,j,s,top=0;
int stack[20],adj[20][20],visited[20];
void dfs(int s);
void main()
{
  printf("\nenter the no of vertices\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
     visited[i]=0;
  printf("\nenter the graph in matrix form\n");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
       scanf("%d",&adj[i][j]);
  printf("\nenter the starting vertex\n");
  scanf("%d",&s);
  printf("\nDFS traversal is:\n");
  stack[0]=s;
  visited[s]=1;
  printf(" %d ",s);
  dfs(s);
}
void dfs(int s)
{
if(top!=-1)
{
  for(i=0;i<n;i++)
    {
      if(adj[s][i]==1 &&visited[i]==0)
        {
          stack[++top]=i;
          visited[i]=1;
          printf(" %d ",stack[top]);
          dfs(i);
          top--;
        }

    }
  for(i=0;i<n;i++)
    if(visited[i]==0)
       dfs(i);
}
}