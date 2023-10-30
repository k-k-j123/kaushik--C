#include<stdio.h>
void select_sort(int arr[],int n){
    int min,i,j,temp=0;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            
            if(arr[j]>arr[min])
            {
                min = j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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
    int arr[]={8,0,7,1,3};
    int n=5;
    printf("\narray before sorting is\n");
    printarray(arr,n);
    select_sort(arr,n);
    printf("\narray after sorting is\n");
    printarray(arr,n);
    return 0;

}