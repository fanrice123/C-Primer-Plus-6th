#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
    FILE *fp;
    char words[MAX], buf[55], amount[10];
    char *pt = buf;
    int count = 0;

    if((fp = fopen("wordy", "a+")) == NULL)
    {
        printf("Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(buf, 55, fp))
    {
        continue;
    }
    while(*pt != '\t')
        pt++;
    for(int i = 0; i < 10 && *pt != '\n'; i++, pt++)
        amount[i] = *pt;
    count = atoi(amount);
    fseek(fp, 0L, SEEK_END);
    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
        fprintf(fp, "%s\t%d\n", words, ++count);
    puts("File contents:");
    rewind(fp);
    while(fgets(words, 51, fp))
        puts(words);
    puts("Done.");
    fclose(fp);

    return 0;
}
