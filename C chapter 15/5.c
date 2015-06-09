#include <stdio.h>

unsigned rotate(unsigned, int);

int main(void)
{
    unsigned value;
    int times;
    while(scanf("%u", &value) == 1)
    {
        scanf("%d", &times);
        value = rotate(value, times);
        printf("%u\n", value);
    }

    return 0;
}

unsigned rotate(unsigned val, int times)
{
    unsigned mask = 1 << 31;
    for(int i = 0; i < times; i++)
    {
        if(val & mask)
        {
            val <<= 1;
            val |= 1;
        }
        else
            val <<= 1;
    }

    return val;
}
