#include <stdio.h>

int main(void)
{
    int word, i = 0;
    char ** input;
    char * temp = (char *) malloc(500 * sizeof(char));

    puts("How many words you wish to enter? ");
    scanf("%d", &word);
    input = (char **) malloc(word * sizeof(char));
    for(int g = 0; g < word; g++)
        input[g] = (char *) malloc( 50 * sizeof(char));
    printf("Enter %d words now:\n", word);
    fflush(stdin);
    gets(temp);
    for(int j = 0; j < 5; j++)
    {
        int o = 0;
        do
        {
            input[j][o] =  temp[o];
            o++;
        }while(temp[o-1] != '\0' && temp[o-1] != ' ');
        temp[o-1] = '\0';
    }
    for(int z = 0; z < 5; z++)
        puts(input[z]);

    free(temp);
    free(input);
    return 0;
}
