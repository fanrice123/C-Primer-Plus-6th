#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "s.h"

int main(void)
{
    struct player temp;
    FILE *fp;
    int flag = 1;
    if((fp = fopen("player_details.dat", "a+b")) == NULL)
    {
        printf("open file failed.\n");
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    while(flag)
    {
        fputs("player's number : ", stdout);
        scanf("%d", &temp.number);
        fputs("player's first name : ", stdout);
        scanf("%s", temp.first_n);
        fputs("player's last name : ", stdout);
        scanf("%s", temp.last_n);
        fputs("player's official times at bat : ", stdout);
        scanf("%d", &temp.tab);
        fputs("player's hits number : ", stdout);
        scanf("%d", &temp.noh);
        fputs("player's walk : ", stdout);
        scanf("%d", &temp.walk);
        fputs("player's RBIs : ", stdout);
        scanf("%d", &temp.rbi);
        while(getchar() != '\n')
            continue;
        fwrite(&temp, sizeof(struct player), 1, fp);
        puts("Continue ? 'y' = yes; 'n' = no");
        if(tolower(getchar()) == 'y')
            flag = 1;
        else
            flag = 0;
    }
    rewind(fp);
    puts("Here are the content in the file :");
    while(fread(&temp, sizeof(struct player), 1, fp) == 1)
    {
        printf("player's number : %d\nplayer's first name : %s\n", temp.number, temp.first_n);
        printf("player's last name : %s\nplayer's official time at bat : %d\n", temp.last_n, temp.tab);
        printf("player's hits number : %d\nplayer's walk : %d", temp.noh, temp.walk);
        printf("\nplayer's RBIs : %d\n", temp.rbi);
    }

    fclose(fp);

    return 0;
}
