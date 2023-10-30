#include<stdio.h>
#include<Stdlib.h>
#include "sstack.h"
int main(void)
{
    struct stack s1,t,s2;
    init(&s1);
    init(&s2);
    init(&t);
    int i,n,num;
    printf("How many elements in stack1: ");
    scanf("%d",&n);
    printf("Enter element in stack1: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        push(&s1,num);   //pushing elements in stack1
    }
    while(!ISEMPTY(&s1))
     {
         push(&t,pop(&s1));   //pushing stack1 elements in temporary stack
     }
    while(!ISEMPTY(&t))
     {
         push(&s1,seek(&t));   //pushing temporary stack element in stack1
         push(&s2,pop(&t));    //pushing temporary stack element in stack2
     }
     printf("\n-----Elements of stack1 is copied in stack2------\n");

}

