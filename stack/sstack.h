#include<stdio.h>
#include<stdlib.h>
#include<String.h>
 #define MAX 100
struct stack{
    int arr[MAX];
    int top;
};
void init(struct stack *ps){
    ps->top=-1;
}
int ISFULL(struct stack *ps){
    if(ps->top==MAX-1)
        return 1;
    else 
        return 0;
}
int ISEMPTY(struct stack *ps){
    if(ps->top==-1)
        return 1;
    else
        return 0;
}
void push(struct stack *ps,int data){
    if(ISFULL(ps)){
        printf("\nstack is full");
    }else{
        ps->top++;
        ps->arr[ps->top]=data;
    }
}
int pop(struct stack *ps){
    int data;
    if(ISEMPTY(ps)){
        printf("\nstack is empty");
        return -1;
    }else{
        data=ps->arr[ps->top];
        ps->top--;
        return data;
    }
}
int seek(struct stack *ps){
    if(ISEMPTY(ps)){
        printf("\nstack is empty");
        return -1;
    }else{
        return ps->arr[ps->top];
    }
}
void display(struct stack *ps){
    if(ISEMPTY(ps)){
        printf("\nstack is empty");
        return;
    }
        printf("\nstack is-\n");
        for(int i=0;i<=ps->top;i++){
            printf("%d\t",ps->arr[i]);
        }
        printf("\n");

}

