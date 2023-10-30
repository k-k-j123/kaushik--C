#include<stdio.h>
#include<string.h>
int stringlen(char X[30]);
int main()
{
    int l,i;
    char X[30];
    printf("\nenter a string\n");
    gets(X);
    printf("\nlength of string using std library func is : %d",strlen(X));
    l=stringlen(X);
    printf("\nlength of string without using std library func is : %d",l);
    return 0;
}
int stringlen(char X[30])
{
    int c=0,i;
    for(i=0;X[i]!='\0';i++)
    {
        c++;
    }
    return c;
}