#include <stdio.h>

struct template
{
    unsigned long int security_num;
    struct
    {
        char first_n[20];
        char middle_n[20], last_n[20];
    };
};

void print(struct template, const int);
int main(void)
{
    struct template member[5] = {[0] = {302039823, {"Flossie", "Middle", "Dribble"}}};

    print(member[0], 0);

    return 0;
}

void print(struct template structure, const int index)
{
    printf("%s, %s %c%c -- %ul\n", structure.last_n, structure.first_n, structure.middle_n[0], (*(&structure)).middle_n[0] == '\0' ? '\0' : '.', structure.security_num);
}
