#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAXNL 20
#define MAXSNL 3
#define EMPTY 0
#define RESERVED 1
#define MAXFL 4
#define MAXSEAT 12
typedef char FLAG;
struct seat
{
    char first_n[MAXNL];
    char last_n[MAXNL];
    char seat_num[MAXSNL];
    FLAG isAssigned;
};
struct flight
{
    unsigned int code_name;
    struct seat seats[MAXSEAT];
};
void show_empty(struct flight *);
void show_list(struct flight *);
void show_alpha(struct flight *);
void add_cust(struct flight *);
void del_seat(struct flight *);
void menu(void);
char *s_gets(char *, const int);

int main(void)
{
    FILE *fp;
    int i, j;
    struct flight flights[MAXFL];
    struct flight temp;
    char seat_no[3];
    unsigned int codename[4] = {102, 311, 444, 519};
    FLAG seat_num, key;
    FLAG flag = 1;
    char input;

    for(i = 0; i < MAXFL; i++)
    {
        flights[i].code_name = codename[i];
        key = 'L';
        seat_num = 1;
        for(j = 0; j < MAXSEAT; j++, seat_num++)
        {
            if(seat_num == 7)
            {
                seat_num = 1;
                key = 'R';
            }
            flights[i].seats[j].isAssigned = EMPTY;
            flights[i].seats[j].first_n[0] = flights[i].seats[j].last_n[0] = '\0';
            sprintf(seat_no, "%c%d", key, seat_num);
            strcpy(flights[i].seats[j].seat_num, seat_no);
        }
    }
    if((fp = fopen("seats.data", "rb")) == NULL)
    {
        if((fp = fopen("seats.data", "wb")) == NULL)
        {
            printf("Failed to open file \"seats.data\"\n");
            exit(EXIT_FAILURE);
        }
        else
        {
            fwrite(&flights, sizeof(struct flight), 4, fp);
        }
            fclose(fp);
    }
    else
    {
        if(fread(&flights, sizeof(struct flight), 4, fp) == 0)
        {
            puts("reading failed.");
        }
    }
    fclose(fp);
    while(flag)
    {
        menu();
        input = getchar();
        while(getchar() != '\n')
            continue;
        switch(input)
        {
        case 'a':
            show_empty(flights);
            break;
        case 'b':
            show_list(flights);
            break;
        case 'c':
            show_alpha(flights);
            break;
        case 'd':
            add_cust(flights);
            break;
        case 'e':
            del_seat(flights);
            break;
        case 'f':
            flag = 0;
            break;
        }
    }
    if((fp = fopen("seats.data", "wb")) == NULL)
    {
        puts("Modify file failed.");
        exit(EXIT_FAILURE);
    }
    fwrite(&flights, sizeof(struct flight), 4, fp);
    fclose(fp);

    return 0;
}

void menu(void)
{
    puts("To choose a function, enter its letter label:\na) Show number of empty seats");
    puts("b) Show list of empty seats\nc) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment\ne) Delete a seat assignment");
    puts("f) Quit");
}

void show_empty(struct flight * flights)
{
    unsigned int seat_no = 0;
    for(int i = 0; i < MAXFL; i++)
    {
        for(int j = 0; j < MAXSEAT; j++)
            if(flights[i].seats[j].isAssigned == EMPTY)
                seat_no++;
        printf("The total number of flight %u empty seats is %u.\n\n", flights[i].code_name, seat_no);
        seat_no = 0;
    }
}

void show_list(struct flight * flights)
{
    for(int i = 0; i < MAXFL; i++)
    {
        printf("The empty seats of flight %u:\n", flights[i].code_name);
        for(int j = 0; j < 6; j++)
            printf("%s\t%s\n", flights[i].seats[j].isAssigned == EMPTY ? flights[i].seats[j].seat_num : "   ",
                               flights[i].seats[j+6].isAssigned == EMPTY ? flights[i].seats[j+6].seat_num : " ");
    }
    putchar('\n');
}

