#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *rep;
}*head[30],*tail[30],*temp,*newnode;
struct node *rep_,*_rep,*rep1,*rep2,*tail1,*tail2,*head1,*head2;
int count=0,x,i,flag,c,y,pos1,pos2;
void display();
void makeset(int x);
struct node* findset(int x);
struct node* union_(int x,int y);
void main()
{
do
{
printf("\nenter your choice\n1.make set\n2.display set representatives\n3.union\n4.find set\n5.exit\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("\nenter the element\n");
scanf("%d",&x);
for(i=0;i<count;i++)
{
flag=0;
for(temp=head[i];temp!=NULL;temp=temp->next) 
{ 
if(temp->data==x)
{
flag=1;
printf("\n %d is already exists\n",x);
break;
}
}
}
if(flag==0)
makeset(x);
break;
case 2:
display();
break;
case 3:
printf("\nenter the  first element\n");
scanf("%d",&x);
printf("\nenter the second element\n");
scanf("%d",&y);
_rep=union_(x,y);
printf("\n!!!!!!!!!!!!!!!!!!UNION OF TWO SETS:!!!!!!!!!!!!!!!!!!!\n");
for(temp=_rep;temp!=NULL;temp=temp->next)
printf("%d->",temp->data);
break;
case 4:
printf("\nenter the element\n");
scanf("%d",&x);
rep_=findset(x);
if(rep_==NULL)
printf("\n%d is not present in disjoint set ds\n",x);
else
printf("\nrepresentative of the set containing %d is:%d\n",x,rep_->data);
break;
case 5:
printf("********************exit point***************************");
break;
default:
printf("\nenter a valied choice\n");
}
}while(c!=5);
}
void makeset(int x)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=x;
newnode->next=NULL;
newnode->rep=newnode;
head[count]=newnode;
tail[count]=newnode;
count++;
}
void display()
{
printf("!!!!!!!!!!!!THE REPRESENTATIVES OF EACH SET IS!!!!!!!!!!!!!!!!!:\n");
for(i=0;i<count;i++)
printf("\n%d\n",head[i]->data);
}
struct node* findset(int x)
{
for(i=0;i<count;i++)
{
temp=head[i];
while(temp!=NULL)
{
if(temp->data==x)
return temp->rep;
temp=temp->next;
}
}
return NULL;
}
struct node* union_(int x,int y)
{
rep1=findset(x);
rep2=findset(y);
if(rep1==NULL || rep2==NULL)
{
printf("\nelement not present in disjoint set ds\n");
return NULL;
}
if(rep1!=rep2)
{
for(i=0;i<count;i++)
if(head[i]==rep1)
{
head1=head[i];
tail1=tail[i];
pos1=i;
}
for(i=0;i<count;i++)
if(head[i]==rep2)
{
tail2=tail[i];
pos2=i;
}
tail2->next=head1;
tail[pos2]=tail[pos1];
temp=rep1;
while(temp!=NULL)
{
temp->rep=rep2;
temp=temp->next;
}
for(i=pos1;i<count;i++)
{
head[i]=head[i+1];
tail[i]=tail[i+1];
}
count--;
return rep2;
}
}