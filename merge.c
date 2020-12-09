#include<stdio.h>
void main()
{
int a[20],b[20],c[20],temp[20],i,m,n,j,k;

printf("\n enter the size of first array\n");
scanf("%d",&m);
printf("\n enter the %d array elements\n",m);
for(i=0;i<m;i++)
scanf("%d",&a[i]);
printf("\n enter the size of second array\n");
scanf("%d",&n);
printf("\n enter the %d array elements\n",n);
for(j=0;j<n;j++)
scanf("%d",&b[j]);
for(i=0,k=0;i<m;i++,k++)
c[k]=a[i];
for(j=0;j<n;j++,k++)
c[k]=b[j];
printf("\n the merged array is:\n");
for(k=0;k<m+n;k++)
printf(" %d ",c[k]);
for(i=0;i<m+n-1;i++)
for(j=0;j<m+n-1;j++)
{
if(c[j+1]<c[j])
{
temp[j]=c[j];
c[j]=c[j+1];
c[j+1]=temp[j];
}
}
printf("\n the merged sorted array is:\n");
for(i=0;i<m+n;i++)
printf(" %d ",c[i]);
}
