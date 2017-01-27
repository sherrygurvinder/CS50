/**
 * Prompts user for as many as MAX values until EOF is reached, 
 * then proceeds to search that "haystack" of values for given needle.
 *
 * Usage: ./find needle
 *
 * where needle is the value to find in a haystack of values
 */
       
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include "helpers.c"
int get_int()
{       
    int n;
    //printf("Enter Interger");
    scanf("%d",&n);
    return n;
}
// maximum amount of hay
const int MAX = 65536;

int main(int argc,char* argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int size;
    unsigned int haystack[MAX];
    int straw;
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        //printf("\nhaystack[%i] = ", size);
        straw = get_int();
        if (straw ==32767)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // sort the haystack
    sort(haystack, size);

    // try to find needle in haystack
    if (search(needle, haystack, size))
    {
        printf("\nFound needle in haystack!\n\n");
        return 0;
    }
    else
    {
        printf("\nDidn't find needle in haystack.\n\n");
        return 1;
    }
    return 0;
}
