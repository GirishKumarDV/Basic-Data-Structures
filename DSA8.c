
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char ssn[10],name[20],dept[10],desig[10],phno[10];
    int sal;
    struct node *back;
    struct node *forw;
}NODE;
NODE *start=NULL;
void create();
void display();
void insert_front();
void del_front();
void insert_end();
void del_end();
int count_nodes();
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
    while(1)
    {
        printf("\nDOUBLE LINKED LIST IMPLEMENTATION\n");
        printf("1.CREATE LIST\n");
        printf("2.INPUT RESTRICTED DEQUE\n");
        printf("3.OUTPUT RESTRICTED DEQUE\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : input_deque();
                     break;
            case 3 : output_deque();
                     break;
            case 4 : display();
                     break;
            case 5 : exit(0);
            default : printf("\nINVALID CHOICE\n");
        }
    }
}
void create()
{
    int i,n;
    NODE*newnode,*curptr=NULL;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     insert_front();
}
void display()
{
    NODE *curptr=NULL;
    if(start==NULL)
    {
        printf("\n\tLIST IS EMPTY\n");
    }
    else
    {
        curptr=start;
        printf("\n The contents are\n");
        printf("\n SSN\tNAME\tDEPT\tDESIG\tSALARY\tPHONE\n");
        while(curptr!=NULL)
        {
            printf("\n %s\t%s\t%s\t%s\t%d\t%s\n",curptr->ssn,curptr->name,curptr->dept,curptr->desig,curptr->sal,curptr->phno);
            curptr=curptr->forw;
        }
    }
    printf("\nNumber Of nodes= %d",count_nodes());
}
int count_nodes()
{
    NODE *curptr=NULL;
    int ch=0;
    if(start==NULL)
    {
        return 0;
    }
    else
    {
        curptr = start;
        while(curptr!=NULL)
        {
            curptr=curptr->forw;
            ch++;
        }
        return ch;
    }
}
void insert_front()
{
    NODE *newnode=NULL,*curptr=NULL;
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter the ssn\n");
    scanf("%s",newnode->ssn);
    printf("Enter the name department and designation\n");
    scanf("%s%s%s",newnode->name,newnode->dept,newnode->desig);
    printf("\nEnter the salary\n");
    scanf("%d",&newnode->sal);
    printf("\nEnter phone number\n");
    scanf("%s",newnode->phno);
    if(start==NULL)
    {
        newnode->back=NULL;
        newnode->forw=NULL;
        start=newnode;
    }
    else
    {
        curptr=start;
        curptr->back=newnode;
        newnode->back=NULL;
        newnode->forw=curptr;
        start=newnode;

    }

}
void insert_end()
{
    NODE*newnode=NULL,*curptr=NULL;
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter the ssn\n");
    scanf("%s",newnode->ssn);
    printf("Enter the name department and designation\n");
    scanf("%s%s%s",newnode->name,newnode->dept,newnode->desig);
    printf("\nEnter the salary\n");
    scanf("%d",&newnode->sal);
    printf("\nEnter phone number\n");
    scanf("%s",newnode->phno);
    if(start==NULL)
    {
        newnode->forw=NULL;
        newnode->back=NULL;
        start=newnode;
    }
    else
    {
        curptr=start;
        while(curptr->forw!=NULL)
        {
            curptr=curptr->forw;
        }
        newnode->back=curptr;
        curptr->forw=newnode;
        newnode->forw=NULL;
    }
}
void del_end()
{
    NODE*curptr=NULL;
    if(start==NULL)
    {
        printf("\nlist empty\n");
    }
    else
    if(start->forw==NULL)
    {
        curptr=start;
        start=NULL;
        free(curptr);
    }
    else
    {
        curptr=start;
        while(curptr->forw!=NULL)
            curptr=curptr->forw;
            curptr->back->forw=NULL;
            free(curptr);

    }
}
void del_front()
{
    NODE*curptr=NULL;
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        curptr=start;
        start=start->forw;
        start->back=NULL;
        free(curptr);
    }
}
void input_deque()
{
    int ch;
    while(1)
    {
        printf("\nINPUT RESTRICTED DEQUE\n");
        printf("1.Insert from rear\n");
        printf("2.Delete from rear\n");
        printf("3.Delete from front\n");
        printf("4.Display\n");
        printf("5.Exit from deque\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insert_end();
                     break;
            case 2 : del_end();
                     break;
            case 3 : del_front();
                     break;
            case 4 : display();
                     break;
            case 5 : main_menu();
                     break;
            default : printf("\n!!!Invalid choice!!!\n");
        }
    }
}
void output_deque()
{
    int ch;
    while(1)
    {
        printf("\nOUTPUT RESTRICTED DEQUE\n");
        printf("1.Insert from rear\n");
        printf("2.Insert from front\n");
        printf("3.Delete from front\n");
        printf("4.Display\n");
        printf("5.Exit from deque\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insert_end();
                     break;
            case 2 : insert_front();
                     break;
            case 3 : del_front();
                     break;
            case 4 : display();
                     break;
            case 5 : main_menu();
                     break;
            default : printf("\n!!!Invalid choice!!!\n");
        }
    }
}
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
