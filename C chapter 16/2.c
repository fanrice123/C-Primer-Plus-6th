#include <stdio.h>
#define HARMONIC(X,Y) (1/((1/(X) + 1/(Y))/2))
#define HARM(X,Y) (2.0 * (X) * (Y)/ ((X) + (Y)))

int main(void)
{
    printf("%f\n%f\n", HARMONIC(49.0, 38.0 + 1.5), HARM(49.0, 39.5));

    return 0;
}
