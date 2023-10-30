// program to find sum a digits
#include<stdio.h>
int main()
{
    int i,n,r,sum=0;
    printf("\nenter a number\n");
    scanf("%d",&n);
    while(n!=0)
    {
        r=n%10;
        sum=sum+r;
        n=n/10;
    }
    printf("sum id %d",sum);
}