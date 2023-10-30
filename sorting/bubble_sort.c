#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void bubble_sort(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        //n-1-i becuse with every pass we do n-i comparison so for 1th pass then no of 
        //comparison will be 1 to 4 for an array with 5 elements as last element is in its
        //right place refer obsidian notes for further explanation
        for(j=0;j<n-1-i;j++){
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
         }
        }
    }
}
void printarray(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
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
    unsigned int max = 10000;
    int A[max], n;
    n=10000;
    generate(A, n);
    //printArray(A, n);
    clock_t start=clock();
    bubble_sort(A,  n - 1);
    clock_t end=clock();
    //printArray(A, n);
    double elapsed_time = (double)(end - start)/CLOCKS_PER_SEC;
    printf("%lf",elapsed_time);
    return 0;
}
