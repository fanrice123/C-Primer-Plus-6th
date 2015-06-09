#include <stdio.h>
#define ON 1
#define OFF 0
#define LEFT OFF
#define CENTER ON
#define RIGHT 2
#define MASK 127
#define AMUSK 3

struct  switcher
{
    unsigned int ID : 8;
    unsigned int fsize : 7;
    unsigned int align : 2;
    unsigned int B : 1;
    unsigned int I : 1;
    unsigned int U : 1;
};

void menu(struct switcher *);
int response(char, struct switcher *);

int main(void)
{
    struct switcher platform = {1, 12, LEFT, OFF, OFF, OFF};
    menu(&platform);

    return 0;
}

void menu(struct switcher * platform)
{
    char input;
    do
    {
        fflush(stdin);
        printf("\tID SIZE ALIGNMENT\tB\tI\tU\n");
        printf("\t%d%6d  %s\t\t%s\t%s\t%s\n", platform->ID, platform->fsize, platform->align == 2 ? "RIGHT" : platform->align == 1 ? "CENTER" : "LEFT", platform->B ? "ON" : "OFF", platform->I ? "ON" : "OFF", platform->U ? "ON" : "OFF");
        puts("\nf)change font\ts)change size\ta)change alignment\nb)toggle bold\ti)toggle italic\tu)toggle underline\nq)quit");
        input = getchar();
    }while(response(input, platform));


}

int response(char input, struct switcher * controller)
{
    fflush(stdin);
    unsigned res;
    char test;
    char ret_val = 1;
    switch(input)
    {
    case 's':
        printf("Enter font size (0-127): ");
        scanf("%u", &res);
        controller->fsize = res & MASK;
        break;
    case 'a':
        puts("Select alignment:");
        puts("l)left  c)center  r)right");
        scanf("%c", &test);
        switch(test)
        {
        case 'l':
            controller->align = LEFT;
            break;
        case 'r':
            controller->align = RIGHT;
            break;
        case 'c':
            controller->align = CENTER;
            break;
        }
        break;
    case 'q':
        ret_val = 0;
        break;
    case 'i':
        controller->I = ~controller->I;
        break;
    case 'b':
        controller->B = ~controller->B;
        break;
    case 'u':
        controller->U = ~controller->U;
        break;
    }

    return ret_val;
}
