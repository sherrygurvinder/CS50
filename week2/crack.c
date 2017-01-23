#define _XOPEN_SOURCE
#define _GNU_SOURCE
#include<stdio.h>
#include<string.h>
#include<crypt.h>
#include <stdlib.h>
int increment(int Index1)
{
    if(Index1==90)
        return 97;
    else
        return ++Index1;
}
int main(int arg,char *argv[])
{
    int Index1=65,Index2,Index3,Index4;
    char *Password,*HashPassword;
    char *hash = argv[1];
    const char *const salt = "50";
    if(arg!=2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    while(Index1<=122)
    {   Index2=65;
        while(Index2<=122)
            {   Index3=65;
                while(Index3<=122)
                    {   Index4=65;
                        while(Index4<=122)
                            {   
                               	sprintf(Password,"%c%c%c%c",Index1,Index2,Index3,Index4);
                               	 HashPassword= crypt(Password,salt);
                                if (strcmp(HashPassword,hash) == 0)
                                 {
                                   printf("%s\n", Password);
                                   exit(0);
                                 }
                                Index4=increment(Index4);
                            }      
                    Index3=increment(Index3);
                    }
              
            Index2=increment(Index2);
            }                                                           
     Index1=increment(Index1);
     }
return 0;
}

