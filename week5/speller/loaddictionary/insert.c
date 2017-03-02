#include<stdio.h>

struct s
{
	int info;
	struct s* link;
	
};
struct s *start,*ptr;
int main()
{
	char ch='y';
	start=(struct s *)malloc(sizeof(struct s));
	ptr=start;
	while(ch=='y')
	{
		printf("enter no");
		scanf("%d",&ptr->info);
		printf("want to enter more");
		ch=getc(ch);
		if(ch=='y')
		{
		ptr->link=(struct s*)malloc(sizeof(struct s));
		ptr=ptr->link;
			
		}
		else
		ptr->link=NULL;
		
	}
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d",ptr->info);
		ptr=ptr->link;
	}
	return 0;
}
