#include <stdio.h>
#include <stdlib.h>
int maximum(int arr[], int n)
{
    int i;
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int arr[], int n)
{
    int max = maximum(arr, n);
    int C[max + 1];
    int output[max];
    int i, j;
    for (i = 0; i < max + 1; i++)
    {
        C[i] = 0; // initializing count arr by zero
    }
    for (i = 0; i < n; i++)
    {
        C[arr[i]]++; // incrementing corresponding index
    }
    for(i=1;i<=max;i++)
    {
        C[i]=C[i]+C[i-1];//store cumulative sum in count arr
    }
    for(j=n;j>=1;j--)
    {
        output[C[arr[j]]-1]=arr[j];
        C[arr[j]]--;
    /*    *count[A[i]] - 1 calculates the index where this employee should 
    be placed in the sorted output array. Since counting sort is a 0-based 
    index-based algorithm, subtracting 1 adjusts the index accordingly
     Copy the sorted output back to the original array*/
    }
    for (int i = 1; i < n; i++)
    {
        arr[i] = output[i];//copy back to original arr
    }
}
void printarr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
void generate(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
    }
}
int main()
{
    int arr[30], n;
    printf("\nenter number of elements\t");
    scanf("%d", &n);
    generate(arr, n);
    printf("\narray before sorting\n");
    printarr(arr, n);
    countsort(arr, n);
    printf("\narray after sorting\n");
    printarr(arr, n);
    return 0;
}