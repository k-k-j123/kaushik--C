#include<stdio.h>
#include<stdlib.h>
#include "sstack.h"
struct stack s;
int main(){
    int n1,n2,n3,num;
    char exp[20],*e;
    init(&s);
    printf("\nenter postfix expression\t");
    scanf("%s",&exp);
    e=exp;
    while(*e!='\0'){
    if(isdigit(*e)){
        num=*e-48;
        push(&s,num);
    }
    else{
        n1=pop(&s);
        n2=pop(&s);
        switch(*e){
            case '+':
            n3=n1+n2;
            break;
             case '-':
            n3=n1-n2;
            break;
             case '*':
            n3=n1*n2;
            break;
             case '/':
            n3=n1/n2;
            break;
        }
        push(&s,n3);
    }
    e++;
    }
    printf("\nresult is %d",pop(&s));
    return 0;
}