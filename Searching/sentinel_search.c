#include<stdio.h>
#include<stdlib.h>
void search(int arr[],int n,int key)
{
 int last=arr[n-1];
 arr[n-1]=key;
 int i=0;
 while(arr[i]!=key)
 {
  i++;
 }
 arr[n-1]=last;
 if((i<n-1)||(arr[n-1]==key))
 {
 printf("element is present at %d\n",i);
 }
 else 
 {
 printf("element not found\n");
 }
}
int main()
{
 int arr[30],n,key,i;
 printf("\nenter size of array:\t");
 scanf("%d",&n);
 if(n>30)
 {
    printf("\nenter no of element less than 30");
     return -1;
 }
 for(i=0;i<n;i++)
 {
  arr[i]=rand()%100;
 }
 for(i=0;i<n;i++)
 {
 printf("%d\t",arr[i]);
 }
 printf("\nenter the element to search\t");
 scanf("%d",&key);

 search(arr,n,key);
 return 0;
}