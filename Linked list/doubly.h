#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *t, *last, *start = NULL, *a, *b;
struct node *create(int num)
{
    t = (struct node *)malloc(sizeof(struct node));
    t->data = num;
    t->next = NULL;
    t->prev=NULL;
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
        t->prev=last;//
        last = t;
    }
}
void atbeg(int data){
    t=create(data);
    if(start==NULL){
        start=t;
    }
    else{
        start->prev=t;//
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
    s->prev=t;//
    s->next=t->next->next;
    t->next->prev=s;//
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
    s->prev=t;//

}
void deleteatbeg(){
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    t=start;
    start=start->next;
    start->prev=NULL;//
    free(t);
}
void deleteatend(){
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    t=start;
    while(t->next->next!=NULL){
        t=t->next;
    }
    t->next=NULL;
}
void deleteatmid(){
    t=start;int pos;
    printf("\nenter position\n");
    scanf("%d",&pos);
    for(int i=0;i<pos;i++){
        t=t->next;
    }
    t->next->prev=t;//
    t->next=t->next->next;

}
void reverse(){
     while (start != NULL) {
        last=start;
        a = start->prev;
        start->prev = start->next;
        start->next = a;            
        start = start->prev;
    }
    if(last!=NULL){
        start=last;
    }

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
