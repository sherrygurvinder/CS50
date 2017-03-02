#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <stdlib.h>
#undef calculate
#undef getrusage
//#ifndef DICTIONARY_H
//#define DICTIONARY_H
#define DICTIONARY "dictionaries/large"

#include <stdbool.h>

bool load(const char *dictionary)
{
    // TODO

    FILE * inptr;
    int string;
    int count=0;
    typedef struct Node
    {
        struct Node *link;
        char word[46];
    }START;

    struct Node *link1 =(struct Node *)malloc(sizeof(struct Node));
    inptr=fopen("large","r+");
    printf("dictionary load into memory \n ");
    while(inptr!=EOF)
   {
        string = fgetc(inptr);
        printf("%c \n",string);
        if(count==50)
        break;
        count++;
        //*/

   }
    //return false;
}

int main(int argc, char *argv[])
{
    // check for correct number of args
    if (argc != 2 && argc != 3)
    {
        printf("Usage: speller [dictionary] text\n");
        return 1;
    }

    // structs for timing data
    struct rusage before, after;

    // benchmarks
    double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;

    // determine dictionary to use
  char* dictionary = (argc == 3) ? argv[1] : DICTIONARY;

    // load dictionary
    getrusage(RUSAGE_SELF, &before);
    bool loaded = load(dictionary);
        getrusage(RUSAGE_SELF, &after);
}
