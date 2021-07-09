
#include <stdio.h>
#include<stdlib.h>

struct BirthDate
{
    int Day;
    int Month;
    int Year;
};

struct studentNode
{
    char name[100];
    int ID;
    struct BirthDate birthDate;
    int score;
    struct Node* next;
};

struct studentNode *head, *tail = NULL;

// function to add new nodes
void addNode(int Day,int Month, int Year,char name[],int ID,int score)
{
    //Create a new node
    struct studentNode *new_node = (struct node*)malloc(sizeof(struct studentNode));
    new_node->birthDate.Day = Day;
    new_node->birthDate.Month = Month;
    new_node->birthDate.Year = Year;
    new_node->ID = ID;
    new_node->score = score;
    new_node->next = NULL;
    int cpyI;
    for(cpyI=0; cpyI<100; cpyI++)
    {
        new_node->name[cpyI]=name[cpyI];
    }
    //Checks if the list is empty
    if(head == NULL)
    {
        //If list is empty, both head and tail will point to new node
        head = new_node;
        tail = new_node;
    }
    else
    {
        //newNode will be added after tail such that tail's next will point to newNode
        tail->next = new_node;
        //newNode will become new tail of the list
        tail = new_node;
    }
}

void push(struct node** head_ref, int Day,int Month, int Year,char name[],int ID,int score)
{
    /* 1. allocate node */
    struct studentNode* new_node = (struct node*) malloc(sizeof(struct studentNode));

    /* 2. put in the data  */
    new_node->birthDate.Day = Day;
    new_node->birthDate.Month = Month;
    new_node->birthDate.Year = Year;
    new_node->ID = ID;
    new_node->score = score;
    int cpyI;
    for(cpyI=0; cpyI<100; cpyI++)
    {
        new_node->name[cpyI]=name[cpyI];
    }

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}
/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(struct studentNode* prev_node, int Day,int Month, int Year,char name[],int ID,int score)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct studentNode* new_node =(struct studentNode*) malloc(sizeof(struct studentNode));

    /* 3. put in the data */
    new_node->birthDate.Day = Day;
    new_node->birthDate.Month = Month;
    new_node->birthDate.Year = Year;
    new_node->ID = ID;
    new_node->score = score;
    int cpyI;
    for(cpyI=0; cpyI<100; cpyI++)
    {
        new_node->name[cpyI]=name[cpyI];
    }
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a list and an int, appends a new node at the end  */
void append(struct studentNode** head_ref, int Day,int Month, int Year,char name[],int ID,int score)
{
    /* 1. allocate node */
    struct studentNode* new_node = (struct studentNode*) malloc(sizeof(struct studentNode));

    struct studentNode *last = *head_ref;  /* used in step 5*/
    /* 2. put in the data  */
    new_node->birthDate.Day = Day;
    new_node->birthDate.Month = Month;
    new_node->birthDate.Year = Year;
    new_node->ID = ID;
    new_node->score = score;
    int cpyI;
    for(cpyI=0; cpyI<100; cpyI++)
    {
        new_node->name[cpyI]=name[cpyI];
    }
    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}


int main()
{
    /* Start with the empty list */
struct studentNode* head = NULL;
  addNode(8,12,1980,"hoda",12,49);
  // Insert 7 at the beginning. So linked list becomes 7->6->NULL
  push(&head, 7,11,1999,"ali",10,50);

  printf("\n Created Linked list is: ");


  return 0;




    return 0;
}

