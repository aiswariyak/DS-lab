#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
 void main()
{
int n,i;
struct node *current,*temp ,*new_node,*start=NULL;
printf("\n enter the total number of nodes\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
new_node=(struct node*)malloc(sizeof(struct node));
printf("\n enter the data\n");
scanf("%d",&new_node->data);
new_node->next=NULL;
if(start==NULL)
{
start=new_node;
current=start;
}
else
{
current->next=new_node;
current=new_node;
}
}
printf("\nThe linked list is:\n");
for(temp=start;temp<=current;temp=temp->next)
printf(" %d-->",temp->data);
}
