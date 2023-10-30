// program to revrse a digit
#include<stdio.h>
int main()
{
    int i,n,r;
    printf("\nenter a number\n");
    scanf("%d",&n);
    while(n!=0)
    {
        r=n%10;
        printf("%d",r);
        n=n/10;
    }
}