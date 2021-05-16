#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max_size 5

int stack[max_size], top = -1;

void push();
void pop();
void display();
void palindrome();

void main()
{
    int ch;
    while (1)
    {
        printf("\nSTACK\n\n1. Push\n2. Pop\n3. Palindrome\n4. Display\n5. exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            palindrome();
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

void push()
{
    int item;
    if (top == max_size - 1)
    {
        printf("\nSTACK OVERFLOW\n");
        return;
    }
    else
    {
        printf("\nEnter item to be pushed to stack: ");
        scanf("%d", &item);
        stack[++top] = item;
    }
}

void pop()
{
    int item;
    if (top == -1)
        printf("\nSTACK UNDERFLOW\n");

    else
    {
        item = stack[top--];
        printf("\nPopped element is: %d", item);
    }
}

void palindrome()
{
    int rev[max_size], j = 0, i, flag = 0;
    if (top == -1 || top == 0)
        printf("\nPALINDROME CANNOT BE DETERMINED\n");

    for (i = top; i >= 0; i--, j++)
        rev[j] = stack[i];

    for (i = 0; i <= top; i++)
    {
        if (stack[i] != rev[i])
        {
            flag = 1;
        }
    }
    if (flag)
        printf("\nNOT a palindrome");
    else
        printf("\nPalindrome");
}

void display()
{
    int i;
    if (top == -1)
        printf("\nStack empty!\n");
    else
        for (i = top; i >= 0; i--)
            printf("\t%d\n", stack[i]);
}