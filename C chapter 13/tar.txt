#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *spt, *tpt;
    int ch;
    if(argc < 3)
    {
        printf("Too less argument.\n");
        exit(EXIT_FAILURE);
    }
    if((spt = fopen(argv[1], "rb")) == NULL)
    {
        printf("File %s failed to be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((tpt = fopen(argv[2], "wb")) == NULL)
    {
        printf("Fail to open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(spt)) != EOF)
        putc(ch, tpt);
    fclose(spt);
    fclose(tpt);

    return 0;
}
