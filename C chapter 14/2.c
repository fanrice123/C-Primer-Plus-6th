#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *s_gets(char *, const int);
union month
{
    int num;
    char name[10];
};
struct date
{
    int day, year;
    union month mon;
};

int main(void)
{
    char *month_n[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char input[10];
    int day_of_year, flag, total = 0;
    struct date data;
    fputs("Please enter the day : ", stdout);
    scanf("%d", &data.day);
    while(getchar() != '\n')
        continue;
    fputs("Please enter the month : ", stdout);
    s_gets(input, 10);
    if(isdigit(input[0]))
    {
        data.mon.num = atoi(input);
        flag = 1;
    }
    else
    {
        strcpy(data.mon.name, input);
        data.mon.name[0] = toupper(data.mon.name[0]);
        flag = 0;
    }
    fputs("Please enter the year : ", stdout);
    scanf("%d", &data.year);
    day_of_year = data.year % 4 == 0?
        data.year % 100 == 0?
            data.year % 400 == 0? 366 : 365
            : 366
        : 365;
    if(flag)
    {
        for(int i = 1; i < data.mon.num; i++)
        {
            total += i < 8 ? i % 2 == 1? 31 : i == 2 ? day_of_year == 366 ? 29 : 28 : 30 : i % 2 == 0 ? 31 : 30;
        }
        total += data.day;
    }
    else
    {
        for(int i = 0; i < 12; i++)
        {
            if(strncmp(data.mon.name, month_n[i], 3) == 0)
            {
                for(int j = 0; j < i; j++)
                {
                    total += j < 7 ? j % 2 == 0? 31 : j == 1 ? day_of_year == 366 ? 29 : 28 : 30 : j % 2 == 1 ? 31 : 30;
                }
                total += data.day;
                break;
            }
        }
    }
    printf("The total number of days in year %d through the given date is %d.\n", data.year, total);

    return 0;
}

char *s_gets(char *arr, const int SIZE)
{
    char *ret_val;
    if((ret_val = fgets(arr, SIZE, stdin)) == NULL)
        return NULL;
    if((arr = strchr(arr, '\n')) != NULL)
        *arr = '\0';
    else
        while(getchar() != '\n')
            continue;

    return ret_val;
}

