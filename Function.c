#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// PUSH FUNCTION
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    top++;
    stack[top] = ch;
}

// POP FUNCTION
char pop()
{
    char ch;

    if (top == -1)
    {
        return '\0';
    }

    ch = stack[top];
    top--;

    return ch;
}

// MATCHING FUNCTION
int matching(char exp[])
{
    int i;
    char ch;

    for (i = 0; i < strlen(exp); i++)
    {
        // Opening brackets
        if (exp[i] == '(' ||
            exp[i] == '{' ||
            exp[i] == '[')
        {
            push(exp[i]);
        }

        // Closing brackets
        else if (exp[i] == ')' ||
                 exp[i] == '}' ||
                 exp[i] == ']')
        {
            if (top == -1)
            {
                return 0;
            }

            ch = pop();

            if ((ch == '(' && exp[i] != ')') ||
                (ch == '{' && exp[i] != '}') ||
                (ch == '[' && exp[i] != ']'))
            {
                return 0;
            }
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char exp[MAX];

    printf("Enter expression: ");
    scanf("%s", exp);

    if (matching(exp))
        printf("Parentheses are balanced.\n");
    else
        printf("Parentheses are not balanced.\n");

    return 0;
}
