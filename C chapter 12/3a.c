#include <stdio.h>
#include "3b.h"
int main(void)
{
    int mode;
    double distance, fuel_consumed;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        get_info(&distance, &fuel_consumed, mode);
        show_info(distance, fuel_consumed, mode);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");

    return 0;
}
