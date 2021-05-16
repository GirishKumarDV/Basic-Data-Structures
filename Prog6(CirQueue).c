/*
Design, Develop and Implement a menu driven Program in C for the following operations on 
Circular QUEUE of Characters (Array Implementation of Queue with maximum size MAX) 
a. Insert an Element on to Circular QUEUE 
b. Delete an Element from Circular QUEUE 
c. Demonstrate Overflow and Underflow situations on Circular QUEUE 
d. Display the status of Circular QUEUE 
e. Exit 
Support the program with appropriate functions for each of the above operations 
*/

#include <stdio.h>
#include <stdlib.h>
#define max 10
int count, rear = -1, front = 0;
char queue[max];

void insert();
void delete ();
void display();

void main()
{
    int ch;
    while (1)
    {
        printf("\nQUEUE\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nINVALID CHOICE!\n");
        }
    }
}

void insert()
{
    char ch, item;
    if (count >= max)
    {
        printf("\nQueue Overflow!\n");
        return;
    }
    else
    {
        ch = getchar();
        printf("\nEnter character to input: ");
        item = getchar();
    
        rear = (rear + 1) % max;
        queue[rear] = item;
        count++;
    }
}

void delete ()
{
    char item;
    if (count <= 0)
        printf("\nQueue underflow\n");
    else
        item = queue[front];
    front = (front + 1) % max;
    printf("\nDeleted element: %c", item);
    count--;
}

void display()
    {
    int i, j;
    if (count <= 0)
        printf("\nQueue Empty!\n");
    else
    {
        i = front;
        for (j = 1; j <= count; j++)
        {
            printf("%c", queue[i]);
            i = (i + 1) % max;
        }
    }
}
