#include<stdio.h>
int c,usize,Asize,Bsize,i,j,flag;
int universal_set[20],bitstring_u[20],setA[20],bitstring_A[20],setB[20],bitstring_B[20],set_union[20],bitstring_union[20],bitstring_intersection[20],bitstring_diff[20];
void universal();
void set_A();
void set_B();
void union_(int arr[],int arr1[]);
void printresult(int arr[]);
void intersection(int arr[],int arr1[]);
void difference(int arr[],int arr1[]);
void main()
{
do
{
printf("\nenter your choice\n1.universal set\n2.set A\n3.setB\n4.union\n5.intersecion\n6.difference\n7.exit");
scanf("%d",&c);
switch(c)
{
case 1:
universal();
break;
case 2:
set_A();
break;
case 3:
set_B();
break;
case 4:
union_(bitstring_A,bitstring_B);
break;
case 5:
intersection(bitstring_A,bitstring_B);
break;
case 6:
difference(bitstring_A,bitstring_B);
break;
case 7:
printf("\n****************************EXIT POINT****************************************\n");
break;
default:
printf("\nenter a valied choice\n");
}
}while(c!=7);
}
void universal()
{
printf("\n enter the size of universal set\n");
scanf("%d",&usize);
for(i=0;i<usize;i++)
{
printf("enter the element");
scanf("%d",&universal_set[i]);
bitstring_u[i]=1;
}
printf("\n universal set is:\n");
printf("{");
for(i=0;i<usize;i++)
printf("%d,",universal_set[i]);
printf("}");
printf("\ncorresponding bitstring is:");
for(i=0;i<usize;i++)
printf("%d",bitstring_u[i]);
}
void set_A()
{
printf("\n enter the size of set A\n size of A must less than the size of universal set\n");
scanf("%d",&Asize);
for(i=0;i<Asize;i++)
{
printf("\nenter the element\nelement must be present in universal set\n");
scanf("%d",&setA[i]);
}
for(i=0;i<usize;i++)
{
flag=0;
for(j=0;j<Asize;j++)
if(universal_set[i]==setA[j])
{
flag=1;
break;
}
if(flag==1)
bitstring_A[i]=1;
else
bitstring_A[i]=0;
}
printf("\nset A is:\n");
printf("{");
for(i=0;i<Asize;i++)
printf("%d,",setA[i]);
printf("}");
printf("\ncorresponding bitstring is:");
for(i=0;i<usize;i++)
printf("%d",bitstring_A[i]);
}
void set_B()
{
printf("\n enter the size of set B\n size of B must less than the size of universal set\n");
scanf("%d",&Bsize);
for(i=0;i<Bsize;i++)
{
printf("enter the element\nelement must be present in universal set\n");
scanf("%d",&setB[i]);
}
for(i=0;i<usize;i++)
{
flag=0;
for(j=0;j<Bsize;j++)
if(universal_set[i]==setB[j])
{
flag=1;
break;
}
if(flag==1)
bitstring_B[i]=1;
else
bitstring_B[i]=0;
}
printf("\nset B is:\n");
printf("{");
for(i=0;i<Bsize;i++)
printf("%d,",setB[i]);
printf("}");
printf("\ncorresponding bitstring is:");
for(i=0;i<usize;i++)
printf("%d",bitstring_B[i]);
}
void union_(int arr[],int arr1[])
{
for(i=0;i<usize;i++)
bitstring_union[i]=arr[i]|arr1[i];
printf("\nunion of two sets:\n");
printresult(bitstring_union);
}
void printresult(int arr[])
{
printf("{");
for(i=0;i<usize;i++)
if(arr[i]==1)
{
printf("%d,",universal_set[i]);
}
printf("}");
}
void intersection(int arr[],int arr1[])
{
for(i=0;i<usize;i++)
bitstring_intersection[i]=bitstring_A[i]&bitstring_B[i];
printf("\nintersection of two sets:\n");
printresult(bitstring_intersection);
}
void difference(int arr[],int arr1[])
{
int temp[20];
for(i=0;i<usize;i++)
temp[i]=~arr1[i];
for(i=0;i<usize;i++)
bitstring_diff[i]=bitstring_A[i]&temp[i];
printf("\ndifference of two sets:\n");
printresult(bitstring_diff);
}