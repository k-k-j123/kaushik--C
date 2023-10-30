#include<stdio.h>
int arr[100];
int data;
int top = -1;
void push(int x){
	if(top==100){
		printf("\nstack is full\n");
		return;
	}
	top++;
	arr[top]=x;
}
int pop(){
	if(top==-1){
		printf("\nstack is empty\n");
	}
	else{
	data=arr[top];
	top--;
	return data;
	}
}
void seek(){
	if(top==-1){
		printf("\nstack is empty\n");
	}
	else{
		printf("\ntop of the stack is %d\n",arr[top]);
	}
}
void display(){
	if(top==-1){
		printf("\nstack is empty\n");
	}
	else{
	for(int i=top;i>=0;i--){
		printf("%d\t",arr[i]);
	}
		printf("\n");
	}
}

int main(){
	int x;
	do{
		printf("\n******Menu******\n");
		printf("1)Push\n2)pop\n3)seek\n4)Display\n5)exit");
		printf("\nenter your choice\n");
		scanf("%d",&x);
		switch(x){
		case 1:
			printf("\nenter the number to be inserted\n");
			scanf("%d",&data);
			push(data);
			break;
		case 2:
			data=pop();
			printf("\nThe element deleated is %d\n",data);
			break;
		case 3:
			seek();
			break;
		case 4:
			display();
			break;
		}
	}while(x!=5);
	return 0;
}