#include <stdio.h>
void get_info(void);
void show_info(void);
void set_mode(int);
static int mode;
static double distance, fuel_consumed;

void set_mode(int x)
{
    mode = x;
}
void get_info(void)
{
    if(mode)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel_consumed);
    }
    else
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf",&fuel_consumed);
        printf("%f fuel %f distance %f distance / 100.\n", fuel_consumed, distance, distance/100);
    }
}

void show_info(void)
{
    if(mode)
        printf("Fuel consumption is %.2f miles per gallon.\n", distance/ fuel_consumed);
    else
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel_consumed / ( distance / 100 ) );
}
