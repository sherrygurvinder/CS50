#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
	struct node *link;
	char dictionary[45];
	int info;
	
}head[26];
struct node * ptr;
struct node * store;
void main()
{
	int  n,chr[45],count=0,i=0,remind=0,alphabetcounter=0;
	char str,str1,first;
	int c1=0,c2;
	int j=0;
	char *chrr = malloc(45 * sizeof(char));
	

	FILE * inptr=NULL;
	inptr=fopen("aa","r+");
    printf("dictionary load into memory \n ");
    str = fgetc(inptr);
    first=str;

    store = (struct node*)malloc(sizeof(struct node));
 	ptr=store;
    while(!(feof(inptr)))
    {

   		//str = fgetc(inptr);
        while(str != '\n')
        {
        	chrr[i] = str;
        	i = i+1;
        	str = fgetc(inptr);
        }

       if(str == '\n')
        	{	
        		
        		//printf("%s",);
        		strcpy(ptr->dictionary, chrr);
        		printf(" \n %s dictionary",ptr->dictionary);
        		ptr->link=(struct node *)malloc(sizeof(struct node));
        		ptr=ptr->link;
        		//printf("in if");
			}
			printf("before str\n");
			str=fgetc(inptr);
			//printf("after str");
			i=0;
			free(chrr);
			char *chrr = malloc(45 * sizeof(char));

	}
	free(chrr);
}