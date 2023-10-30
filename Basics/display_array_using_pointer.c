#include<stdio.h>
int main()
{
    int a[10]={1,2,3,4,5};
    printf("\narray elements are");
    for (int i = 0; i < 5; i++)
    {
        printf("\n%d",*(a+i));
    }
    return 0;
}