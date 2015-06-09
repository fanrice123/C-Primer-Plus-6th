#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char ch1, ch2;
    FILE *fp1, *fp2;
    if((fp1 = fopen(argv[1], "r")) == NULL)
    {
        printf("Open file %s failed.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((fp2 = fopen(argv[2], "r")) == NULL)
    {
        printf("Open file %s failed.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    ch1 = getc(fp1);
    ch2 = getc(fp2);
    while(ch1 != EOF || ch2 != EOF)
    {
        while(ch1 != EOF && ch1 !='\n')
        {
            putchar(ch1);
            ch1 = getc(fp1);
        }
        if(ch1 != EOF)
        {
            putchar('\n');
            ch1 = getc(fp1);
        }
        while(ch2 != EOF && ch2 != '\n')
        {
            putchar(ch2);
            ch2 = getc(fp2);
        }
        if(ch2 != EOF)
        {
            putchar('\n');
            ch2 = getc(fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
