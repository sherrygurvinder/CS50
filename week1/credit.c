#include<stdio.h>
long long int get_long_long()
{
	long long int n;
	printf("NUMBER:");
	scanf("%lld",&n);
	while(n<=0)
	{
		printf("INVALID:");
		scanf("%lld",&n);
	}
	return n;
}

void main()
{

	int i=1,temp1=0,temp=0,sum=0,sum1,sum2,result=0,final,count=0;
	long long int n,n1,n3,n4;
	n=get_long_long();
	n3=n;	
	n1=n;
	n4=n;
	while(n3!=0)
	{
		count++;
		n3=n3/10;
	}
	//printf(" \ncount %d",count);
	while(n1!=0)
	{
		n=n1%10;
		n1=n1/10;
		if(i%2==0)
		{
			temp=0;
			temp=temp+n;
			temp=temp*2;
			if(temp>=10)
			{
				sum1=temp/10;
				sum2=temp%10;
				sum=sum1+sum2;
				result=result+sum;	
			}
			else
			{
				result=result+temp;
			}
		}
		else
		{
			temp1=temp1+n;
		}
		i++;	
	}
	final=temp1+result;		
	if(final%10==0)
	{	
		
		if(count==15&&(n4/10^13==34||n4/10^13==37))
		{
			printf("Amex\n");           
          	}	
		if(count==16&&(n4/10^14==51||n4/10^14==52||n4/10^14==53||n4/10^14==54||n4/10^14==55))
		{
			printf("Master Card\n");
  		}        	
		if((count==13||count==16)&&(n4/10^12==4||n4/10^15==4))
		{
			printf("Visa\n"); 
		}
	}
    
	else
      	{
		printf("INVALID\n");
	}		
	

	
}
