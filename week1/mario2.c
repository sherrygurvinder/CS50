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

	int n,i,j,k,count=0;
	printf("ENTER THE HEIGHT: ");
	n=get_int();
	count=n;
	for(i=n;i>0;i--)
	{	       	
		for(j=0;j<=n*2;j++)
		{
		if(j==n)
		{
			printf(" ");
		}

		if(j<n)
		{
		
			if(j<i-1)
		{
				printf(" ");
		}
			else
		{
				printf("#");
		}

		}
			if(j>n)
			{
				if(j<=count+1)
				{
					printf("#");
				}
		else
		{
				printf(" ");
		}

		}
	
	}
		count++;

	
	printf("\n");
}
}
