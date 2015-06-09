#include <stdio.h>
#include <stdlib.h>
char *s_gets(char *, const int);

int main(void)
{
    FILE *fp;
    char filename[50];
    char buff[200];
    long po;
    int ch;
    s_gets(filename, 50);
    if((fp = fopen(filename, "r")) == NULL)
    {
        printf("Failed to open file %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Enter the file position : ");
    while((scanf("%ld", &po) == 1) && po > 1)
    {
        fseek(fp, po, SEEK_SET);
        fgets(buff, 200, fp);
        puts(buff);
    }
}

char *s_gets(char *arr, const int SIZE)
{
    char *ret_val;
    if(ret_val = fgets(arr, SIZE, stdin))
    {
        while(*arr != '\0')
        {
            if(*arr == '\n')
                *arr = '\0';
            arr++;
        }
    }
    fflush(stdin);

    return ret_val;
}
