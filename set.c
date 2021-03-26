#include<stdio.h>
#include<stdlib.h>
struct bit
{unsigned char x:1;}; //for one bit storage only unsigned
int uset[]={1,2,3,4,5,6,7,8,9};  //globally declared uset
int size=9;
void main()
{
void readset(struct bit[],int n);
void printset(struct bit[]);
void unionset(struct bit[],struct bit[],struct bit[]);
void intersect(struct bit[],struct bit[],struct bit[]);
void difference(struct bit[],struct bit[],struct bit[]);
struct bit a[9]={0},b[9]={0},c[9]={0};
int n;
printf("no.of elements in A:");
scanf("%d",&n);
readset(a,n);
printf("no.of elements in B:");
scanf("%d",&n);
readset(b,n);
printf("set A:");
printset(a);
printf("set B:");
printset(b);
unionset(a,b,c);
printf("A union B:");
printset(c);
intersect(a,b,c);
printf("A intersect B:");
printset(c);
printf("A difference B:");
difference(a,b,c);
printset(c);
} //end of main
//read set and storing bit storage 
void readset(struct bit a[],int n)
{
int i,x,k;
printf("Enter %d elements:",n);
for(i=0;i<n;i++)
{
scanf("%d",&x);
for(k=0;k<size;k++)
if(uset[k]==x)
{
a[k].x=1;
break;
}
}
}
//function to print a set from bitstring representation
void printset(struct bit a[])
{
int k;
printf("{");
for(k=0;k<size;k++)
if(a[k].x!=0)
printf("%d,",uset[k]);
printf("}\n");
}
//union of two set representing a bit string
void unionset(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
c[k].x=a[k].x|b[k].x;
return;
}
// to find a difference b
void difference(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
if(a[k].x==1)
c[k].x=a[k].x ^ b[k].x;
return;
}
//to find a intersect b 
void intersect(struct bit a[],struct bit b[],struct bit c[])
{
int k;
for(k=0;k<size;k++)
c[k].x=a[k].x & b[k].x;
return;
}