void show_alpha(struct flight * flights)
{
    int i, j, k , gap;
    struct seat * key;
    struct seat *spt[MAXSEAT];
    for(i = 0; i < MAXFL; i++)
    {
        for(j = 0; j < MAXSEAT; j++)
            spt[j] = &flights[i].seats[j];
        gap = 1;
        while( gap < MAXSEAT / 3) gap = gap * 3 + 1;
        while(gap >= 1)
        {
            for(j = gap; j < MAXSEAT; j++)
            {
                key = spt[j];
                k = j - gap;
                while(k >= 0 && strcmp(key->first_n, spt[k]->first_n) < 0)
                {
                    spt[k+gap] = spt[k];
                    k -= gap;
                }
                spt[k+gap] = key;

            }
            gap /= 3;
        }
        printf("passenger list of flight %u : \n", flights[i].code_name);
        for(j = 0; j < MAXSEAT; j++)
            printf("%s %s as seat number %s.\n", spt[j]->first_n, spt[j]->last_n, (*spt[j]).seat_num);
    }
}

void add_cust(struct flight * flights)
{
    int i, pointer;
    int size = sizeof(struct flight) + (sizeof(struct seat) * MAXSEAT);
    FLAG input;
    struct seat temp;
    struct flight tempflight;

    puts("Which flight?");
    printf("a) flight %u\nb) flight %u\nc) flight %u\nd) flight %u\n", flights[0].code_name, flights[1].code_name, flights[2].code_name, flights[3].code_name);
    if((input = getchar()) == '\n')
        return;
    while(getchar() != '\n')
        continue;
    switch(input)
    {
    case 'a':
        input = 0;
        break;
    case 'b':
        input = 1;
        break;
    case 'c':
        input = 2;
        break;
    case 'd':
        input = 3;
        break;
    }
    puts("First name:");
    s_gets(temp.first_n, MAXNL);
    puts("Last name:");
    s_gets(temp.last_n, MAXNL);
    puts("Left side seat or right side?");
    while(1)
    {
        if((i = toupper(getchar())) == 'L')
            pointer = -1;
        else if(i == 'R')
            pointer = 5;
        else
        {
            puts("enter \"l\" or \"r\"");
            continue;
        }
        temp.seat_num[0] = i;
        while(getchar() != '\n')
            continue;
        puts("seat number?");
        scanf("%hd", &i);
        if(0 < i && i < 7)
        {
            pointer += i;
            temp.seat_num[1] = '0' + i;
            temp.seat_num[2] = '\0';
            if(flights[input].seats[pointer].isAssigned == RESERVED)
                puts("The seat has been reserved. Please select another seat.");
            else
            {
                temp.isAssigned = RESERVED;
                flights[input].seats[pointer] = temp;
                break;
            }
        }
        else
        {
            puts("Out of boundary. (1>6)");
        }
    }
    fflush(stdin);
}

void del_seat(struct flight * flights)
{
    char seat[3];
    int i;
    FLAG pointer;
    FLAG flag = 1;
    while(flag)
    {
        puts("Which flight?");
        printf("a) %u\nb) %u\nc) %u\nd) %u\n", flights[0].code_name, flights[1].code_name, flights[2].code_name, flights[3].code_name);
        while(flag)
        {
            if((i = getchar()) == '\n')
                return;
            if('a' > i || i > 'd')
            {
                while(getchar() != '\n')
                    continue;
                puts("Out of bound");
            }
            else
                break;
        }
        i -= 'a';
        puts("Which seat?");
        scanf("%s", seat);
        seat[0] = toupper(seat[0]);
        if(seat[0] == 'L')
        {
            pointer = -1;
            flag = 0;
        }
        else if(seat[0] == 'R')
        {
            pointer = 5;
            flag = 0;
        }
        else
        {
            puts("Seat unrecognized.");
            continue;
        }
        if('0' < seat[1] && seat[1] < '7')
            pointer += (seat[1] - '0');
        else
        {
            puts("Seat unrecognized.");
            continue;
        }
        if(flights[i].seats[pointer].isAssigned == RESERVED)
        {
            flights[i].seats[pointer].last_n[0] = flights[i].seats[pointer].first_n[0] = '\0';
            flights[i].seats[pointer].isAssigned = EMPTY;
            flag = 0;
        }
        else
            puts("The seat is empty");
    }
}

char *s_gets(char *arr, const int SIZE)
{
    char *ret_val;
    if(ret_val = fgets(arr, SIZE, stdin))
    {
        if((arr = strchr(arr, '\n')) != NULL)
            *arr = '\0';
        else
            while(getchar() != '\n')
                continue;
    }

    return ret_val;
}
