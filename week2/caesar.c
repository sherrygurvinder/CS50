#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int arg,char* arg1[])
{ 
	if(arg!=2)
	{	
		printf("Usage: ./caesar k\n");
		return 1;
	}
	char p1[100],p2[100];
	int key,key1,temp,asc,i=0,count;
	key=atoi(arg1[1]);
	key=key%26;
	printf("\nplaintext:");
	fgets(p1,50,stdin);
	count=strlen(p1);
 	count=count-1;
	while(count>0)
	{	
		if(p1[i]>=65&&p1[i]<=90)
		{
			asc=p1[i];
			temp=90-asc;
			if(temp==0&&key!=0)
			{
				p2[i]=65+key-1;
			}
			else if(temp==0&&key==0)
			{
				p2[i]=asc;
			}
			else if(temp<key)
			{
				p2[i]=asc+temp;
				key1=key-temp;
				p2[i]=65+key1-1;
				key1=0;			
			}	
			else
			{
				p2[i]=asc+key;
			}
			
		}
		else if(p1[i]>=90&&p1[i]<=122)
		{
			asc=p1[i];
			temp=122-asc;
			if(temp==0&&key!=0)
			{
				p2[i]=97+key-1;
			}
			else if(temp==0&&key==0)
			{
				p2[i]=asc;
			}
			else if(temp<key)
			{
				p2[i]=asc+temp;
				key1=key-temp;
				p2[i]=97+key1-1;
				key1=0;			
			}	
			else
			{
				p2[i]=asc+key;
			}
		
		}
		else
		{
			p2[i]=p1[i];
		}
			i++;
			count--;
		
	}
	p2[i]='\0';
	i=0;
	printf("ciphertext:");
	while(p2[i]!='\0')
	{
		printf("%c",p2[i]);
		i++;
	}
	printf("\n");
	return 0;
}


