#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char c = argv[1][0];
    FILE *fp;
    int time;

    if((fp = fopen(argv[2],"w")) == NULL)
        exit(EXIT_FAILURE);
    puts("How much line you want it to print in file?");
    scanf("%d", &time);
    for(int i = 0; i < time; i++)
    {
        for(int j = 0; j < 255; j++)
            putc(c,fp);
        putc('\n',fp);
    }
    fclose(fp);
    puts("Done.");

    return 0;
}
