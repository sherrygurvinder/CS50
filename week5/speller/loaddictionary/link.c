#include<stdio.h>
#include<malloc.h>
struct node
{
	struct node *link;
	char name[45];
};
struct node *start,*ptr;
int main()
{
	start=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	int name1;
int count=5,i=0;
while(count!=0)
{
	printf("enter the name");
	scanf("%s",ptr->name);
	printf("%s",ptr->name);
	//ptr->name=name1;
		
		if(count!=0)
		{
		ptr->link=(struct node *)malloc(sizeof(struct node));
		ptr=ptr->link;
			
		}
		else
		ptr->link=NULL;
		count--;
		
	}
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%s",ptr->name);
		ptr=ptr->link;
	}
}
