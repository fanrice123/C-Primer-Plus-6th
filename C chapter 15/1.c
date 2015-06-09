#include <stdio.h>
#include <limits.h>
#define MASK 0x1

unsigned int btoi(char *);

int main(void)
{
    int size = CHAR_BIT * sizeof(int) + 1;
    char arr[size];
    scanf("%s", arr);
    unsigned int value = btoi(arr);
    printf("%u", value);

    return 0;
}

unsigned int btoi(char * arr)
{
    unsigned int ret_val = 0;
    unsigned int flag = 1;
    int c = 0;
    while(arr[c])
        c++;
    for(int i = c-1; i >= 0; i--, flag <<= 1)
        if(arr[i] - '0')
            ret_val |= flag;

    return ret_val;
}
