#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 300

void pick(int (*)[], int, int);

int main(void)
{
    int (*arr)[2] = (int (*)[2]) calloc(SIZE * 2, sizeof(int));

    srand((double)time(0));
    for(int i = 0; i < SIZE; i++)
        arr[i][0] = rand();
    pick(arr, SIZE, SIZE);
}

void pick(int (*arr)[2], const int n, int times)
{
    int i = 0;
    int p;
    int count = 1;
    while(i < times)
    {
        p = rand() % n;
        if(arr[p][1])
            continue;
        arr[p][1] = 1;
        printf("%7d ", arr[p][0]);
        i++;
        if(count % 8 == 0)
            putchar('\n');
        count++;
    }
    printf("\nDone.\n");
}
