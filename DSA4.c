#include <stdio.h>
#include <ctype.h>
#define max 20

char infix[max], postfix[max], stack[max];
int top = -1;
int precedence(char ch);

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return (stack[top--]);
}

int precedence(char ch)
{
    switch (ch)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '-':
    case '+':
        return 2;
    case '*':
    case '/':
    case '%':
        return 3;
    case '^':
        return 4;
    }
}

void main()
{
    char ch, elem;
    int k = 0, i = 0;
    printf("\nEnter infix expression: ");
    gets(infix);
    puts(infix);
    push('#');
    while ((ch = infix[i++]) != '\0')
    {
        if(isalnum(ch))
        postfix[k++] = ch;
        else if(ch == '(')
        push(ch);
        // else if(ch == ' ')
        // i++;
        else if(ch == ')')
        {
            while(stack[top] != '(')
            postfix[k++] = pop();
            elem = pop();
        }
        else // operator
        {
            while(precedence(stack[top]) >= precedence(ch))
            postfix[k++] = pop();
            push(ch);
        }
    }
    while(stack[top] != '#')
    postfix[k++] = pop();
    postfix[k] = '\0';
    printf("\nINFIX : %s\nPOSTFIX: %s",infix, postfix);
}