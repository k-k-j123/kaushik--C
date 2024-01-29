#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int temp;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main()
{
    int arr[20];
    int i, n;
    printf("Enter how namy elements?\n");
    scanf("%d",&n);
    printf("\nenter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Before sorting array elements are are: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    heapsort(arr, n);
    printf("\nSorted array is: \n");
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}