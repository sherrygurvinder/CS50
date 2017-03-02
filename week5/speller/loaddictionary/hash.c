#include<stdio.h>
#include<malloc.h>
struct node
{
	struct node *link;
	int info;
};
void main()
{
int  n,chr[45],count=0;
printf("enter the value of n");
scanf("%d",&n);
struct node *head[1000]; 
*head=(struct node *)malloc(sizeof(struct node));
while(count!=10)
{
head[count]->info=n ;
printf("%d",head[0]->info);
count++;
}
}