#include<stdio.h>
#include<stdlib.h>
#include "singly.h"
int main(){
    int x;int pos;int element;
    while(1){
        printf("\nmenu\n");
        printf("\n1)add\n2)delete\n3)display\n4)sort\n5)reverse\n99)exit\n");
        printf("\nenter your choice\t");
        scanf("%d",&x);
        switch(x){
            case 1:
            printf("\nenter the number to insert\n");
            scanf("%d",&element);
            add(element);
            break;
            case 2:
            printf("\nenter position of element to delete\t");
            scanf("%d",&pos);
            deleteatmid(pos);
            break;
            case 3:
            display();
            break;
            case 4:
            sort();
            printf("\nthe sorted linked list is\n");
            display();
            break;
            case 5:
            printf("\nreversed list is\n");
            reverse();
            break;
            case 99:
            exit(1);
            break;
        }
    }
    return 0;
}