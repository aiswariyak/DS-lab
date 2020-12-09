#include<stdio.h>

void main()
{
int arr[30],i,n,loc,item;
printf("\n enter the size of the array\n");
scanf("%d",&n);
printf("\nenter the %d array elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("\n array before insertion\n");
for(i=0;i<n;i++)
printf("%d\n",arr[i]);
printf("\n enter the location you want to insert\n ");
scanf("%d",&loc);
printf("\n enter the element you want to insert\n");
scanf("%d",&item);
for(i=n-1;i>=loc-1;i--)
arr[i+1]=arr[i];
arr[loc-1]=item;
printf("\n the array after insertion\n");
for(i=0;i<=n;i++)
printf(" %d ",arr[i]);
}
