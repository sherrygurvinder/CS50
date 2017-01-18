#include<stdio.h>
int get_int()
{

	int n;
	scanf("%d",&n);

	while(n<=0&&n>=24)
	{
		printf("RETRY:");
		scanf("%d",&n);
	}
	return n;
}
void main()
{

	int n,i,j;
	printf("ENTER THE HEIGHT: ");
	n=get_int();

	for(i=n;i>0;i--)
	{	
		for(j=0;j<=n;j++)
		{
			if(j<=i-2)
			{
				printf(" ");
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}
}
