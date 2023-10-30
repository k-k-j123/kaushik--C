#include<stdio.h>
# define MAX 100
int arr[MAX];
int data;
int top = -1;
void push(int x){
	if(top==MAX){
		printf("\nstack is full\n");
		return;
	}
	top++;
	arr[top]=x;
}
int pop(){
	if(top==-1){
		printf("\nstack is empty");
	}
	else{
	data=arr[top];
	top--;
	return data;
	}
}

void pritnarr(){
	for(int i=top;i>=0;i--){
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	pritnarr();
	pop();
	pop();
	pritnarr();
	return 0;

}