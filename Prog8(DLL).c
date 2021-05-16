/*
Design, Develop and Implement a menu driven Program in C for the following operations on 
Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, 
Sal, PhNo
a. Create a DLL of N Employees Data by using end insertion. 
b. Display the status of DLL and count the number of nodes in it 
c. Perform Insertion and Deletion at End of DLL 
d. Perform Insertion and Deletion at Front of DLL 
e. Demonstrate how this DLL can be used as Double Ended Queue. 
f. Exit 
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char ssn[10], name[20], dept[10], desig[10], phno[10];
    int sal;
    struct node *back;
    struct node *forw;
} NODE;
NODE *start = NULL;
void create();
void display();
int count_nodes();
void insert_front();
void del_front();
void insert_end();
void del_end();
void main_menu();
void input_deque();
void output_deque();
void main()
{
    main_menu();
}
void main_menu()
{
    int ch;
    while (1)
    {
        printf("\n DOUBLY LINKED LIST IMPLEMENTATION\n");
        printf("\n 1. CREATE LIST\n");
        printf("\n 2. INPUT RESTRICTED DEQUE\n");
        printf("\n 3. OUTPUT RESTRICTED DEQUE\n");
        printf("\n 4. DISPLAY\n");
        printf("\n 5.EXIT\n");
        printf("\n ENTER YOUR CHOICE\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            input_deque();
            break;
        case 3:
            output_deque();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("\n INVALID CHOICE\n");
        }
    }
}
void create()
{
    int i, n;
    NODE *newnode, *curptr = NULL;
    printf("\n enter the number of nodes\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        printf("\nenter the ssn\n");
        scanf("%s", newnode->ssn);
        printf("\n enter name department and designation\n");
        scanf("%s%s%s", newnode->name, newnode->dept, newnode->desig);
        printf("\n enter salary\n");
        scanf("%d", &newnode->sal);
        printf("\n enter phone number\n");
        scanf("%s", newnode->phno);
        if (start == NULL)
        {
            newnode->forw = NULL;
            newnode->back = NULL;
            start = newnode;
        }
        else
        {
            curptr = start;
            while (curptr->forw != NULL)
                curptr = curptr->forw;
            newnode->back = curptr;
            newnode->forw = NULL;
            curptr->forw = newnode;
        }
    }
}
void display()
{
    NODE *curptr = NULL;
    if (start == NULL)
        printf("\n LIST EMPTY\n");
    else
    {
        curptr = start;
        printf("\n The contents are\n");
        printf("\n SSN\tNAME\tDEPT\tDESIG\tSALARY\tPHONE\n");
        while (curptr != NULL)
        {
            printf("\n %s\t%s\t%s\t%s\t%d\t%s\n", curptr->ssn, curptr->name,
                   curptr->dept, curptr->desig, curptr->sal, curptr->phno);
            curptr = curptr->forw;
        }
        printf("\n TOTAL NUMBER OF NODES IS %d", count_nodes());
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
            curptr = curptr->forw;
        }
    }
    return ctr;
}
void input_deque()
{
    int ch;
    while (1)
    {
        printf("\n INPUT RESTRICTED DEQUE\n");
        printf("\n 1. insert from rear\n");
        printf("\n 2. delete from rear\n");
        printf("\n 3. delete from front\n");
        printf("\n 4. display\n");
        printf("\n 5. exit from deque\n");
        printf("\n enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_end();
            break;
        case 2:
            del_end();
            break;
        case 3:
            del_front();
            break;
        case 4:
            display();
            break;
        case 5:
            main_menu();
            break;
        default:
            printf("\n wrong choice\n");
        }
    }
}
void insert_end()
{
    NODE *newnode, *curptr = NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nenter the ssn\n");
    scanf("%s", newnode->ssn);
    printf("\n enter name department and designation\n");
    scanf("%s%s%s", newnode->name, newnode->dept, newnode->desig);
    printf("\n enter salary\n");
    scanf("%d", &newnode->sal);
    printf("\n enter phone number\n");
    scanf("%s", newnode->phno);
    if (start == NULL)
    {
        newnode->forw = NULL;
        newnode->back = NULL;
        start = newnode;
    }
    else
    {
        curptr = start;
        while (curptr->forw != NULL)
            curptr = curptr->forw;
        newnode->back = curptr;
        newnode->forw = NULL;
        curptr->forw = newnode;
    }
}
void del_end()
{
    NODE *curptr = NULL;
    if (start == NULL)
        printf("\n LIST EMPTY\n");
    else if (start->forw == NULL)
    {
        curptr = start;
        printf("\n last node\n");
        start = NULL;
        free(curptr);
    }
    else
    {
        curptr = start;
        while (curptr->forw != NULL)
            curptr = curptr->forw;
        curptr->back->forw = NULL;
        free(curptr);
    }
}
void del_front()
{
    NODE *curptr = NULL;
    if (start == NULL)
        printf("\n LIST EMPTY\n");
    else
    {
        curptr = start;
        start = start->forw;
        start->back = NULL;
        free(curptr);
    }
}
void output_deque()
{
    int ch;
    while (1)
    {
        printf("\n OUTPUT RESTRICTED DEQUE\n");
        printf("\n 1. insert from rear\n");
        printf("\n 2. insert from front\n");
        printf("\n 3. delete from front\n");
        printf("\n 4. display\n");
        printf("\n 5. exit from deque\n");
        printf("\n enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_end();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            del_front();
            break;
        case 4:
            display();
            break;
        case 5:
            main_menu();
            break;
        default:
            printf("\n wrong choice\n");
        }
    }
}
void insert_front()
{
    NODE *newnode = NULL;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("\nenter the ssn\n");
    scanf("%s", newnode->ssn);
    printf("\n enter name department and designation\n");
    scanf("%s%s%s", newnode->name, newnode->dept, newnode->desig);
    printf("\n enter salary\n");
    scanf("%d", &newnode->sal);
    printf("\n enter phone number\n");
    scanf("%s", newnode->phno);
    newnode->forw = start;
    newnode->back = NULL;
    start->back = newnode;
    start = newnode;
}
