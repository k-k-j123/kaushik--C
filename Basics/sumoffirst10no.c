//c program to print sum of first 10 natural nos
#include<stdio.h>
int main()
{
    int i ,sum=0;
    for(i=0;i<=10;i++)
    {
        sum=sum+i;
    }
    printf("\nsum of first 10  natural nos is %d",sum);
}