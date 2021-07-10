
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int i,n;
struct BirthDate
{
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

struct studentNode
{
    char name[100];
    int ID;
    struct BirthDate birthDate;
    int score;
    struct Node* next;
};


struct studentNode *head, *tail = NULL;


int main()

{



    printf("Size of struct = %d \n",calculateStructSize());
    printf("Size taken by a node in memory = %d \n", sizeNode());

    time_t begin4=time(NULL);

    append(3,9,1990,"ai",1,99);

    time_t end4=time(NULL);

    printf("Time taken to insert in end of linked list = %d seconds \n",end4-begin4);

    time_t begin5=time(NULL);

    push(3,5,6,"mumu",2,24);

    time_t end5=time(NULL);
    printf("Time taken to insert in beginning of linked list = %d seconds \n",end5-begin5);

    append(2,8,1998,"riri",2,20);

    time_t begin6=time(NULL);

    push_at(3,4,1950,"mimi",2,4,2);

    time_t end6=time(NULL);
    printf("Time taken to insert in middle of linked list = %d seconds \n",end6-begin6);
    printList(head);

    printf("Welcome to our project\n");


    dynamicAllocate();

    time_t begin = time(NULL);

    insertBeginning("ani",1,2,90,9,94);

    time_t end = time(NULL);

    printf("Time taken to insert in beginning of array = %d seconds \n", end-begin);

    time_t begin2 = time(NULL);

    insertMiddle("osa",2,3,5,20,95);

    time_t end2 = time(NULL);

    printf("Time taken to insert in middle of array = %d seconds \n", end2-begin2);

    time_t begin3 = time(NULL);

    insertEnd("mis",3,5,6,2,97);

    time_t end3 = time(NULL);

    printf("Time taken to insert in end of array = %d seconds \n", end3-begin3);

    insertEnd("nunu",3,6,7,800,96);

    insertBeginning("begin",1,2,3,4,5);
    printArray();



    return 0;
}

void dynamicAllocate()
{



    printf("Enter no. of students : ");
    scanf("%d",&n);
    p=(struct student*)calloc(n,n*sizeof(struct student));
    for(i=0; i<n; i++)
    {
        printf("Enter Name : ");
        scanf("%s",&(p+i)->name);

        printf("Enter ID: ");
        scanf("%d",&(p+i)->ID);
        printf("Enter Birthdate in the form of day month year: ");
        scanf("%d %d %d",&(p+i)->birthDate.Day,&(p+i)->birthDate.Month,&(p+i)->birthDate.Year);
        printf("Enter last year score: ");
        scanf("%d",&(p+i)->score);


    }
}
void insertEnd(char name[100], int ID, int day, int month, int year, int score)
{


    n+=1;
    p=(struct student*)realloc(p,(n)*sizeof(struct student));
    int cpyI;
    for(cpyI=0; cpyI<100; cpyI++)
    {
        (p+i)->name[cpyI]=name[cpyI];
    }
    (p+i)->ID=ID;
    (p+i)->birthDate.Day=day;
    (p+i)->birthDate.Month=month;
    (p+i)->birthDate.Year=year;
    (p+i)->score=score;
    i=n;

}
void insertBeginning(char name[100], int ID, int day, int month, int year, int score)
{



    n+=1;
    p=(struct student*)realloc(p,(n)*sizeof(struct student));
    for(i=i; i>0; i--)
    {
        for(int charIndex=0; charIndex<100; charIndex++)
        {
            (p+i)->name[charIndex]=(p+i-1)->name[charIndex];
        }
        (p+i)->ID=(p+i-1)->ID;
        (p+i)->birthDate.Day = (p+i-1)->birthDate.Day;
        (p+i)->birthDate.Month = (p+i-1)->birthDate.Month;
        (p+i)->birthDate.Year=(p+i-1)->birthDate.Year;
        (p+i)->score=(p+i-1)->score;
    }
    int cpyI;
    for(cpyI=0; cpyI<100; cpyI++)
    {
        p->name[cpyI]=name[cpyI];
    }
    p->ID=ID;
    p->birthDate.Day=day;
    p->birthDate.Month=month;
    p->birthDate.Year=year;
    p->score=score;
    i=n;

}
void insertMiddle(char name[100], int newID, int day, int month, int year, int score)
{

    n+=1;
    p=(struct student*)realloc(p,(n)*sizeof(struct student));
    for(i=i; i>=newID; i--)
    {
        for(int charIndex=0; charIndex<100; charIndex++)
        {
            (p+i)->name[charIndex]=(p+i-1)->name[charIndex];
        }
        (p+i)->ID=(p+i-1)->ID;
        (p+i)->birthDate.Day = (p+i-1)->birthDate.Day;
        (p+i)->birthDate.Month = (p+i-1)->birthDate.Month;
        (p+i)->birthDate.Year=(p+i-1)->birthDate.Year;
        (p+i)->score=(p+i-1)->score;
    }

    int cpyI;
    for(cpyI=0; cpyI<100; cpyI++)
    {
        (p+newID-1)->name[cpyI]=name[cpyI];
    }

    (p+newID-1)->ID=newID;
    (p+newID-1)->birthDate.Day=day;
    (p+newID-1)->birthDate.Month=month;
    (p+newID-1)->birthDate.Year=year;
    (p+newID-1)->score=score;

    i=n;

}

int calculateStructSize()
{
    struct student sizest;
    return sizeof(sizest);
}
void printArray()
{

    printf("Number of elements in array= ");
    printf("%d",n);
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("\n");
        printf("Name: ");
        printf("%s",(p+i)->name);
        printf("\n");
        printf("ID: ");
        printf("%d",(p+i)->ID);
        printf("\n");

        printf("Birthdate: ");
        printf("%d", (p+i)->birthDate.Day);
        printf("/");
        printf("%d", (p+i)->birthDate.Day);
        printf("/");
        printf("%d", (p+i)->birthDate.Day);
        printf("\n");
        printf("Score = %d",(p+i)->score);
    }

    i=n;
}



void printList(struct studentNode *head)
{
    struct studentNode *current_node = head;
    while (current_node != NULL)
    {


        printf("%s",current_node->name); printf(" ");
        printf("%d ", current_node->ID);
        printf("%d ", current_node->birthDate.Day);
        printf("%d ", current_node->birthDate.Month);
        printf("%d ", current_node->birthDate.Year);
        printf("\n");
         current_node = current_node->next;


    }
}

int sizeNode(){
struct studentNode nodeStudent;
int size=sizeof(nodeStudent);
return size;
}






