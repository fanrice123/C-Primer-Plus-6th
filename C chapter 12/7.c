#include <stdio.h>
#include <stdlib.h>
void roll(int, int, int);

int main(void)
{
    int set, side, dice;
    srand('y');
    printf("Enter the number of sets; enter q to stop: ");
    while(scanf("%d", &set) == 1)
    {
        if(set < 0)
            printf("it must has at least a set of dice.\n");
        else
        {
            printf("How many sides and how many dice? ");
            if(scanf("%d%d", &side, &dice) == 2)
                roll(set, side, dice);
        }
        printf("Enter the number of sets; enter q to stop: ");
    }
    puts("Bye.");

    return 0;
}

void roll(int set, int side, int dice)
{
    int count;
    for(int i = 0; i < set; i++)
    {
        count = 0;
        for(int d = 0; d < dice; d++)
        {
            count += (rand() % side) + 1;
        }
        printf("%d ", count);
    }
    putchar('\n');
}
