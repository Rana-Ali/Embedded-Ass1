
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct BirthDate {
    int Day;
    int Month;
    int Year;
};
struct student
{
    char name [100];
    int ID;
    struct BirthDate birthDate;
    int score;
};
int main()
{
    printf("Welcome to our project");
    struct student S1;
    struct BirthDate BD;
    printf("Please enter your name");
    scanf("%s",&S1.name);
    printf("Please enter your ID");
    scanf("%d",&S1.ID);
    printf("Please enter your Birthdate in the form of day month year ");
    scanf("%d %d %d",&S1.birthDate.Day,&S1.birthDate.Month,&S1.birthDate.Year);
    printf("please enter your last year score");
    scanf("%d",&S1.score);
    printf("Thank you");

    return 0;
}
