#include <stdio.h>
void print_times(void);

int main(void)
{
    int input;

    scanf("%d", &input);
    for(int i = 0; i < input; i++)
        print_times();

    return 0;
}

void print_times(void)
{
    static int count;

    count++;
    printf("%2d\n", count);
}
