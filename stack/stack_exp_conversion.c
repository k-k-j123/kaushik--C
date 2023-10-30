#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 20
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
void convert(char *expression)
{
    int top = -1;
    int k = -1;
    char stack[max], result[max];
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] >= 'a' && expression[i] <= 'z' || expression[i] >= 'A' && expression[i] <= 'Z')
        {
            result[++k] = expression[i];
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^')
        {
            while (top != -1 && precedence(expression[i]) <= precedence(stack[top]))
            {
                result[++k] = stack[top--]; // If the precedence of the character is lower, pop the operator from the stack and output it
            }
            stack[++top] = expression[i]; // If the precedence of the character is higher than the precedence of the operator on the top of the stack, push it onto the stack.
        }
        else if (expression[i] == '(')
        {
            stack[++top] = expression[i];
        }
        else if (expression[i] == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                result[++k] = stack[top--];
            }
            if (top != -1 && stack[top] == '(')
            {
                top--;
            }
        }
    }
    while (top != -1)
    {
        result[++k] = stack[top--];
    }
    result[++k] = '\0';
    printf("\npostfix expression is %s\n", result);
}
int main()
{
    char expression[max];
    printf("\nenter an expression\n");
    scanf("%s", &expression);
    convert(expression);
    return 0;
}
