#include<stdio.h>
#include "sstack.h"
int data;
#define MAX 100
struct stack s;
int main(){
	int x;
    init(&s);
	while(1){
		printf("\n******Menu******\n");
		printf("1)Push\n2)pop\n3)seek\n4)Display\n5)exit");
		printf("\nenter your choice\n");
		scanf("%d",&x);
		switch(x){
		case 1:
			printf("\nenter the number to be inserted\n");
			scanf("%d",&data);
			push(&s,data);
			break;
		case 2:
			data=pop(&s);
			printf("\nThe element deleated is %d\n",data);
			break;
		case 3:
			data=seek(&s);
			printf("\nTop of the stack is %d",data);
			break;
		case 4:
			display(&s);
			break;
        case 5:
            exit(1);
        default:
            printf("\nenter valid value");
		}
	}
	return 0;
}