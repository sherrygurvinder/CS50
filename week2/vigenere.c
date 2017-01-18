#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int arg,char* arg1[])
{	char* key1,p1[100],p2[100];
	int i=0,key[100],n,key11,key22,temp,count,j=0,asc;
	//key=atoi(arg1[1]);
	key1=arg1[1];
	if(arg!=2)
	{
		printf("Usage: ./vigenere k \n");
		return 1;
	}
	while(key1[i]!='\0')
	{
		if(key1[i]>=65&&key1[i]<=90)
		{
			key[i]=key1[i]-65;
		}
		else if(key1[i]>=97&&key1[i]<=122)
		{
			key[i]=key1[i]-97;
		}
		else
		{	printf("Usage: ./vigenere k \n ");
			//return 1;
		}
		i++;
	}
	n=i;
	i=0;
	printf("plaintext:");
	fgets(p1,50,stdin);
	count=strlen(p1);
 	count=count-1;
	j=0;
	printf("ciphertext:");
	while(count>0)
	{	
		if(j==n)
		{
			j=0;
		}
		if(p1[i]>=65&&p1[i]<=90)
		{
			asc=p1[i];
			//printf("\n ascii value p1[%d]  chracter %c",asc,p1[i]);
			temp=90-asc;
			//printf(" \n allowed character %d",temp);
			if(key[j]>temp)
			{
				p2[i]=asc+temp;
				//printf("\n p2 %d key %d",p2[i],key[j]);
				key11=key[j]-temp;
				//printf("\n remaining key %d",key11); 
				p2[i]=65+key11-1;
				printf(" %c",p2[i]);
				key11=0;
			}
			else
			{	
				//printf(" \n ASC+key %d + %d = ",asc,key[j]);
				p2[i]=asc+key[j];
				printf("%c",p2[i]);
			}
		j++;
		}
		else if(p1[i]>=97&&p1[i]<=122)
		{	
			asc=p1[i];
			temp=122-asc;
			if(key[j]>temp)
			{
				p2[i]=asc+temp;
				key11=key[j]-temp;
				p2[i]=97+key11-1;
				key11=0;	
				printf("%c",p2[i]);		
			}	
			else
			{
				p2[i]=asc+key[j];
				printf("%c",p2[i]);
			}
		
		j++;		
		}
		else
		{
			p2[i]=p1[i];
			printf("%c",p2[i]);
			
		}
	
	i++;
	count--;
	}
	//printf("\n %c ",p2[1]);
	//p2[i]='\0';
	//i=0;
	//printf("ciphertext:");
	/*while(p2[i]!='\0')
	{
		printf("%c",p2[i]);
		i++;
	}
*/
	printf("\n");

	
	return 0;
}

