/*
Design, Develop and Implement a menu driven Program in C for the following array 
operations. 
a. Creating an array of N Integer Elements 
b. Display of array Elements with Suitable Headings 
c. Inserting an Element (ELEM) at a given valid Position (POS) 
d. Deleting an Element at a given valid Position (POS)
e. Exit. 
Support the program with functions for each of the above operations. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 5         //Preprocessor directive to replace all occurances of 'max' with '5'(integer)
int a[max];           //Gloabal declaration of array 'a' of size 'max' i.e. 5
int n, count;         //variable 'n' to keep track of number of elements in array. Variable 'count' to check if array exists or not
void create();        //Function prototypes (Necessary because C is a Procedural/Structural Programming Language and has TopDown approach)
void display();
void insert_pos();
void del_pos();

int main()
{
    int ch;
    while (1)
    {
        printf("\nArray Menu-\n");
        printf("\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (count == 0 && n == 0)
                create();
            else
                printf("\nArray already created! Insert elemnts");
            break;

        case 2:
            if (count == 0 || n < 0)
                printf("\nArray does not exist, create array first");
            else
                display();
            break;

        case 3:
            if (count == 0 || n < 0)
                printf("\nArray does not exist, create array first");
            else
                insert_pos();
            break;

        case 4:
            if (count == 0 || n < 0)
                printf("\nArray does not exist, create array first");
            else
                del_pos();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\nINVALID CHOICE!\n");
        }
    }
}

void create()
{
    int i;
    printf("\nEnter the array size: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    count++;
}

void display()
{
    int i;
    if (n == 0)
        printf("\nArray Empty!\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void insert_pos()
{
    int i, pos, elem;
    do
    {
        printf("\nEnter valid position to insert : ");
        scanf("%d", &pos);
    } while (pos <= 0 || pos > n + 1);

    printf("\nEnter element to enter: ");
    scanf("%d", &elem);

    pos--;
    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = elem;
    n++;
}

void del_pos()
{
    int i, pos, elem;
    do
    {
        printf("\nEnter valid position to delete: ");
        scanf("%d", &pos);
    } while (pos <= 0 || pos > n);

    elem = a[--pos];

    for (i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    printf("\nDeleted element is : %d", elem);
    n--;

    return;
}

