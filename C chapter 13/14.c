#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define RESULT "result12.txt"

int main(int argc, char *argv[])
{
    FILE *fp, *tfp;
    char buf[20][31], tar[20][31];
    char ch;
    int sidevalue = 0;
    int divider = 0;
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
            fputs(buf[i], stdout);
        }
    }
    putchar('\n');
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            sidevalue = 0;
            divider = 0;
            if(i != 0)
            {
                if( buf[i][j] != buf[i-1][j])
                {
                    sidevalue += buf[i-1][j];
                    divider++;
                }
            }
            if(i != 19)
            {
                if(buf[i][j] != buf[i+1][j])
                {
                    sidevalue += buf[i+1][j];
                    divider++;
                }
            }
            if(j > 0)
            {
                if( buf[i][j] != buf[i][j-1])
                {
                    sidevalue += buf[i][j-1];
                    divider++;
                }
            }
            if(j < 29)
            {
                if(buf[i][j] != buf[i][j+1])
                {
                    sidevalue += buf[i][j+1];
                    divider++;
                }
            }
            if(divider > 1)
            {
                tar[i][j] = (int) (((double)sidevalue) / divider);
            }
            else
                tar[i][j] = buf[i][j];
            putc(converter[tar[i][j]], tfp);
            putchar(converter[tar[i][j]]);
        }
        putc('\0', tfp);
        putchar('\n');
        putc('\n', tfp);
    }
    printf("\n%d %d %d %d %d %d %d %d %d %d", '0', '1', '2', '3', '4', '5', '6', '7', '8', '9');
    fclose(fp);
    fclose(tfp);
    puts("Done.");

    return 0;

}
