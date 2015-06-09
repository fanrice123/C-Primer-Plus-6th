#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;
    for(int i = 1; i < argc; i++)
    {
        if((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("FAIL OPEN FILE %s.\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        while((ch = getc(fp)) != EOF)
            putchar(ch);
        fclose(fp);
    }

    puts("Done.");
    printf("%d\n", argc);

    return 0;
}
