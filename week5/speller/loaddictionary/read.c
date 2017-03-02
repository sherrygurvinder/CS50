#include<stdio.h>

#include<string.h>
void main()
{
    FILE * inptr=NULL;

    //int  chr[45],count=0,i=0,remind=0,alphabetcounter=0;
    char str;
    //char *chrr;
    // = malloc(45 * sizeof(char));
    inptr=fopen("aa","r+");
     str = fgetc(inptr);
    //*chrr=str;

    printf("dictionary load into memory \n ");
   
    
 while(!(feof(inptr)))
   {	
   	//printf("sdfs");
   		printf(" str %c",str);
   		str = fgetc(inptr);
        if(str == '\n')
        	{	
        		printf("end of line");
        		str = fgetc(inptr);
       			
        	}
         
        }
       
     
         
     
 }