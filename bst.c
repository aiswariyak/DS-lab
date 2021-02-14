#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* left;
struct node* right;
}*newnode,*root=NULL,*temp;
struct node* insert (struct node *root,struct node *newnode);
struct node* delete (struct node *root,int value);
struct node* inorder_successor(struct node *root);
struct node* search(struct node *root,int value);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
int c,value,min;
void main()
{
do
{
printf("\nenter the choice\n1.insert\n2.delete\n3.search\n4.inorder_traversal\n5.preorder_traversal\n6.postorder_traversal");
scanf("%d",&c);
switch(c)
{
case 1:
{
printf("\nenter the data\n");
newnode=(struct node *)malloc(sizeof(struct node));
scanf("%d",&newnode->data);
newnode->left=NULL;
newnode->right=NULL;
root=insert(root,newnode);
break;
}
case 2:
printf("\nenter the element to delete\n");
scanf("%d",&value);
delete(root,value);
break;
case 3:
printf("\nenter the element to search");
scanf("%d",&value);
if(search(root,value)==NULL)
printf("\nelement is not found\n");
else
printf("\nelement found\n");
break;
case 4:
inorder(root);
break;
case 5:
preorder(root);
break;
case 6:
postorder(root);
break;
case 7:
printf("\n***********************************exit point***************************");
break;
default:
printf("\nenter a valied choice\n");
}
}while(c!=7);
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!INSERTION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
struct node * insert(struct node* root,struct node *newnode)
{
if(root==NULL)
{
root=newnode;
return root;
}
else if(newnode->data<=root->data)
{
root->left=insert(root->left,newnode);
}
else
{
root->right=insert(root->right,newnode);
}
return root;
}

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!DELETION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
struct node* delete(struct node *root,int value)
{
if(root==NULL)
{
return root ;
}
else if(value<root->data)
{
root->left=delete(root->left,value);
}
else if(value>root->data)
{
root->right=delete(root->right,value);
}
else
{

/*!!!!!!!!!!!!!!!!!!!!!NO CHILD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
if(root->left==NULL && root->right==NULL)
{
free(root);
return NULL;
}

/*!!!!!!!!!!!!!!!!!!!!!ONE CHILD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
else if((root->left==NULL && root->right!=NULL )||(root->right==NULL &&root->left!=NULL))
{
if(root->left==NULL)
temp=root->right;
if(root->right==NULL)
temp=root->left;
free(root);
return temp;
}
/*!!!!!!!!!!!!!!!!!!!!!TWO CHILD!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
else
{
temp=inorder_successor(root->right);
root->data=temp->data;
root->right=delete(root->right,temp->data);
}
}
return root;
}
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!FIND MINIMUM!!!!!!!!!!!!!!!!!!!!!!*/
struct node* inorder_successor(struct node *root)
{
if(root==NULL)
return NULL;
if(root->left==NULL)
return root;
return inorder_successor(root->left);
}

/*!!!!!!!!!!!!!!!!!!!!!SEARCH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
struct node* search(struct node *root,int value)
{
if(root==NULL)
return NULL;
if(root->data==value)
return root;
else if(value<root->data)
return search(root->left,value);
else
return search(root->right,value);
}
void inorder(struct node *root)
{
if (root==NULL)
return;
else
{
inorder(root->left);
printf("%d->",root->data);
inorder(root->right);
}
}
void preorder( struct node *root)
{
if(root==NULL)
{
return; 
}
printf("%d->",root->data);
preorder(root->left);
preorder(root->right);
}
void postorder(struct node *root)
{
if(root==NULL)
{
return; 
}
preorder(root->left);
preorder(root->right);
printf("%d->",root->data);
}
