#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int arr[],int low,int high,int mid){
    int i,j,k;
    i=low,j=mid+1,k=0;
    int B[high + 1];
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            B[k]=arr[i];
            k++,i++;
        }
        else{
            B[k]=arr[j];
            j++,k++;
        }
    }
    while(i<=mid){
        B[k]=arr[i];
        k++;i++;
    }
    while(j<=high){
        B[k]=arr[j];
        k++;j++;
    }
    for(k=0,i=low;i<=high;i++,k++){
        arr[i]=B[k];
    }
}
void merge_sort(int arr[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
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
        // A[i] = rand() % 10;
        scanf("%d",&A[i]);
    }
}
int main(){
    int n,arr[30];
    printf("\nenter number of elements:\t");
    scanf("%d",&n);
    if(n>30){
        printf("\nenter number of elements less than 30");
        return -1;
    }
    generate(arr,n);
    printf("\narray before sorting is:-\n");
    printarray(arr,n);
    merge_sort(arr,0,n-1);
    printf("\naray after sorting is:-\n");
    printarray(arr,n);
    return 0;
}

// int main()
// {
   
//     int A[max], n;
//     n=10000;
//     generate(A, n);
//     //printArray(A, n);
//     clock_t start=clock();
//     merge_sort(A,0,n-1);
//     clock_t end=clock();
//     //printArray(A, n);
//     double elapsed_time = (double)(end - start)/CLOCKS_PER_SEC;
//     printf("%lf",elapsed_time);
//     return 0;
// }
