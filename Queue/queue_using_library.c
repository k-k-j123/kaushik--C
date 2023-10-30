#include<stdio.h>
#include<stdlib.h>
#include "queue_lib.h"
int main(){
    struct Queue *q;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    printf("\nbefore reversing queue is\n");
    display(q);
    reverse(q);
    printf("\nafter reversing queue is\n");
    display(q);


}