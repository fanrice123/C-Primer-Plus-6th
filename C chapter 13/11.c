#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char buf[200];
    if(argc < 3)
    {
        puts("Too few arguments.\n");
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Fail to open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while(fgets(buf, 200, fp))
    {
        if(strstr(buf, argv[1]))
            fputs(buf, stdout);
    }
    fclose(fp);
    puts("Done.");

    return 0;
}
