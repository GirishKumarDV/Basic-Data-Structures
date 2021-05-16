/*#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define max 20
char stack[max], postfix[max];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return (stack[top--]);
}

void main()
{
    int op1, op2, i, result;
    char ch;
    printf("\nEnter valid postfix expression without spaces\n");
    gets(postfix);
    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];
        if(isdigit(ch))
        push(ch - '0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch(ch)
            {
                case '+' : result = op1 + op2;
                break;
                case '-' : result = op1 - op2;
                break;
                case '*' : result = op1 * op2;
                break;
                case '/' : result =  op1/op2;
                break;
                case '%' : result = op1%op2;
                break;
                case '^' : result = pow(op1,op2);
                break;
                default : printf("\nINVALID CHARACTER\n");
            }
            push(result);
        }
    }
    result = pop();
    printf("\nRESULT = %d",result); 
}*/

// toh

#include <stdio.h>
int count;
void tower(int n,char s,char t, char d);
void main()
{
    int n;
    printf("\nEnter the number of discs to move from disc A to C: ");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("\nNumber of moves = %d",count);
}

void tower(int n, char s, char t, char d)
{
    if(n==1)
    {
        printf("\nMove disc 1 from %c to %c\n",s,d);
        count++;
        return;
    }
    tower(n-1,s,d,t);
    printf("\nMove disc %d from %c to %c",n,s,d);
    count++;
    tower(n-1,t,s,d);
}