#include <stdio.h>
#include <stdlib.h>
void countnum(int);
static int count[10];

int main(void)
{
    for(int i = 0; i < 10; i++)
    {
        srand((i+1) * 13);
        for(int x = 0; x < 10; x++)
            count[x] = 0;
        for(int i = 0; i < 1000; i++)
            countnum(rand() % 10);
        for(int i = 0; i < 10; i++)
            printf("%4d", i+1);
        putchar('\n');
        for(int i = 0; i < 10; i++)
            printf("%4d", count[i]);
        putchar('\n');
    }
    return 0;
}

void countnum(int n)
{
    extern int count[];
    switch(n)
    {
    case 1:
        count[1]++;
        break;
    case 2:
        count[2]++;
        break;
    case 3:
        count[3]++;
        break;
    case 4:
        count[4]++;
        break;
    case 5:
        count[5]++;
        break;
    case 6:
        count[6]++;
        break;
    case 7:
        count[7]++;
        break;
    case 8:
        count[8]++;
        break;
    case 9:
        count[9]++;
        break;
    default:
        count[0]++;
        break;
    }
}
