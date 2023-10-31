#include<stdio.h>
#include<stdlib.h>
#include "doubly.h"
int main(){
    int x;
    while(1){
        printf("\n******menu******\n");
        printf("\n1)add\n2)delete\n3)display\n4)reverse\n5)sort\n6)exit");
        printf("\nenter your choice\n");
        scanf("%d",&x);
        switch(x){
            case 1:
            printf("\nenter the element to add\n");
            scanf("%d",&x);
            add(x);
            printf("\nelement inserted\n");
            break;
            case 2:
            deleteatmid();
            printf("\nelement deleted\n");
            break;
            case 3:
            display();
            break;
            case 4:
            reverse();
            printf("\nafter reverse the element are\n");
            display();
            break;
            case 5:
            sort();
            printf("\nafter sorting the elements are\n");
            display();
            break;
            case 6:
            exit(1);
            break;
        }
    }
    return 0;
}