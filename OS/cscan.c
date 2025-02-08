#include<stdio.h>
#include<stdlib.h>
int main(){
	int RQ[100],i,j,n,THM=0,initial,size,move;
	printf("Enter the no of request:\t");
	scanf("%d",&n);
	printf("Enter the request sequence:\n");
	for(i=0;i<n;i++){
		scanf("%d",&RQ[i]);
	}
	printf("enter inital head position:\t");
	scanf("%d",&initial);
	printf("enter total disk size:\t");
	scanf("%d",&size);
	printf("enter the head movement direction high 1 and low 0:\t");
	scanf("%d",&move);
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(RQ[i]>RQ[i+1]){
				int temp;
				temp=RQ[j];
				RQ[j]=RQ[j+1];
				RQ[j+1]=temp;
			}
		}
	}
	int index;
	for(i=0;i<n;i++){
		if(initial<RQ[i]){
			index=i;
			break;
		}
	}
	if(move==1){
		for(i=index;i<n;i++){
			THM=THM+abs(RQ[i]-initial);
			initial=RQ[i];
		}
		THM=THM+abs(size-RQ[i-1]-1);
		THM=THM+abs(size-1-0);
		initial=0;
		for(i=0;i<index;i++){
			THM=THM+abs(RQ[i]-initial);
			THM=THM+abs(size-RQ[i-1]-1);
			THM=THM+abs(size-1-0);
			initial=0;
		}
		for(i=0;i<index;i++){
			THM=THM+abs(RQ[i]-initial);
			initial=RQ[i];
		}
	}else{
		for(index-1;i>=0;i--){
			THM=THM+abs(RQ[i]+initial);
			initial=RQ[i];
		}
		THM=THM+abs(RQ[i]-initial);
		THM=THM+abs(size-1-0);initial=size-1;
		for(i=n-1;i>=index;i--){
			THM=THM+abs(RQ[i]-initial);
			initial=RQ[i];
		}
	}
	printf("Total head movement is %d",THM);
	return 0;
}


