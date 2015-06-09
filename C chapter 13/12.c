#include <stdio.h>
#include <stdlib.h>
#define RESULT "result12.txt"

int main(int argc, char *argv[])
{
    FILE *fp, *tfp;
    char buf[20][31];
    char ch;
    char converter[100];
    converter['0'] = ' ';
    converter['1'] = '.';
    converter['2'] = '\'';
    converter['3'] = ':';
    converter['4'] = '~';
    converter['5'] = '*';
    converter['6'] = '=';
    converter['7'] = '@';
    converter['8'] = '%';
    converter['9'] = '#';
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Fail to open the file.\n");
        exit(EXIT_FAILURE);
    }
    if((tfp = fopen(RESULT, "w")) == NULL)
    {
        printf("Fail to open file %s.\n", RESULT);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 20; i++)
    {
        if(fgets(buf[i], 32, fp))
        {
            buf[i][30] = '\0';
            for(int j = 0; ch = buf[i][j]; j++)
            {
                putchar(ch = converter[ch]);
                putc(ch, tfp);
            }
            putchar('\n');
            putc('\n', tfp);
        }
    }
    fclose(fp);
    fclose(tfp);
    puts("Done.");

    return 0;

}
