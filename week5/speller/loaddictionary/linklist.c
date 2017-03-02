#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
    struct node *link;
    int info;
        char dictionary[45];

};
struct node *start,*ptr;

void main()
{
    start = (struct node *)malloc(sizeof(struct node));
    ptr=start;
    FILE * inptr=NULL;

    int  n,chr[45],count=0,i=0,remind=0,alphabetcounter=0;
    char str,str1,first,*name;
    int c1=0,c2;   
    char *chrr = malloc(45 * sizeof(char));
    inptr=fopen("aa","r+");
     str = fgetc(inptr);
    *chrr=str;

    printf("dictionary load into memory \n ");
   
    
 while(!(feof(inptr)))
   {	

   		
        while(str!='\n')
        {
        	chrr[i]=str;
        	i++;
        	 str = fgetc(inptr);
        }
        if(str=='\n')
        	{	
        		//str = fgetc(inptr);
                strcpy(ptr->dictionary,chrr);
                //printf(" \n word %s",ptr->dictionary);
        		ptr->link=(struct node *)malloc(sizeof(struct node));
                ptr=ptr->link;
        	}
                free(chrr);
            chrr=malloc(45 * sizeof(char));
            i=0;
        }
         printf("word %s \n ",ptr->dictionary);
         free(chrr);
         ptr=start;
         while(ptr->link!=NULL)
         {        

                  printf("word %s \n ",ptr->dictionary);
                  ptr=ptr->link;
         }
         
     
 }