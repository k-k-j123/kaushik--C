#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 20
int top;
char items[max];
void push(char data)
{
    if (top == max - 1)
    {
        printf("\nstackoverflow");
    }
    else
    {
        items[++top] = data;
    }
}
char pop()
{
    char letter = items[top--];
    return letter;
}
void revrse()
{
    int i;
    char str[20];
    int count;
    int data;
    char temp[20];
    printf("\nenter the stirng u want to reverse\n");
    scanf("\n%s", str);
    int l = strlen(str);
    for (i = 0; i < l; i++)
    {
        push(str[i]);
    }
    printf("\nreversed string is\n");
    for (i = 0; i < l; i++)
    {
        temp[i] = pop();
        printf("%c", temp[i]);
    }
    if (strcmp(temp, str) == 0)
    {
        printf("\n%s is palindrome\n", str);
    }
}
int main()
{
    revrse();
    return 0;
}