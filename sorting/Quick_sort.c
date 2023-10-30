// #include <stdio.h>
// #include <stdlib.h>
// void swap(int *a, int *b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }
// int partition(int a[], int l, int h)
// {
//     int i = l + 1;
//     int j = h;
//     int piv = a[l];
//     do
//     {
//         while (a[i] <= piv )
//         {
//             i++;
//         }
//         while (a[i] > piv)
//         {
//             j--;
//         }
//         if (i < j)
//         {
//             swap(&a[i], &a[j]);
//         }

//     } while (i < j);
//     swap(&a[l], &a[j]);
//     return j;
// }
// void quicksort(int a[], int l, int h)
// {
//     int p;
//     if (l < h)
//     {
//         p = partition(a, l, h);
//         quicksort(a, l, p - 1);
//         quicksort(a, p + 1, h);
//     }
// }
// void display(int a[], int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         printf("%d\t", a[i]);
//     }
// }
// void generate(int a[], int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//        scanf("%d",&a[i]);
//     }
// }
// int main()
// {
//     int a[30], n;
//     printf("\nenter value of n");
//     scanf("%d", &n);
//     generate(a,n);
//     printf("\narray before sorting is\n");
//     display(a, n);
//     quicksort(a, 0, n - 1);
//     printf("\narray after sorting is\n");
//     display(a, n);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);

    // Swap A[low] and A[j]
    swap(&A[low], &A[j]);
    return j;
}

void quickSort(int A[], int low, int high)
{
    int p; // Index of pivot after partition

    if (low < high)
    {
        p = partition(A, low, high);
        quickSort(A, low, p -1 );  // sort left subarray
        quickSort(A, p + 1, high); // sort right subarray
    }
}
void generate(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 10;
    }
}
int main()
{
    int A[30], n;
    printf("\nenter number of elements\n");
    scanf("%d", &n);
    generate(A, n);
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}
