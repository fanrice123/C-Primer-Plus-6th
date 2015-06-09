#include <stdio.h>

int count_bits(int);

int main(void)
{
    int input;
    scanf("%d", &input);
    printf("has %d on_bit(s).\n", count_bits(input));

    return 0;
}

int count_bits(int n)
{
    int count = 0;
    for(int i = 0; i < 32; i++, n >>= 1)
        if(n & 0x1)
            count++;

    return count;
}
