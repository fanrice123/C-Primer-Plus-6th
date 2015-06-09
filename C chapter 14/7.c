#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
char *s_gets(char * st, int n);
void addbook(struct book *, int *, int *);
void delbook(struct book *);
void modbook(struct book *);
int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    char input, flag = 1;
    int filecount;
    FILE * pbooks;
    int size = sizeof(struct book);

    if((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);
    while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
    {
        if(count == 0)
            puts("Current contents of book.dat:");
        printf("%s by %s: $%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    filecount = count;
    if(count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
    }
    fclose(pbooks);
    while(flag)
    {
        puts("Enter 1 to add new book.\nEnter 2 to delete a book specified by book title.\nEnter 3 to modify a book ''''''''''''''''''''");
        if((input = getchar()) == '1')
            addbook(library, &filecount, &count);
        else if(input == '2')
            delbook(library);
        else if(input == '3')
            modbook(library);
        else
            flag = 0;
    }
    puts("Done.");

    return 0;
}

void addbook(struct book * library, int * filecount, int * count)
{
    fflush(stdin);
    FILE *fp;
    int index;
    int size = sizeof(struct book);
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    if((fp = fopen("book.dat", "a+b")) == NULL)
    {
        printf("open file failed.\n");
        exit(EXIT_FAILURE);
    }
    while(*count < MAXBKS && s_gets(library[*count].title, MAXTITL) != NULL && library[*count].title[0] != '\0')
    {
        puts("Now enter the author.");
        s_gets(library[*count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[(*count)++].value);
        while(getchar() != '\n')
            continue;
        if(*count < MAXBKS)
            puts("Enter the next title.");
    }
    if(*count > 0)
    {
        puts("Here is the list of your books:");
        for(index = 0; index < *count; index++)
        {
            printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
        }
        fwrite(&library[*filecount], size, *count - *filecount, fp);
    }
    else
        puts("No books? Too bad.\n");
    fclose(fp);
}

void delbook(struct book * library)
{
    fflush(stdin);
    FILE *fp, *replace;
    int flag = 0;
    char temp[MAXTITL];
    struct book record;
    struct book empty;
    puts("Please enter the book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while(s_gets(temp, MAXTITL) != NULL && temp[0] != '\0')
    {
        if((fp = fopen("book.dat", "rb")) == NULL)
        {
            puts("Failed to open file.");
            exit(EXIT_FAILURE);
        }
        if((replace = fopen("replace.tmp", "wb")) == NULL)
        {
            puts("Failed to create temp file.");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < MAXBKS; i++)
        {
            fread(&record, sizeof(struct book), 1, fp);
            if(strcmp(temp,library[i].title) == 0)
            {
                flag = 1;
                library[i] = empty;
                continue;
            }
            else
                fwrite(&record, sizeof(struct book), 1, replace);
        }
        if(flag != 1)
            printf("Title not found.\n");
        fclose(fp);
        fclose(replace);
        remove("book.dat");
        rename("replace.tmp", "book.dat");
        puts("Enter the next title.");
        puts("Press [enter] at the start o a line to stop.");
    }
}

void modbook(struct book * library)
{
    fflush(stdin);
    FILE * fp, * replace;
    char temp[MAXTITL];
    struct book replacement;
    struct book traverser;
    puts("Please enter the book titles for the modification.");
    puts("Press [enter] at the start of a line to stop.");
    while(s_gets(replacement.title, MAXTITL) != NULL && replacement.title[0] != '\0')
    {
        puts("Enter the author of the book.");
        s_gets(replacement.author, MAXAUTL);
        puts("Enter the value of the given book.");
        scanf("%f", &replacement.value);
        while(getchar() != '\n')
            continue;
        if((fp = fopen("book.dat", "rb")) == NULL)
        {
            printf("Failed to open file \"book.dat\".\n");
            exit(EXIT_FAILURE);
        }
        if((replace = fopen("temp.tmp", "wb")) == NULL)
        {
            puts("Failed to open file.");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < MAXBKS; i++)
        {
            if(fread(&traverser, sizeof(struct book), 1, fp) == 1)
                break;
            if(strcmp(replacement.title,library[i].title) == 0)
            {
                library[i] = replacement;
                fwrite(&replacement, sizeof(struct book), 1, replace);
            }
            else
            {
                fwrite(&traverser, sizeof(struct book), 1, replace);
            }
        }
        fclose(fp);
        fclose(replace);
        remove("book.dat");
        rename("temp.tmp", "book.dat");
        puts("Enter the next title.");
        puts("Press [enter] at the start o a line to stop.");
    }
}

char * s_gets(char * arr, const int SIZE)
{
    char * ret_val;
    if((ret_val = fgets(arr, SIZE, stdin)) != NULL)
    {
        if((arr = strchr(arr, '\n')) != NULL)
            *arr = '\0';
        else
            while(getchar() != '\n')
                continue;
    }
    return ret_val;

}
