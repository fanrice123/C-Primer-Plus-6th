#include <stdio.h>
#include <limits.h>

unsigned btoi(char *arr);
char *itob(unsigned, char *);
void manipulation(unsigned, unsigned, char *);

int main(int argc, char **argv)
{
    int size = CHAR_BIT * sizeof(unsigned);
    char bin[size + 2];
    int val_a, val_b;
    val_a = btoi(argv[1]);
    val_b = btoi(argv[2]);
    manipulation(val_a, val_b, bin);

    return 0;
}

unsigned btoi(char * arr)
{
    int c = 0;
    unsigned val = 0;
    unsigned flag = 1;
    while(arr[c])
        c++;
    for(int i = c-1; i >= 0; i--, flag <<= 1)
        if(arr[i] - '0')
            val |= flag;
    return val;
}

void manipulation(unsigned valx, unsigned valy, char * bin)
{
    unsigned result;
    result = valx | valy;
    char xxx[CHAR_BIT * sizeof(unsigned) + 2];
    printf("the original values of two arguments are %u and %u\n\n", valx, valy);
    printf("%s\n%s\n", itob(valx, bin), itob(valy, xxx));
    printf("OR operator : %u\n", result);
    printf("%s\n", itob(result, bin));
    result = valx & valy;
    printf("AND operator : %u\n", result);
    printf("%s\n", itob(result, bin));
    printf("~ operator two each number : %u %u\n", ~valx, ~valy);
    printf("%s\n%s\n", itob(~valx, bin), itob(~valy, bin));
    result = valx ^ valy;
    printf("^ operator : %u\nDone.\n", result);
    printf("%s\n", itob(result, bin));
}

char *itob(unsigned x, char * bin)
{
    int size = CHAR_BIT * sizeof(unsigned);
    for(int i = size; i >= 0; i--, x >>= 1)
        bin[i] = (x & 0x1) + '0';
    bin[size + 1] = '\0';

    return bin;
}
