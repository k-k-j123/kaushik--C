#include<stdio.h>
#define MAX 100
int main()
{
    int arr[MAX],i,index,size,element=0;
    
    printf("\nenter the size of array\t",size);
    scanf("%d",&size);
    
    printf("\nenter array elements\t");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nenter the position where you want to delete the element\t");
    scanf("%d",&index);

    //printing original array
    printf("\noriginal array\n");
    for(i=0;i<size;i++)
    {
        printf("\t%d",arr[i]);
    }
    //adding element to arr
    for(i=index-1;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    //printing final array
     printf("\nfinal array\n");
      for(i=0;i<size;i++)
      {
        printf("\t%d",arr[i]);
      }
}