#include<stdio.h>
int main()
{
    int a[10],n;
    printf("\nenter number of elements in array ");
    scanf("%d",&n);
    printf("\nenter array elements");
    for(int i=0; i<n ; i++)
    {
        scanf("%d",(a+i));
    }
    //printing in reverse order
    printf("\narray in reverse order is\n");
    for(int i=n-1;i>=0;i--)
    {
       printf("%d\n",*(a+i));
    }
    return 0;
}