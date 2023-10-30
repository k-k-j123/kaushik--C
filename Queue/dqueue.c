#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start,*last,*t;
struct node *create(int data){
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
    return n;
}
void add(int data){
    t=create(data);
    if(start==NULL){
        start=t;
        last=t;
    }
    last->next=t;
    last=t;
}
void delete(){
    if(start==NULL){
        printf("\nqueue is empty");
        return ;
    }
    t=start;
    start=start->next;
    printf("\nelement deleted");
    free(t);
}
void display(){
    printf("\nelements of queue are\n");
    for(t=start;t!=NULL;t=t->next){
        printf("%d\t",t->data);
    }
}
void seek(){
    if(start==NULL){
        printf("\nqueue is empty\n");
        return;
    }
    printf("\nfirst in queue is %d",start->data);
}
void check(){
    if(start==NULL){
        printf("\nthere are no elements in queue\n");
        return;
    }
    printf("\nthere are elements in the queue\n");
    
}
int main(){
    int x;
    while(1){
        printf("\nmenu\n");
        printf("\n1)add\n2)delete\n3)display\n4)check\n5)peek\n6)exit");
        printf("\nenter your choice\t");
        scanf("%d",&x);
        switch(x){
            case 1:
            printf("\nenter element to be inserted\n");
            scanf("%d",&x);
            add(x);
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            check();
            break;
            case 5:
            seek();
            break;
            case 6:
            exit(1);
            break;
        }
    }
    return 0;
}