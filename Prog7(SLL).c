/*
Design, Develop and Implement a menu driven Program in C for the following operations on 
Singly Linked List (SLL) of Student Data with the fields: USN, Name, Programme, Sem, 
PhNo
a. Create a SLL of N Students Data by using front insertion. 
b. Display the status of SLL and count the number of nodes in it 
c. Perform Insertion / Deletion at End of SLL 
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack) 
e. Exit
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char usn[20], name[20], branch[10], phone[10];
    int sem;
    struct node *link;
} NODE;

NODE *start = NULL;
int count_nodes();
void main_menu();
void create_list();
void insert_front();
void display();
void insert_end();
void del_front();
void del_end();
void stack();
void queue();
void main()
{
    main_menu();
}
void main_menu()
{
    int ch;
    while (1)
    {
        printf("\n-------------------SINGLY LINKED LIST IMPLEMENTATION---------------------------\n");
        printf("\n1. CREATE LIST\n");
        printf("\n2. INSERTION AND DELETION FROM FRONT(STACK)\n");
        printf("\n3. INSERTION AT END AND DELETION FROM FRONT(QUEUE)\n");
        printf("\n4. DISPLAY\n");
        printf("\n5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create_list();
            break;
        case 2:
            stack();
            break;
        case 3:
            queue();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nINVALID CHOICE!\n");
        }
    }
}

void create_list()
{
    //NODE *newnode=NULL;
    int n, i;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        insert_front();
    }
}

void display()
{
    NODE *curptr = NULL;
    if (start == NULL)
        printf("\nLIST EMPTY!\n");
    else
    {
        curptr = start;
        printf("\nUSN\t\tNAME\tBRANCH\tSEM\tPHONE NUMBER\n");
        while (curptr != NULL)
        {
            printf("\n%s\t\t%s\t%s\t%d\t%s\n", curptr->usn, curptr->name, curptr->branch, curptr->sem, curptr->phone);
            curptr = curptr->link;
        }
        printf("\nNumber of nodes= %d\n", count_nodes());
    }
}

void stack()
{
    int ch;
    while (1)
    {
        printf("\n______STACK IMPLEMENTATION________\n");
        printf("\n1. INSERT FRONT\n");
        printf("\n2. DELETE FRONT\n");
        printf("\n3. DISPLAY\n");
        printf("\n4. EXIT FROM STACK MENU\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_front();
            break;
        case 2:
            del_front();
            break;
        case 3:
            display();
            break;
        case 4:
            main_menu();
            break;
        default:
            printf("\nINVALID CHOICE!!\n");
        }
    }
}

void insert_front()
{
    NODE *newnode = NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter USN: ");
    scanf("%s", newnode->usn);
    getchar();
    printf("\nEnter name and branch:\n ");
    scanf("%[^\n] %[^\n]", newnode->name, newnode->branch);
    printf("\nEnter Semester: ");
    scanf("%d", &newnode->sem);
    printf("\nEnter Phone Number: ");
    scanf("%s", newnode->phone);
    newnode->link = start;
    start = newnode;
}

void del_front()
{
    NODE *curptr = NULL;
    if (start == NULL)
        printf("\n LIST EMPTY!!\n");
    else
    {
        curptr = start;
        start = start->link;
        printf("\nThe deleted information is: \n");
        printf("\nUSN\t\tNAME\t\tBRANCH\tSEM\tPHONE NUMBER\n");
        printf("\n%s\t%s\t%s\t%d\t%s\n", curptr->usn, curptr->name, curptr->branch, curptr->sem, curptr->phone);
        free(curptr);
    }
}

int count_nodes()
{
    NODE *curptr = NULL;
    int ctr = 0;
    if (start == NULL)
        return 0;
    else
    {
        curptr = start;
        while (curptr != NULL)
        {
            ctr++;
            curptr = curptr->link;
        }
    }
    return ctr;
}

void queue()
{
    int ch;
    while (1)
    {
        printf("\n_________QUEUE IMPLEMENTATION__________\n");
        printf("\n1. INSERT END\n");
        printf("\n2. DELETE FRONT\n");
        printf("\n3. DISPLAY\n");
        printf("\n4. EXIT FROM QUEUE MENU\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_end();
            break;
        case 2:
            del_front();
            break;
        case 3:
            display();
            break;
        case 4:
            main_menu();
            break;
        default:
            printf("\nINVALID CHOICE!!\n");
        }
    }
}

void insert_end()
{
    NODE *curptr, *newnode = NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter USN: ");
    scanf("%s", newnode->usn);
    getchar();
    printf("\nEnter Name and Branch:\n ");
    scanf("%[^\n] %[^\n]", newnode->name, newnode->branch);
    printf("\nEnter Semester: ");
    scanf("%d", &newnode->sem);
    printf("\nEnter Phone Nnumber: ");
    scanf("%s", newnode->phone);
    if (start == NULL)
    {
        newnode->link = start;
        start = newnode;
    }
    else
    {
        curptr = start;
        while (curptr->link != NULL)
        {
            curptr = curptr->link;
        }
        curptr->link = newnode;
    }
}

void del_end()
{
    NODE *curptr = NULL, *nextcur = NULL;
    if (start == NULL)
        printf("\nLIST EMPTY!!\n");
    else if (start->link == NULL)
        free(start);
    else
    {
        curptr = start;
        nextcur = curptr;
        while (curptr->link != NULL)
        {
            nextcur = curptr;
            curptr = curptr->link;
        }
        nextcur->link = NULL;
        free(curptr);
    }
}
