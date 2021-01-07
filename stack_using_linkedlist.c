#include<stdio.h>
#include<stdlib.h>
struct stack
{
int data;
struct stack *next;
}*newnode,*top=NULL,*temp,*topnode;
int n,key,c,i,flag,size=0;
void push();
void pop();
void search();
void display();
void main()
{

printf("\nenter the size of the stack\n");
scanf("%d",&n);
do
{
printf("\n enter your choice\n1.PUSH\n2.POP\n3.SEARCH\n4.DISPLAY\n5.EXIT");
scanf("%d",&c);
switch(c)
{
case 1:
  push();
  break;
case 2:
  pop();
  break;
case 3:
  search();
  break;
case 4:
  display();
  break;
case 5:
  printf("\n***********EXIT POINT***********\n");
  break;
default:
  printf("\n enter a valied choice\n");
}
}while(c!=5);
}
void push()
{
if(size==n)
printf("\n*************OVERFLOW*********************\n");
else
{
newnode=(struct stack*)malloc(sizeof(struct stack));
printf("\n enter the  element\n");
scanf("%d",&newnode->data);
newnode->next=top;
top=newnode;
size=size+1;
 }
}
void pop()
{
if(size==0)
printf("\n*************UNDERFLOW*************\n");
else
{
topnode=top;
printf("\nthe popped element is %d\n",top->data);
top=top->next;
free(topnode);
size=size-1;
}
}
void display()
{
if(size==0)
printf("\n*************STACK IS EMPTY**************\n");
else
{
printf("\n the stack is:\n");
temp=top;
while(temp!=NULL)
{
printf("\n%d\n",temp->data);
temp=temp->next;
}
}
}
void search()
{
if(size==0)
printf("\n ******************STACK IS EMPTY***********\n");
else
{
printf("\n enter the value to search\n");
scanf("%d",&key);
temp=top;
while(temp!=NULL)
{
flag=0;
if(key==temp->data)
{
flag=1;
break;
}
temp=temp->next;
}
if(flag==1)
printf("\n element is found\n");
else
printf("\nelement is not found\n");
}
}