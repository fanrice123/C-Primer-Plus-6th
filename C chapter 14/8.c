#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef char FLAG;
struct seat
{
    char seat_num[3];
    FLAG isAssigned;
    char first_n[20], last_n[20];
};
struct status
{
    FLAG isUsed;
    char seat_num[3];
};

/*static struct status statuses[] = { {0, "L1"}, {0, "L2"}, {0, "L3"}, {0, "L4"}, {0, "L5"}, {0, "L6"},
                                    {0, "R1"}, {0, "R2"}, {0, "R3"}, {0, "R4"}, {0, "R5"}, {0, "R6"}};
*/
void menu(void);
void show_empty(struct seat *);
void show_list(struct seat *);
void show_alpha(struct seat *);
void add_cust(struct seat *);
char *s_gets(char *,const int);
void del_seat(struct seat *);

int main(void)
{
    struct seat seats[12];
    struct seat temp;
    FLAG select;
    FILE * fp;
    int pointer;
    int i;
    char seat_no = 1, key = 'L';

    for(i = 0; i < 12; i++, seat_no++)
    {
        seats[i].isAssigned = 0;
        seats[i].first_n[0] = '\0';
        seats[i].last_n[0] = '\0';
        if(i == 6)
        {
            key = 'R';
            seat_no = 1;
        }
        sprintf(seats[i].seat_num, "%c%d", key, seat_no);
    }
    if((fp = fopen("seats.bin", "rb")) == NULL)
    {
        fclose(fp);
        if((fp = fopen("seats.bin", "wb")) == NULL)
        {
            puts("Fail to create \"seats.bin\" file.");
            exit(EXIT_FAILURE);
        }
        fclose(fp);
    }
    else
    {
        while(fread(&temp, sizeof(struct seat), 1, fp) == 1)
        {
    /*        if(seats[i].seat_num[0] == 'L')
                pointer = atoi(&seats[i].seat_num[1]) - 1;
            else
                pointer = 5 + atoi(&seats[i].seat_num[1]);
            statuses[pointer].isUsed = 1;
            i++;
    */
            if(temp.seat_num[0] == 'L')
                pointer = atoi(&temp.seat_num[1]) - 1;
            else
                pointer = 5 + atoi(&temp.seat_num[1]);
            seats[pointer] = temp;
        }
        /*while(i < 12)
        {
            if(seats[i].isAssigned = 0)
            for(int j = 0; j < 12; j++)
            {
                if(statuses[j].isUsed == 0)
                {
                    strcpy(seats[i].seat_num, statuses[j].seat_num);
                    break;
                }
            }
            i++;
        } */
    }
    menu();
    while(select = getchar())
    {
        fflush(stdin);
        switch(select)
        {
        case 'a':
            show_empty(seats);
            break;
        case 'b':
            show_list(seats);
            break;
        case 'c':
            show_alpha(seats);
            break;
        case 'd':
            add_cust(seats);
            break;
        case 'e':
            del_seat(seats);
            break;
        case 'f':
            return 0;
        }
        menu();
    }
}

void menu(void)
{
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment\nf) Quit");
}

void show_empty(struct seat * seats)
{
    int total = 0;
    int e;
    for(int i = 0; i < 12; i++)
        if(seats[i].isAssigned != 1)
            total++;
    printf("The number of empty seats is %d.\n\n", total);
    for(int i = 0; i < 12; i++)
        printf("no %d %s\n", i, seats[i].seat_num);
}

void show_list(struct seat * seats)
{
    int i = 0, c1 = 0, c2 = 1;
    while(i < 6)
    {
        printf("%s\t%s\n", seats[i].seat_num, seats[i + 6].seat_num);
        i++;
    }
}

