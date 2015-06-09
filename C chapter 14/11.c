#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 20

double *transform(double *, double *, int, double (*)(double));

int main(void)
{
    double (*farr[4])(double) = {sin, cos, tan, sqrt};
    int i, c;
    double source[SIZE], target[SIZE];
    double *arr;
    srand(time(0));
    for(i = 0; i < SIZE; i++)
        source[i] = rand();
    for(c = 0; c < 4; c++)
    {
        arr = transform(source, target, SIZE, farr[c]);
        for(i = 0; i < SIZE; i++)
            printf("%f %f\n", target[i], arr[i]);
        putchar('\n');
    }

    return 0;
}

double *transform(double * source, double * tar, const int LENGTH, double (*fpt)(double arg))
{
    for(int i = 0; i < LENGTH; i++)
        tar[i] = (*fpt)(source[i]);

    return tar;
}
