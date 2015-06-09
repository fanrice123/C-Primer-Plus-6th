#include <stdio.h>
#define CSIZE 4

struct name
{
    char first[20], last[20];
};

struct student
{
    struct name Name;
    float grade[3];
    double average;
};
void enter_score(struct student *);
void get_average(struct student *);
void print_info(struct student *);
void print_class_avg(struct student *);
int main(void)
{
    struct student students[CSIZE] = { {{"F1", "L1"},{0, 0, 0},0},
                                        {{"F2", "L2"},{0, 0, 0},0},
                                        {{"F3", "L3"},{0, 0, 0},0},
                                        {{"F4", "L4"},{0, 0, 0},0}};
    for(int i = 0; i < CSIZE; i++)
    {
        enter_score(&students[i]);
        get_average(&students[i]);
    }
    print_info(students);
    print_class_avg(students);

    return 0;
}

void enter_score(struct student * students)
{
    printf("Enter the three scores of student %s %s : ", students->Name.first, students->Name.last);
    scanf("%f%f%f", &students->grade[0], &students->grade[1], &students->grade[2]);
}

void get_average(struct student * studentpt)
{
    studentpt->average = (studentpt->grade[0] + studentpt->grade[1] + (*studentpt).grade[2]) / 3;
}

void print_info(struct student *studentpt)
{
    for(int i = 0; i < CSIZE; i++)
    {
        printf("%s %s, grade 1 : %f, grade 2 : %f, grade 3 : %f, average score : %f.\n", (studentpt+i)->Name.first, (studentpt+i)->Name.last, (studentpt+i)->grade[0], (studentpt+i)->grade[1], studentpt[i].grade[2], (studentpt+i)->average);
    }
}

void print_class_avg(struct student *studentpt)
{
    printf("Average score of the class is %f.\n", (studentpt->average + studentpt[1].average + studentpt[2].average + studentpt[3].average) / 4);
}
