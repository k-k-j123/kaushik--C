#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,j,head,item[20],dst[20];
	int cylinder=20;
	printf("Enter no of locations:");
	scanf("%d",&n);
	printf("Enter position of head:");
	scanf("%d",&head);
	printf("Enter elements of disk queue");
	for(i=0;i<n;i++){
		scanf("%d",&item[i]);
		dst[i]=(head-item[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(dst[j]>dst[i]){
				int temp=dst[j];
				dst[j]=dst[i];
				dst[i]=temp;

				temp=item[i];
				item[i]=item[j];
				item[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		if(item[i]>=head){
			j=i;
			break;
		}
	}
	printf("j=%d",j);
	printf("\n\n order of disk allocation is as follows:");
	for(i=j;j<n;j++){
		printf("->%d",item[i]);
		cylinder+=abs(head-item[i]);
		head=item[i];
	}
	for(i=0;i<j;i++){
		printf("->%d",item[i]);
		cylinder+=abs(head-item[i]);
		head=item[i];
	}
	printf("\n\ncylinder movement:%d\n\n",cylinder);
}


