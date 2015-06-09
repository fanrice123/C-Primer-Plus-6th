#include <stdio.h>
#include <time.h>
long long unsigned delay(double);
int main(void)
{
    printf("%d\n", delay(getchar() - '0'));

    return 0;
}

long long unsigned delay(double timelong)
{
    clock_t begin = clock();
    long long unsigned i;
    for(i = 0; ((double)(clock() - begin) / CLOCKS_PER_SEC) < timelong;)
        i++;

    return i;
}
