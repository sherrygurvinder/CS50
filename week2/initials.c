#include<stdio.h>
#include<string.h>
void main()
{
	char str[50];
	gets(str);
	int i=0;
	while(str[i]!='\0')
	{
		if(str[i]!=' ')
		{
			if(i==0||str[i-1]==' ')
			{
				if(str[i]>=97&&str[i]<=122)
				{
					printf("%c",str[i]-32);
				}
				else
				{
					printf("%c",str[i]);
				}
			}
		}
	i++;
	}
	printf("\n");

}

