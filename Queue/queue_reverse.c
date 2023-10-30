#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start,*last,*t,*a,*b;
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
void display(){
    printf("\nelements of queue are\n");
    for(t=start;t!=NULL;t=t->next){
        printf("%d\t",t->data);
    }
}
void reverse(){
    while(start!=NULL){
        a=start->next;
        start->next=b;
        b=start;
        start=a;
    }
    start =b;
    display();

}
int main(){
int n,element;
printf("\nenter number of elements in queue\n");
scanf("%d",&n);
printf("\nenter queue elements\n");
for(int i=0;i<n;i++){
scanf("%d",&element);
add(element);
}

display();
reverse();
return 0;
}