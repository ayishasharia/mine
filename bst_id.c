#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *lchild;
struct node *rchild;
};
void main()
{
struct node *tinsert(struct node *,int);
struct node *tdelete(struct node *,int);
void inorder(struct node *);
int opt,data;
struct node *root=0;
do{
printf("\n1.Insert\n2.Delete\n3.Traverse\n4.Exit\n");
printf("option");
scanf("%d",&opt);
switch(opt)
{
case 1: printf("Data:");
        scanf("%d",&data);
        root=tinsert(root,data);
        printf("succesfully inserted");
        break;

case 2: printf("Data to be deleted:");
        scanf("%d",&data);
        root=tdelete(root,data);
       
        break;
case 3: printf("Binary search tree content:\n");
        inorder(root);
        break;
case 4: exit(1);
}
}while(1);
}

//fuction to insert data in binary search tree
struct node *tinsert(struct node *root,int data)
{
struct node *t,*t1,*t2;
t=(struct node *)malloc(sizeof(struct node));
t->data=data;
t->lchild=t->rchild=(struct node *)0;
t1=root;
while(t1!=(struct node *)0 && t1->data!=data)
{
t2=t1;
if(data<t1->data)
t1=t1->lchild;
else
t1=t1->rchild;
}
if(root==(struct node *)0)
root=t;
else
{
if(t1==(struct node *)0)
{
if(data<t2->data)
t2->lchild=t;
else
t2->rchild=t;
}
else
printf("duplicate\n");
}
return root;
}

//function to inorder traverse the binary tree

void inorder(struct node *root)
{
if(root!=(struct node *)0)
{
inorder(root->lchild);
printf("\n%d\n",root->data);
inorder(root->rchild);
}
return;
}

//function to delete a data from binary tree.

struct node *tdelete(struct node *root,int data)
{
struct node *par,*t1,*sucpar,*t2;
par=(struct node *)0;
t1=root;
while(t1!=(struct node *)0 && t1->data!=data)
{
par=t1;
if(data<t1->data)
{
t1=t1->lchild;
}
else
t1=t1->rchild;
}
if(t1==(struct node *)0)
printf("Not found");
else
//delete root
{
if(t1==root)
{
//if root have no child
if(root->lchild==0 && root->rchild==0 && root->data==data)
root=(struct node *)0;
//if root have only one child
else if(root->lchild==0)
{
root=root->rchild;
root->rchild=(struct node *)0;
}
else if(root->rchild==0)
{
root=root->lchild;
root->lchild=(struct node *)0;
}
//if root have two child
else
{
sucpar=root;
t2=root->rchild;
while(t2->lchild!=0) //to find the extreme left
{
sucpar=t2;
t2=t2->lchild;
}
root->data=t2->data;
//copy the inorder successor data to the data to be inserted then remove inorder
if(t2->data<sucpar->data)
sucpar->lchild=t2->rchild;
else
sucpar->rchild=t2->rchild;
free(t2);
}
}
else if(t1->lchild==0 && t1->rchild==0)
{
if(t1->data<par->data)
par->lchild=0;
else par->rchild=0;
free(t1);
}
else if(t1->lchild==0)
{
if(t1->data<par->data)
par->lchild=t1->rchild;
else par->rchild=t1->rchild;
free(t1);
}
else if(t1->rchild==0)
{
if(t1->data<par->data)
par->lchild=t1->lchild;
free(t1);
}
else
{
sucpar=t1;
t2=t1->rchild;
while(t2->lchild!=0)
{
sucpar=t2;
t2=t2->lchild;
}
t1->data=t2->data;
//copy the inorder successor data to the data to be deleted
if(t2->data<sucpar->data)
sucpar->lchild=t2->rchild;
else
sucpar->rchild=t2->rchild;
free(t2);
}
}
return root;
}

