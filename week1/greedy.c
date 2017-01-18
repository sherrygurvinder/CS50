#include<stdio.h>
#include<stdlib.h>
float ask_amount()
{

	float amount;char a[10];
	fgets(a,sizeof a,stdin);
	amount=atof(a);	

	while(amount<=0)
	{
	  	printf("Retry:");
		 fgets(a,sizeof a,stdin);
       		 amount=atof(a); 
	}
	return amount;
}

void main()
{
	int coins=0,temp=0,i=0,amount=0;
	float am;
	int money[5]={25,10,5,1};
	printf("O hai! How much change is owed? \n");
	am=ask_amount();
	amount=am*100;
	
	while(amount!=0)
	{
		if(amount>=money[i])
		{
			temp=(amount/money[i]);
			amount=(amount%money[i]);
			coins=coins+temp;
		}
		else
		{
			i++;
		}
	}
	printf("%d \n ",coins);
}
