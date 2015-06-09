#include <stdio.h>
#include <stdlib.h>
char *s_gets(char *,const int);
int main(int argc, char *argv[])
{
    FILE * fp;
    char input[80], *pt = input;
    int sam, ch, i = 2;
    int count = 0;
    sam = argv[1][0];
    while(argc)
    {
        if(argc < 3)
        {
            printf("Enter a filename : ");
            s_gets(input, 80);
            if(input[0] == '\0')
                break;
        }
        else
        {
            if(i < argc)
            {
                pt = argv[i];
                i++;
            }
            else
                break;
        }
        if((fp = fopen(pt, "r")) == NULL)
        {
            printf("Failed to open file %s.\n", pt);
        }
        while((ch = getc(fp)) != EOF)
            if(ch == sam)
                count++;
        printf("%d\n", count);
        count = 0;
        fclose(fp);
    }
    puts("Done.");

    return 0;
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
