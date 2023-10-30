#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[30],i,key,n;
    printf("\nenter the number of elements\t");
    scanf("%d",&n);
    // if(n>30)
    // {
    //     printf("\nenter number of elements less than 30");
    //     return -1;
    // }
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    printf("\narray is:-\n");
    for(i=0;i<n;i++)
    {
    printf("%d\t",arr[i]);
    }
    printf("\nenter the number you want to search\t");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        break;
    }
    if(i>n)
    {
        printf("\nelement not found in array");
    }
    else
    {
        printf("\nelement present at index %d",i);
    }
}