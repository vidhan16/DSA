#include <stdio.h>
#include <stdlib.h>
char* calloc_custom(int i,int j)
{
    void *ptr = malloc(i*j);
    for(int k = 0 ; k < i*j ;k++)
    {
        char *currByte = (char*)ptr+k;
        currByte = 0;
    }
}