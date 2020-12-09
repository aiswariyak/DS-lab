#include<stdio.h>
int stack[50],n,i,x,top,c,item;
void push(void);
void pop(void);
void display(void);

void main()
{
   top=-1;
printf("\n enter the size of stack\n");
scanf("%d",&n);
do
{
printf("\n select the operation you want to perform\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
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
printf("\n *************************exit point*************\n");
break;
}
default:
{
printf("\n enter any one of the following\n1\n2\n3\n4\n");
}
}
}
while(c!=4);

}
void push()
{

if(top>=n-1)
printf("\n stack is over flow\n");
else
{
printf("\n enter the element to push\n");
scanf("%d",&item);
stack[++top]=item;
}
}
void pop()
{
if(top<=-1)
printf("\nstack is underflow\n");
else
{
x=stack[top--];
printf("\n the popped element is:%d\n",x);
}
}

void display()
{
if(top>=0)
{
printf("\n**********the stack array is:*************\n");
 for(i=top;i>=0;i--)
printf("\n%d\n",stack[i]);
}
else
printf("\n empty stack\n");
}

