#include<stdio.h>
void InsSort(int arr[],int n){
    int key,i,j=0;
    for(i=1;i<=n-1;i++){
        key = arr[i];
        j = i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void printarray(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
int main(){
    int n;
    int arr[]={23,44,22,34,26,99};
    n=6;
    printf("\nbefore sorting array is\n");
    printarray(arr,n);
    InsSort(arr,n);
    printf("\nafter sorting array is\n");
    printarray(arr ,n);
    return 0;
}