#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
	int pid,n=4,i,j,temp,key;
	int arr[20]={3,2,1,5};
	pid=fork();
	if(pid==0){
		//nice(-10);
		printf("\nChild process executing bubble sort");
		for(i=0;i<n-1;i++){
	        for(j=0;j<n-1-i;j++){
	            if (arr[j] > arr[j + 1]) {
	                int temp = arr[j];
	                arr[j] = arr[j + 1];
	                arr[j + 1] = temp;
	        	 }
        	}
    	}
    	printf("\nafter sorting\n");
    	for(i=0;i<n;i++)
			printf("%d ",arr[i]);
	}
	else{
		nice(5);
		//wait(NULL);
		printf("\nparent process executing insertion sort");
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
    	printf("\nafter sorting\n");
    	for(i=0;i<n;i++)
			printf("%d ",arr[i]);
	}
	return 0;
}
