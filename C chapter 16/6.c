//801 785
#include <stdio.h>
#include <stdlib.h>
#define NUM 40

typedef struct{double v;} arr;
void fillstruct(arr [], int);
void showstruct(const arr [], int);
int mycomp(const void *, const void *);

int main(void)
{
    arr vals[NUM];
    fillstruct(vals, NUM);
    puts("Random list:");
    showstruct(vals, NUM);
    qsort(vals, NUM, sizeof(arr), mycomp);
    puts("\nSorted list:");
    showstruct(vals, NUM);
    return 0;
}

void fillstruct(arr pt[], int n)
{
    int index;

    for(index = 0; index < n; index++)
        pt[index].v = (double)rand()/((double) rand() + 0.1);
}

void showstruct(const arr pt[], int n)
{
    int index;

    for(index = 0; index < n; index++)
    {
        printf("%9.4f ", pt[index].v);
        if(index % 6 == 5)
            putchar('\n');
    }
    if(index % 6 != 0)
        putchar('\n');
}

int mycomp(const void * p1, const void * p2)
{
    const arr * a1 = (const arr *) p1;
    const arr * a2 = (const arr *) p2;

    if(a1->v < a2->v)
        return -1;
    else if(a1->v == a2->v)
        return 0;
    else
        return 1;
}
