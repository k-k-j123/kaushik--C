#include <stdio.h>
#include <string.h>
#include "sstack.h"
struct stack s1;
struct stack s2;
int main()
{
    int I,i=0;
    int t1[MAX],t2[MAX];
    init(&s1);init(&s2);
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s2, 1);
    push(&s2, 1);
    push(&s2, 3);
    while (!ISEMPTY(&s1) && !ISEMPTY(&s2))
    {
         t1[i] = pop(&s1);
         t2[i] = pop(&s2);
        
        i++;
    }
    while(i!=-1){
        if (t1[i] != t2[i])
        {
            I = 1;
        }
        push(&s1,t1[i]);
        push(&s2,t2[i]);
        i--;
    }
    display(&s1);printf("\n");
    display(&s2);
    if (I == 1)
    {
        printf("\nstack are not identical\n");
    }
    else
    {
        printf("\nstack are identical\n");
    }
    return 0;
}
