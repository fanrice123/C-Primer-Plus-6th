#include <stdio.h>
#include <math.h>
typedef struct
{
    double mag;
    double degree;
} polar;
typedef struct
{
    double x;
    double y;
} rec;
rec *fun(polar *);

int main(void)
{
    polar obj;
    rec * ans;
    double mag, deg;
    puts("Magnitude :");
    while(scanf("%lf", &obj.mag) == 1)
    {
        puts("Angle(in degree) :");
        scanf("%lf", &obj.degree);
        ans = fun(&obj);
        printf("X comp is %f and Y comp is %f\n", ans->x, ans->y);
    }

    return 0;
}

rec *fun(polar * obj)
{
    static rec temp;
    temp.x = cos(obj->degree * acos(-1) / 180) * obj->mag;
    temp.y = obj->mag * sin(obj->degree * acos(-1) / 180);
    printf("%f\n", temp.y);

    return &temp;
}
