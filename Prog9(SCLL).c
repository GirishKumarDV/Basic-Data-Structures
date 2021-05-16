/*
Design, Develop and Implement a Program in C for the following operationson Singly 
Circular Linked List (SCLL) with header nodes 
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x^2yz-4yz^5+3x^3yz+2xy^5z-2xyz^3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the 
result in POLYSUM(x,y,z) 
Support the program with appropriate functions for each of the above operations 
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    float cf, px, py, pz;
    int flag;
    struct node *link;
};
typedef struct node NODE;
NODE *getnode()
{
    NODE *x;
    x = (NODE *)malloc(sizeof(NODE));
    if (x == NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    return x;
}

void display(NODE *head)
{
    NODE *temp;
    if (head->link == head) //
    {
        printf("Polynomial does not exist\n");
        return;
    }
    temp = head->link;
    printf("\n");
    while (temp != head)
    {
        printf("%f x^%f y^%f z^%f", temp->cf, temp->px, temp->py, temp->pz);
        if (temp->link != head)
            printf(" + ");
        temp = temp->link;
    }
    printf("\n");
}
NODE *insert_rear(float cf, float x, float y, float z, NODE *head)
{
    NODE *temp, *cur;
    temp = getnode();
    temp->cf = cf;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    cur = head->link; //
    while (cur->link != head)
    {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}
NODE *read_poly(NODE *head)
{
    float px, py, pz, cf, ch;
    do
    {
        printf("\nEnter coeff: ");
        scanf("%f", &cf);
        printf("\nEnter x, y, z powers(0-indiacate NO term): ");
        scanf("%f%f%f", &px, &py, &pz);
        head = insert_rear(cf, px, py, pz, head);
        printf("\nIf you wish to continue press 1 otherwise press 0: ");
        scanf("%d", &ch);
    } while (ch !=0 );
    return head;
}
NODE *add_poly(NODE *h1, NODE *h2, NODE *h3)
{
    NODE *p1, *p2;
    float x1, x2, y1, y2, z1, z2, cf1, cf2, cf;
    p1 = h1->link;
    while (p1 != h1)  
    {
        x1 = p1->px;
        y1 = p1->py;
        z1 = p1->pz;
        cf1 = p1->cf;
        p2 = h2->link;
        while (p2 != h2)
        {
            x2 = p2->px;
            y2 = p2->py;
            z2 = p2->pz;
            cf2 = p2->cf;
            if (x1 == x2 && y1 == y2 && z1 == z2)
                break;
            p2 = p2->link;  
        }
        if (p2 != h2) 
        {
            cf = cf1 + cf2;
            p2->flag = 1;
            if (cf != 0) 
                h3 = insert_rear(cf, x1, y1, z1, h3);
        }
        else
            h3 = insert_rear(cf1, x1, y1, z1, h3);
        p1 = p1->link;
    }
    p2 = h2->link;  
    while (p2 != h2)
    {
        if (p2->flag == 0)
            h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        p2 = p2->link;
    }
    return h3;
}
void evaluate(NODE *h1)
{
    NODE *head;
    float x, y, z;
    float result = 0.0;
    head = h1;
    printf("\nEnter x, y, z, terms to evaluate:\n");
    scanf("%f%f%f", &x, &y, &z);
    while (h1->link != head)
    {
        result = result + (h1->cf * pow(x, h1->px) * pow(y, h1->py) * pow(z, h1->pz));
        h1 = h1->link;
    }
    result = result + (h1->cf * pow(x, h1->px) * pow(y, h1->py) * pow(z, h1->pz));
    printf("\nPolynomial result is: %f", result);
}
void main()
{
    NODE *h1, *h2, *h3, *h;
    int ch;
    h = getnode();
    h1 = getnode();
    h2 = getnode();
    h3 = getnode();
    h->link = h;     
    h1->link = h1;
    h2->link = h2;
    h3->link = h3;
    while (1)
    {
        printf("\n\n1.Evaluate polynomial\n2.Add two polynomials\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
case 1:
            printf("\nEnter polynomial to evaluate:\n");
            h = read_poly(h);
            display(h);
            evaluate(h);
            break;
        case 2:
            printf("\nEnter the first polynomial:");
            h1 = read_poly(h1);
            printf("\nEnter the second polynomial:");
            h2 = read_poly(h2);
            h3 = add_poly(h1, h2, h3);
            printf("\nFirst polynomial is: ");
            display(h1);
            printf("\nSecond polynomial is: ");
            display(h2);
            printf("\nThe sum of 2 polynomials is: ");
            display(h3);
            free(h1);
            free(h2);
            free(h3);
            break;
        case 3: 
            exit(0);
            break;
        default:
            printf("\nInvalid entry");
            break;
        }
    }
}
