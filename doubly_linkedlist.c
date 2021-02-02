#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* next;
struct node* prev;
}*start=NULL,*last=NULL,*newnode,*temp,*temp2;
int n,i,c,pos,count=0,data;
void insert_first();
void insert_at_any_position();
void insert_end();
void delete_first();
void delete_at_any_position();
void delete_end();
void search();
void display_forward();
void display_reverse();
 void main()
{
do
{
printf("\nenter your choice\n1.insert at begining\n2.insert at a specified position\n3.insert at the end\n4.Delete at begining\n5.delete at a speified position\n6.deletion at end\n7.Display_forward\n8.display_reverse\n9.search\n10.Exit");
scanf("%d",&c);
switch(c)
{
case 1:
insert_first();
break;
case 2:
insert_at_any_position();
break;
case 3:
insert_end();
break;
case 4:
delete_first();
break;
case 5:
delete_at_any_position();
break;
case 6:
delete_end();
break;
case 7:
display_forward();
break;
case 8:
display_reverse();
break;
case 9:
search();
break;
case 10:
printf("\n****************EXIT POINT*****************\n");
break;
default:
printf("\n enter a valied choice\n");
}
}while(c!=10);
}
void insert_first()
{
printf("\nenter the data\n");
newnode=(struct node*)malloc(sizeof(struct node));
scanf("%d",&newnode->data);
newnode->next=NULL;
newnode->prev=NULL;
if(start==NULL)
{
start=newnode;
last=newnode;
}
else
{
newnode->next=start;
start->prev=newnode;
start=newnode;
}
count++;
}
void insert_at_any_position()
{
printf("\nenter the position\n");
scanf("%d",&pos);
if(pos==1)
insert_first();
else if(pos<=count)
{
printf("\nenter the data\n");
newnode=(struct node*)malloc(sizeof(struct node));
scanf("%d",&newnode->data);
for(temp=start,i=1;i<pos-1;temp=temp->next,i++)
{
}
temp2=temp->next;
newnode->next=temp2;
newnode->prev=temp;
temp->next=newnode;
temp2->prev=newnode;
count++;
}
else
{
printf("\n*******************enter a valied position*****************");
}
}
void insert_end()
{
printf("\nenter the data\n");
newnode=(struct node*)malloc(sizeof(struct node));
scanf("%d",&newnode->data);
newnode->next=NULL;
newnode->prev=NULL;
if(start==NULL)
{
start=newnode;
last=newnode;
count++;
}
else
{

last->next=newnode;
newnode->prev=last;
last=newnode;
count++;
}
}
void delete_first()
{
if(count==0)
printf("\n************DOUBLY LINKED LIST EMPTY**********");
else
{
printf("\ndeleted element is %d\n",start->data);
if(start->next==NULL)
{
start=NULL;
last=NULL;
count--;
}
else
{
temp=start->next;
temp->prev=NULL;
start=temp;
count--;
}
}
}
void delete_at_any_position()
{
printf("\nenter the position\n");
scanf("%d",&pos);
if(pos>count)
printf("\n*******************enter a valied position*******************");
else
{
if(pos==1)
delete_first();
else if(pos==count)
delete_end();
else
{
for(temp=start,i=1;i<pos-1;temp=temp->next,i++)
{
}
temp2=temp->next;
printf("\ndeleted element is %d",temp2->data);
temp->next=temp2->next;
temp2=temp2->next;
temp2->prev=temp;
count--;
}
}
}
void delete_end()
{
if(count==0)
printf("\n*********************DOUBLY LINKED LIST EMPTY*******************************\n");
else
{
if(count==1)
delete_first();
else
{
printf("\ndeleted element is %d\n",last->data);
temp=last->prev;
temp->next=NULL;
last=temp;
count--;
}
}
}
void search()
{
int item;
if(count==0)
printf("***************************DOUBLY LINKED LIST EMPTY**************************");
else
{
printf("\nenter the element to search");
scanf("%d",&item);
for(temp=start;temp!=NULL;temp=temp->next)
{
if(temp->data==item)
{
printf("\nelement is found");
return;
}
}
printf("\nelement is not found\n");
}
}
void display_forward()
{
if(start==NULL)
printf("***************************DOUBLY LINKED LIST EMPTY**************************");
else
{
for(temp=start;temp!=NULL;temp=temp->next)
printf(" %d->",temp->data);
}
}
void display_reverse()
{
if(last==NULL)
printf("***************************DOUBLY LINKED LIST EMPTY**************************");
else
{
for(temp=last;temp!=NULL;temp=temp->prev)
printf(" %d->",temp->data);
}
}
