#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define TYPE char *

typedef int (*PTRF)(int);
typedef char hehe[5];
typedef char * TEST2;
int main(void)
{
    hehe haha = "Test";
    TYPE test1 = malloc(4 * sizeof(char));
    TEST2 ha[3] = {malloc(5 * sizeof(char)), malloc(5 * sizeof(char)), malloc(5 * sizeof(char))};
    for(int x = 0; x < 3; x++)
        strcpy(ha[x], "test");
    strcpy(test1, "hah");
    int (*ptr[4])(int);
    PTRF test;
    ptr[0] = islower;
    ptr[1] = isupper;
    ptr[2] = tolower;
    ptr[3] = toupper;
    test = ptr[0];
    int i = getchar();
    printf("%d %d %c %c %d\n%s\n", ptr[0](i), ptr[1](i), ptr[2](i), ptr[3](i), (*test)(i), test1);
    printf("%s %s %s\n%s", ha[0], ha[1], ha[2], haha);

    return 0;
}
