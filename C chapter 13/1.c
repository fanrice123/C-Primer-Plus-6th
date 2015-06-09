#include <stdio.h>
#include <stdlib.h> //627
#define SIZE 80

char *s_gets(char *, int);

int main(void)
{
    int ch;
    char filename[SIZE];
    FILE *fp;
    unsign long count = 0;
    fputs("File Name: ", stdout);
    if(*s_gets(filename,SIZE) == NULL)
    {
        printf("Usage: %s filename\n", filename);
        exit(EXIT_FAILURE);
    }


}

char *s_gets(char *arr, const int size)
{
    char *ret_val;
    if(( ret_val = fgets(arr,size,stdin)) != NULL)
        while(*arr)
        {
            if(*arr == '\n')
            {
                *arr = '\0';
                break;
            }
            if(*arr == '\0')
                break;
            arr++;
        }
    fflush(stdin);
    return ret_val;
}
