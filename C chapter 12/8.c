#include <stdio.h>
int * make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
    int * pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while(scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value; ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if (pa)
        {
            show_array(pa, size);
            free(pa);
        }
        fputs("Enter the number of elements ( <1 to quit): ", stdout);
    }
    puts("Done.");

    return 0;
}

int * make_array(int elem, int val)
{
    int *arr = (int *)malloc(elem * sizeof(int));
    for(int i = 0; i < elem; i++)
        *(arr+i) = val;
    return arr;
}

void show_array(const int ar[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", ar[i-1]);
        if(i % 8 == 0)
            putchar('\n');
    }
    putchar('\n');
}
