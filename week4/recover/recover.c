#include<stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t  BYTE;

int main(int arg,char* argu[])
{	
	char *infile = argu[1];
	if (arg!=2)
	{
		printf("Usage: ./recover image \n");
		return 1;
	}

	FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open \n");
        return 2;
    }
    BYTE buffer[512];
    int count=0;
    while(fread(buffer,512,1,inptr)!=0)
    {
    	 
    	if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) == 0xe0)
    	{
    		char Image_Name[10];
            sprintf(Image_Name,"%03i.jpg",count++);
            FILE *image=fopen(Image_Name,"w");
            
            if (image == NULL)
            {
                printf("Could not open ");
                return 2;
            }
            fwrite(buffer, 512,1,image);
            fread(buffer,512,1,inptr);
       
            while(!(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0) == 0xe0))
            {
                
                fwrite(buffer, 512,1, image);
                if(fread(buffer, 512, 1, inptr)!=1)
                    break;
                
            }
            fseek(inptr,-512,SEEK_CUR);
            fclose(image);

    	}

    }
    fclose(inptr);
    return 0;
	
}