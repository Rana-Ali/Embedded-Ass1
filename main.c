
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int i,n;
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
}*p;
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

void dynamicAllocate(){



    printf("Enter no. of students : ");
    scanf("%d",&n);
    p=(struct student*)calloc(n,n*sizeof(struct student));
    for(i=0;i<n;i++){
        printf("Enter Name : ");
        scanf("%s",&(p+i)->name);

        printf("Enter ID");
        scanf("%d",&(p+i)->ID);
        printf("Enter Birthdate in the form of day month year ");
        scanf("%d %d %d",&(p+i)->birthDate.Day,&(p+i)->birthDate.Month,&(p+i)->birthDate.Year);
        printf("Enter last year score");
        scanf("%d",&(p+i)->score);


}
}
void insertEnd(){
    n+=1;
    p=(struct student*)realloc(p,(n)*sizeof(struct student));
    printf("Enter name of student you want to insert in the end: ");
    scanf("%s",&(p+i)->name);

    printf("Enter ID");
    scanf("%d",&(p+i)->ID);

    printf("Enter Birthdate in the form of day month year ");
    scanf("%d %d %d",&(p+i)->birthDate.Day,&(p+i)->birthDate.Month,&(p+i)->birthDate.Year);

    printf("Enter last year score");
    scanf("%d",&(p+i)->score);
    i=n;
}
void insertBeginning(){
n+=1;
p=(struct student*)realloc(p,(n)*sizeof(struct student));
for(i=i;i>0;i--){
    for(int charIndex=0;charIndex<100;charIndex++){
            (p+i)->name[charIndex]=(p+i-1)->name[charIndex];
        }
    (p+i)->ID=(p+i-1)->ID;
    (p+i)->birthDate.Day = (p+i-1)->birthDate.Day;
    (p+i)->birthDate.Month = (p+i-1)->birthDate.Month;
    (p+i)->birthDate.Year=(p+i-1)->birthDate.Year;
}
printf("Enter Name of student you want to insert in the beginning: ");
scanf("%s",&(p)->name);
printf("Enter ID: ");
scanf("%d",&(p)->ID);

printf("\n Enter Birthdate in form of day month year \n");
scanf("%d %d %d",&(p)->birthDate.Day,&(p)->birthDate.Month,&(p)->birthDate.Year);
printf("\n Enter last year score \n");
scanf("%d",&(p)->score);
i=n;
}
void insertMiddle(){
    n+=1;
    p=(struct student*)realloc(p,(n)*sizeof(struct student));
    printf("Where do you want to insert the new student? Write index. ");
    int newIndex;
    scanf("%d",&newIndex);
    for(i=i;i>=newIndex+1;i--){
    for(int charIndex=0;charIndex<100;charIndex++){
            (p+i)->name[charIndex]=(p+i-1)->name[charIndex];
        }
    (p+i)->ID=(p+i-1)->ID;
    (p+i)->birthDate.Day = (p+i-1)->birthDate.Day;
    (p+i)->birthDate.Month = (p+i-1)->birthDate.Month;
    (p+i)->birthDate.Year=(p+i-1)->birthDate.Year;
}
printf("Enter Name: ");
scanf("%s",&(p+newIndex)->name);
printf("Enter ID: ");
scanf("%d",&(p+newIndex)->ID);

printf("\n Enter Birthdate in form of day month year \n");
scanf("%d %d %d",&(p+newIndex)->birthDate.Day,&(p+newIndex)->birthDate.Month,&(p+newIndex)->birthDate.Year);
printf("\n Enter last year score \n");
scanf("%d",&(p+newIndex)->score);
i=n;
}
