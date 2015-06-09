#include <stdio.h>
#include <memory.h>

int main(void)
{
    double data1[100];
    double data2[300];
    memcpy(data1, data2, 100 * sizeof(double));
    double *temp = &data2[200];
    memcpy(data1, temp, 100 * sizeof(double));
}
