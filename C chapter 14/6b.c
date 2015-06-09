#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "s.h"

int main(void)
{
    struct player players[19], temp;
    FILE *fp;
    int i;
    if((fp = fopen("player_details.dat", "rb")) == NULL)
    {
        printf("Open file failed.\n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 19; i++)
        players[i].tab = players[i].noh = players[i].walk = players[i].rbi = players[i].bavg = 0;
    while(fread(&temp, sizeof(struct player), 1, fp))
    {
        players[i = temp.number].number = temp.number;
        strcpy(players[i].first_n, temp.first_n);
        strcpy(players[i].last_n, temp.last_n);
        players[i].tab += temp.tab;
        players[i].noh += temp.noh;
        players[i].walk += temp.walk;
        players[i].rbi += temp.rbi;
    }

    for(int i = 0; i < 19; i++)
    {
        printf("player's number : %d\nplayer's first name : %s\n", players[i].number, players[i].first_n);
        printf("player's last name : %s\nplayer's official time at bat : %d\n", players[i].last_n, players[i].tab);
        printf("player's hits number : %d\nplayer's walk : %d", players[i].noh, players[i].walk);
        printf("\nplayer's RBIs : %d\n", temp.rbi);
    }

    fclose(fp);
    return 0;
}
