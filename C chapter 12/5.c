#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, c, key;
    int *list1 = (int *) malloc(100 * sizeof(int));
    srand((unsigned int) time(0));
    for(i = 0; i < 100; i++)
        list1[i] = (rand()% 10) + 1;
    printf("Before Selection Sort.\n");
    for(i = 1; i <= 100; i++)
    {
        printf("%2d ", list1[i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    printf("After Selection Sort.\n");

    for(i = 0; i < 100; i++)
    {
        int temp;
        for(c = i + 1; c < 100; c++)
        {
            if(list1[c] > list1[i])
            {
                temp = list1[c];
                list1[c] = list1[i];
                list1[i] = temp;
            }
        }
    }
    for(i = 1; i <= 100; i++)
    {
        printf("%2d ", list1[i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    free(list1);

    int *list2 = (int *) malloc(100 * sizeof(int));
    for(i = 0; i < 100; i++)
        list2[i] = (rand()% 10) + 1;
    printf("Before Sorting.\n");
    for(i = 1; i <= 100; i++)
    {
        printf("%2d ", list2[i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    printf("After Insertion Sort.\n");
    for(i = 1; i < 100; i++)
    {
        key = list2[i];
        for(c = i-1; c >= 0; c--)
        {
            if(key > list2[c])
                list2[c+1] = list2[c];
            else
                break;
        }
        list2[c+1] = key;
    }
    for(i = 1; i <= 100; i++)
    {
        printf("%2d ", list2[i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    free(list2);

    int *list3 = (int *) malloc(100 * sizeof(int));
    int (* subarr1)[25] = (int (*)[25]) malloc(25 * 4 * sizeof(int));
    int count;
    for(i = 0; i < 100; i++)
        list3[i] = (rand()% 10) + 1;
    printf("Before Sorting.\n");

    count = 0;
    for(i = 0; i < 4; i++)
    {
        for(int j = 0 ; j < 25; j++)
        {
            subarr1[i][j] = list3[count];
            count++;
        }
    }
    for(i = 1; i <= 25; i++)
    {
        printf("%2d ", subarr1[0][i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    for(i = 1; i <= 25; i++)
    {
        printf("%2d ", subarr1[1][i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    for(i = 1; i <= 25; i++)
    {
        printf("%2d ", subarr1[2][i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    for(i = 1; i <= 25; i++)
    {
        printf("%2d ", subarr1[3][i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    printf("After Merge Sort.\n");

    for(i = 0; i < 25; i++)
    {
        int temp;
        for(c = i + 1; c < 25; c++)
        {
            if(subarr1[0][c] > subarr1[0][i])
            {
                temp = subarr1[0][c];
                subarr1[0][c] = subarr1[0][i];
                subarr1[0][i] = temp;
            }
        }
    }
    for(i = 1; i <= 25; i++)
    {
        printf("%2d ", subarr1[0][i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    for(i = 1; i < 25; i++)
    {
        key = subarr1[1][i];
        for(c = i-1; c >= 0; c--)
        {
            if(key > subarr1[1][c])
                subarr1[1][c+1] = subarr1[1][c];
            else
                break;
        }
        subarr1[1][c+1] = key;
    }
    for(i = 1; i <= 25; i++)
    {
        printf("%2d ", subarr1[1][i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    for(i = 1; i < 25; i++)
    {
        key = subarr1[2][i];
        for(c = i-1; c >= 0; c--)
        {
            if(key > subarr1[2][c])
                subarr1[2][c+1] = subarr1[2][c];
            else
                break;
        }
        subarr1[2][c+1] = key;
    }
    for(i = 1; i <= 25; i++)
    {
        printf("%2d ", subarr1[2][i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    for(i = 0; i < 25; i++)
    {
        int temp;
        for(c = i + 1; c < 25; c++)
        {
            if(subarr1[3][c] > subarr1[3][i])
            {
                temp = subarr1[3][c];
                subarr1[3][c] = subarr1[3][i];
                subarr1[3][i] = temp;
            }
        }
    }
    for(i = 1; i <= 25; i++)
    {
        printf("%2d ", subarr1[3][i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    i = 0;
    for(int x = 0, y = 0; i < 50; i++)
    {
        if((subarr1[0][x] > subarr1[1][y] && x < 25) || y == 25)
        {
            list3[i] = subarr1[0][x];
            x++;
        }
        else
        {
            list3[i] = subarr1[1][y];
            y++;
        }

    }
    putchar('\n');
    putchar('\n');
    for(i = 1; i <= 50; i++)
    {
        printf("%2d ", list3[i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    putchar('\n');
    putchar('\n');
    i = 50;
    for(int x = 0, y = 0; i < 100; i++)
    {
        if((subarr1[2][x] > subarr1[3][y] && x < 25) || y == 25)
        {
            list3[i] = subarr1[2][x];
            x++;
        }
        else
        {
            list3[i] = subarr1[3][y];
            y++;
        }

    }
    for(i = 51; i <= 100; i++)
    {
        printf("%2d ", list3[i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    putchar('\n');
    putchar('\n');
    putchar('\n');
    int list4[100];
    i = 0;
    for(int x = 0, y = 50; i < 100; i++)
    {
        if((list3[x] > list3[y] && x < 50) || y == 100)
        {
            list4[i] = list3[x];;
            x++;
        }
        else
        {
            list4[i] = list3[y];
            y++;
        }

    }

    for(i = 1; i <= 100; i++)
    {
        printf("%2d ", list4[i-1]);
        if(i % 10 == 0)
            putchar('\n');
    }
    free(list3);
    free(subarr1);

    return 0;
}
