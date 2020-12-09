#include<stdio.h>
#define MAX 50
void enqueue();
void dequeue();
void display();

int queue[MAX],c,front=-1,rear=-1,i,item;
void main()
{

do
{
printf("\nenter the operation you want to perform\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
scanf("%d",&c);
switch(c)
{
case 1:

enqueue();
break;

case 2:
dequeue();
break;
case 3:

display();
break;

case 4:

printf("\n*******************EXIT POINT**************************\n");
break;

default:
printf("\nenter a valied choice 1 or 2 or3 or 4 \n");
}
}while(c!=4);
}
void enqueue()
{
if(rear>=MAX-1)
printf("\n **********************QUEUE OVERFLOW****************\n");
if(front==-1)
front=0;
printf("\n enter the element to insert\n");
scanf("%d",&item);
queue[++rear]=item;

}
void dequeue()
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










