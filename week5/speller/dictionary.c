/**
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdbool.h>
#include "dictionary.h"
 #include <string.h>
 #include <malloc.h>

/**
 * Returns true if word is in dictionary else false.
 */
struct node
{
	struct node *link;
	char dictionary[45];
	int info;
	
};
struct node * head[26];
struct node * ptr;
struct node * store;
int count=0;
bool check(const char *word)
{
    // TODO
    int Ascii_value=0;
    Ascii_value=word[0];
     //printf("%d\n",Ascii_value);
    if(Ascii_value>=97)
    {
    	Ascii_value=Ascii_value-97;
    	
    }
    else
    {
    	Ascii_value=Ascii_value-65;
    }
   
    ptr=head[Ascii_value];
    	while(ptr->link!=NULL)
   	  {		
   	  		     
     		if(strcmp(word,ptr->dictionary)==0)
     		{
     			
     			return true;
     		} 
     		ptr=ptr->link;
   	  }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    int  alphabetcounter=0;
	char str,str1,first;
	int j=0,i=0;
	char *chrr = malloc(45 * sizeof(char));
	FILE * inptr=NULL;
	inptr=fopen(dictionary,"r+");
    printf("dictionary load into memory\n ");
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
        		count++;	
        		//printf("%s\n",ptr->dictionary );
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
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
   return count;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < 26; i++)
    	{
    		struct node *pointer = head[i];
    		while(pointer != NULL)
    		{
    			struct node *temp=pointer;
    			pointer=pointer->link;
    			free(temp);
    		}
    		free(pointer);
    	}
    	return true;
}
