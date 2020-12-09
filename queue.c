#include<stdio.h>
#define MAX 50
void push();
void pop();
void display();

int queue[MAX],c,front=-1,rear=-1,i,item;
void main()
{

do
{
printf("\nenter the operation you want to perform\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
scanf("%d",&c);
switch(c)
{
case 1:
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
display();
break;
}
case 4:
{
printf("\n*******************EXIT POINT**************************\n");
break;
}
default:
printf("\nenter a valied choice 1 or 2 or3 or 4 \n");
}
}while(c!=4);
}
void push()
{
if(rear>=MAX-1)
printf("\n **********************QUEUE OVERFLOW****************\n");
if(front==-1)
front=0;
else
{
printf("\n enter the element to insert\n");
scanf("%d",&item);
queue[++rear]=item;
}
}
void pop()
{
if(front==-1||front>rear)
printf("\n*******************QUEUE UNDERFLOW************************");
else
{
printf("\n the deleted element is:%d",queue[front]);
front++;
}
}
void display()
{
for(i=front;i<=rear;i++)
printf(" %d ",queue[i]);
}










