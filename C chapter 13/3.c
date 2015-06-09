#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char *s_gets(char *, const int);

int main(void)
{
    FILE *source, *target;
    char input[80];
    int ch;
    fputs("Enter the source file name : ", stdout);
    s_gets(input, 80);
    if((source = fopen(input, "r")) == NULL)
    {
        printf("Open file %s failed.\n", input);
        exit(EXIT_FAILURE);
    }
    fputs("Enter the target file name : ", stdout);
    s_gets(input, 80);
    if((target = fopen(input, "w")) == NULL)
    {
        printf("Open file %s failed.\n", input);
        exit(EXIT_FAILURE);
    }
    while((ch = toupper(getc(source))) != EOF)
        putc(ch, target);
    fclose(target);
    fclose(source);

    return 0;
}

char *s_gets(char *arr, const int SIZE)
{
    char *ret_val;
    if((ret_val = fgets(arr, SIZE, stdin)) != NULL)
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
