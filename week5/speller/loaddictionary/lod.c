#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
	struct node *link;
	char dictionary[45];
	int info;
	
};
struct node * head[26];
struct node * ptr;
struct node * store;
void main()
{
	int  alphabetcounter=0;
	char str,str1,first;
	int c1=0,c2;
	int j=0;
	char *chrr = malloc(45 * sizeof(char));

	FILE * inptr=NULL;
	inptr=fopen("large","r+");
    printf("dictionary load into memory \n ");
    str = fgetc(inptr);
    first=str;

    store = (struct node*)malloc(sizeof(struct node));
 	*head=(struct node *)malloc(sizeof(struct node));
 	ptr=store;
   	head[alphabetcounter]->link=store;
    while(!(feof(inptr)))
    {	 
   		   
        while(str!='\n')
        { 
          chrr[i]=str;
          i++;
          str = fgetc(inptr);
        }
        chrr[i]='\0';
        if(str=='\n')
        	{	
        		strcpy(ptr->dictionary,chrr);
        		ptr->link=(struct node *)malloc(sizeof(struct node));
        		ptr=ptr->link;
        		str = fgetc(inptr);	
            if(first<str)
        		{	
              alphabetcounter++;
        			head[alphabetcounter]=(struct node *)malloc(sizeof(struct node));
        			ptr=head[alphabetcounter];
        			first=str;
        		}
        			
        	}
        	free(chrr);
        	chrr=malloc(45 * sizeof(char));
          i=0;
       
    }
    free(chrr);
    
    for(j=0;j<=alphabetcounter;j++)
    {
     	ptr=head[j];
    	while(ptr->link!=NULL)
   	  {
     		printf(" \n %s ",ptr->dictionary);
     		ptr=ptr->link;
   	  }
    }
      
}
