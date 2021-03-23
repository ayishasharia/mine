#include<stdio.h>
#include<stdlib.h>
struct node *L=0,*t;
struct node
{
int key;
struct node *prev ,*next;
};
void main()
{
struct node * insertdll(struct node *,int);
struct node * deletedll(struct node *,struct node*);
struct node * search(struct node *,int);
void display(struct node *);
int opt,key;
do
{
printf("\n 1.insert \n 2.delete \n 3.search \n 4.display \n 5.exit\n");
printf("option:");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Data: ");
      scanf("%d",&key);
      L=insertdll(L,key);
      break;
case 2:printf("Data: ");
      scanf("%d",&key);
      t=search(L,key);
      if(t!=(struct node *)0)
      {
        L=deletedll(L,t);
      printf("%d is deleted",key);
}
else
       printf(" Not found\n");
       break;
case 3:printf("Data: ");
      scanf("%d",&key);
      t=search(L,key);
      if(t!=(struct node *)0)
      {
      printf("%d found",key);
      }
      else printf(" Not found\n");
       break;
case 4:display(L);
      break;
case 5:exit(0);
      break;
}
}while(1);
}
struct node * insertdll(struct node *L1,int k)
{
struct node *X;
X=(struct node*)malloc(sizeof(struct node));
X->key=k;
X->next=L1;
X->prev=(struct node *)0;
if(L1!=(struct node *)0)
L1->prev=X;
L1=X;
return L1;
}
void display(struct node *L1)
{
while(L1!=(struct node *)0){
printf("%d",L1->key);
L1=L1->next;
}
}
struct node * search(struct node *L1,int key1)
{
while(L1!=(struct node*)0 && L1->key!=key1)
L1=L1->next;
return L1;
}
struct node * deletedll(struct node *L1,struct node *X)
{
if(X->prev!=(struct node *)0)
X->prev->next=X->next;
else
L1=L1->next;
if(X->next!=(struct node *)0)
X->next->prev=X->prev;
return L1;
}

