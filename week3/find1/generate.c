#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMIT 65536

int main(int argc,char* argv[])
{   
    int i;
    // TODO: comment me
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // TODO: comment me
    int n = atoi(argv[1]);

    // TODO: comment me
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // TODO: comment me
    for (i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
