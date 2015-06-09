#include <stdio.h>
#define IDMASK 0xFF
#define SIZEMASK 0x7F00
#define SIZE 0x7F
#define ALIGNMASK 0x18000
#define ALIGN 0x3
#define BMASK 0x20000
#define IMASK 0x40000
#define UMASK 0x80000
#define ON 1
#define OFF 0
#define LEFT OFF
#define CENTER 0x1
#define RIGHT 2

void menu(unsigned long *);
void itob(unsigned long);
int execution(unsigned long *);
int main(void)
{
    unsigned long info;
    info = 1;
    info |= (12 << 8);
    info |= (1 << 15);
    info |= (OFF << 17);
    info |= (OFF << 18);
    info |= (OFF << 19);
    menu(&info);
}

void menu(unsigned long *controller)
{
    puts(" ID SIZE ALIGNMENT   B   I   U");
    printf("%2d %3d\t   %s    %s %s %s\n\n", *controller & IDMASK,
                                            (*controller >> 8) & SIZE,
                                            ((*controller >> 15) & ALIGN) == LEFT ? "left" : ((*controller >> 15) & ALIGN) == CENTER ? "center" : "right",
                                            ((*controller >> 17) & ON) == ON ? "on" : "off",
                                            ((*controller >> 18) & ON) == ON ? "on" : "off",
                                            ((*controller >> 19) & ON) == ON ? "on" : "off");
    puts("f)change font\ts)change size\ta)change alignment\nb)toggle bold\ti)toggle italic\tu)toggle underline");
    puts("q)quit");
    itob(*controller);
    while(execution(controller))
    {
        puts(" ID SIZE ALIGNMENT   B   I   U");
        printf("%2d %3d\t   %s    %s %s %s\n\n", *controller & IDMASK,
                                            (*controller >> 8) & SIZE,
                                            ((*controller >> 15) & ALIGN) == LEFT ? "left" : ((*controller >> 15) & ALIGN) == CENTER ? "center" : "right",
                                            ((*controller >> 17) & ON) == ON ? "on" : "off",
                                            ((*controller >> 18) & ON) == ON ? "on" : "off",
                                            ((*controller >> 19) & ON) == ON ? "on" : "off");
        puts("f)change font\ts)change size\ta)change alignment\nb)toggle bold\ti)toggle italic\tu)toggle underline");
        puts("q)quit");
        itob(*controller);
    }
}

int execution(unsigned long * controller)
{
    int flag = 1;
    char input;
    unsigned long i;
    unsigned long x;

    scanf("%c", &input);
    getchar();
    switch(input)
    {
    case 's':
        fputs("Enter font size (0-127): ", stdout);
        scanf("%lu", &i);
        fflush(stdin);
        *controller &= (~SIZEMASK);
        *controller |= (i << 8) ;
        break;
    case 'a':
        puts("Select alignment:");
        printf("l)left\tc)center\tr)right\n");
        scanf("%c", &input);
        fflush(stdin);
        if(input == 'l')
            x = LEFT;
        else if(input == 'c')
            x = CENTER;
        else if(input == 'r')
            x = RIGHT;
        else
        {
            puts("Invalid input.");
            return flag;
        }
        printf("%d\n", x);
        *controller &= ((~ALIGN) << 15);
        *controller |= (x << 15);
        break;
    case 'i':
        *controller ^= (ON << 18);
        break;
    case 'b':
        *controller ^= (ON << 17);
        break;
    case 'u':
        *controller ^= (ON << 19);
        break;
    case 'q':
        flag = 0;
        break;
    }
    return flag;
}
 void itob(unsigned long t)
 {
     char arr[33];
     for(int i = 31; i >= 0; i--, t >>= 1)
        arr[i] = (t & 1) + '0';
     arr[32] = '\0';
     puts(arr);
 }
int gcd(int a, int b)
{
    int temp;
    if(a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    return b == 0 ? 1 : gcd(b, a % b);
}
