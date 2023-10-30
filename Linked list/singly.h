#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    // struct node *prev;
};
struct node *t, *last, *start = NULL, *a, *b;
struct node *create(int num)
{
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;
    t->next = NULL;
    // t->prev=NULL;
    return t;
}
void add(int data)
{
    t = create(data);
    if (start == NULL)
    {
        start = t;
        last = t;
    }
    else
    {
        last->next = t;
        // t->prev=last;
        last = t;
    }
}
void atbeg(int data){
    t=create(data);
    if(start==NULL){
        start=t;
    }
    else{
        //start->prev=t
        t->next=start;
        start=t;

    }
}
void atmiddle(int data){
    int pos;
    struct node *s;
    s=create(data);
    printf("\nenter position\n");
    scanf("%d",&pos);
    t=start;
    for(int i=0;i<pos;i++){
        t=t->next;
    }
    s->next=t->next->next;
    t->next=s;
    
}
void atend(int data){
    struct node *s;
    s=create(data);
    t=start;
    if(start==NULL){
        start=t;
    }
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=s;
}
void deleteatbeg(){
    t=start;
    start=start->next;
    free(t);
}
void deleteatend(){
    t=start;
    while(t->next->next!=NULL){
        t=t->next;
    }
    t->next=NULL;
}
void deleteatmid(int pos){
     t=start;
    for(int i=0;i<pos-1;i++){
        t=t->next;
    }
    t->next=t->next->next;

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
void display()
{
    t = start;
    printf("\nelements of list are\n");
    while (t != NULL)
    {
        printf("%d\t", t->data);
        t = t->next;
    }
}
void sort()
{
    int i, j, x;
    a = start;
    b = start;
    if (a == NULL)
    {
        printf("\n List empty to sort");
        return;
    }
    for (a = start; a != NULL; a = a->next)
    {
        for (b = a->next; b != NULL; b = b->next)
        {
            if (a->data > b->data)
            {
                x = a->data;
                a->data = b->data;
                b->data = x;
            }
        }
    }
}
