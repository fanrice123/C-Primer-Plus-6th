#include <stdio.h>

_Bool function(int, int);

int main(void)
{
    int input, position;
    _Bool r;
    while(scanf("%d", &input) == 1)
    {
        scanf("%d", &position);
        r = function(input, position);
        printf("%d", r);
    }
}

_Bool function(int val, int position)
{
    int mask = 1;
    val >>= position;

    return (val & mask) == 1;
}
