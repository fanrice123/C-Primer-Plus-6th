#include <stdio.h>
void get_info(double *, double *, int);
void show_info(double, double, int);
void set_mode(int);

void get_info(double * distance, double * fuel_consumed, int mode)
{
    if(mode)
    {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", fuel_consumed);
    }
    else
    {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf",fuel_consumed);
    }
}

void show_info(double distance, double fuel_consumed, int mode)
{
    if(mode)
        printf("Fuel consumption is %.2f miles per gallon.\n", distance/ fuel_consumed);
    else
        printf("Fuel consumption is %.2f liters per 100 km.\n", fuel_consumed / ( distance / 100 ) );
}