void show_alpha(struct seat * seats)
{
    struct seat * key;
    struct seat *list[12];
    int i, j;
    int gap = 1;
    for(i = 0; i < 12; i++)
        list[i] = &seats[i];
    while(gap < 12/3) gap = gap * 3 + 1;
    while(gap >= 1)
    {
        for(i = gap; i < 12; i++)
        {
            key = list[i];
            j = i - gap;
            while(j >= 0)
            {
                if(strcmp(key->first_n, list[j]->first_n) < 0)
                    list[j + gap] = list[j];
                else
                    break;
                j -= gap;
            }
            list[j + gap] = key;
        }
        gap /= 3;
    }
    for(i = 0; i < 12; i++)
        printf("%s %s at seat no %s.\n", list[i]->first_n, list[i]->last_n, list[i]->seat_num);
}

void add_cust(struct seat * seats)
{
    struct seat temp;
    int pointer;
    FILE *fp;
    int flag = 1;
    if((fp = fopen("seats.bin", "ab")) == NULL)
    {
        puts("Failed to open file.");
        exit(EXIT_FAILURE);
    }
    puts("Please enter customer's first name : ");
    puts("Press [enter] to cancel.");
    if(s_gets(temp.first_n, 20) != NULL && temp.first_n[0] != '\0')
    {
        puts("Enter customer's last name : ");
        s_gets(temp.last_n, 20);
        while(flag)
        {
            puts("Enter the side of seat. \"Left or Right\"");
            s_gets(temp.seat_num, 2);
            temp.seat_num[0] = toupper(temp.seat_num[0]);
            puts("Enter the seat number.");
            s_gets(&temp.seat_num[1], 2);
            if(temp.seat_num[0] == 'L')
                pointer = atoi(&temp.seat_num[1]) - 1;
            else
                pointer = 5 + atoi(&temp.seat_num[1]);
            if(seats[pointer].isAssigned != 1)
            {
                seats[pointer] = temp;
                seats[pointer].isAssigned = 1;
                flag = 0;
            }
            else
                puts("please choose another seat. The seat has been selected.");
        }
        fwrite(&temp, sizeof(struct seat), 1, fp);seats[pointer].first_n[0] = '\0';
    }
    fclose(fp);
    return;
}

char *s_gets(char * arr, const int SIZE)
{
    char *ret_val;
    if(ret_val = fgets(arr, SIZE, stdin))
    {
        if(arr = strchr(arr, '\n'))
            *arr = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;
}

void del_seat(struct seat * seats)
{
    char seat_num[3];
    char flag = 0;
    struct seat temp;
    FILE * fp, *replacement;
    int pointer;
    if((fp = fopen("seats.bin", "rb")) == NULL)
    {
        printf("Failed to open file.\n");
        exit(EXIT_FAILURE);
    }
    if((replacement = fopen("temp.bin", "wb")) == NULL)
    {
        puts("Failed to create temporary file.");
        exit(EXIT_FAILURE);
    }
    while(flag == 0)
    {
        puts("Enter the seat number that is expected to be delete.");
        puts("Press [enter] to cancel.");
        s_gets(seat_num, 3);
        if(seat_num[0] == '\0')
            break;
        seat_num[0] = toupper(seat_num[0]);
        while(fread(&temp, sizeof(struct seat), 1, fp) == 1)
        {
            if(strcmp(temp.seat_num, seat_num) == 0)
            {
                flag = 1;
                if(temp.seat_num[0] == 'L')
                    pointer = atoi(&temp.seat_num[1]) - 1;
                else
                    pointer = 5 + atoi(&temp.seat_num[1]);
                seats[pointer].first_n[0] = '\0';
                seats[pointer].last_n[0] = '\0';
                seats[pointer].isAssigned = 0;
                continue;
            }
            else
                fwrite(&temp,sizeof(struct seat), 1, replacement);
        }
        if(flag != 1)
            printf("seat cannot be found. Please try it again.\n");
    }
    fclose(fp);
    fclose(replacement);
    remove("seats.bin");
    rename("temp.bin", "seats.bin");
}
