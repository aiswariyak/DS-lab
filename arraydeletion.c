#include<stdio.h>
void main()
{
int arr[20],n,i,loc;
printf("\n enter the size of the array\n");
scanf("%d",&n);
printf("\n enter the %d array elements\n",n);
for(i=0;i<n;i++)
scanf("%d",&arr[i]);
printf("\nenter the location  of the element you want to delete\n");
scanf("%d",&loc);
for(i=loc-1;i<n;i++)
arr[i]=arr[i+1];
printf("\nthe array after deletion\n");
for(i=0;i<n-1;i++)
printf(" %d ",arr[i]);
}

