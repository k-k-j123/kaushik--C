#include<stdio.h>
#include<Stdlib.h>
#define max 100
int pqueue[max];
int front,rear;
void create(){
    front=rear=-1;
}
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= pqueue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pqueue[j] = pqueue[j - 1];
            }
            pqueue[i] = data;
            return;
        }
    }
    pqueue[i] = data;
}
void insert(int data){
    if(rear==max-1){
        printf("\nqueue overflow\n");
        return;
    }
    if(front ==-1 && rear==-1){
        front++;
        rear++;
        pqueue[rear]=data;
        return;
    }
    else{
        check(data);
        rear++;
    }
}

void display(){
    if(rear==-1){
        printf("\nqueue is empty");
        return;
    }
    for(int i=front;i<rear;i++){
        printf("%d\t",pqueue[i]);
    }
}
int main(){
    create();
    int x;
    while(1){
        printf("\nmenu");
        printf("\n1)insert element\n2)display\n3)exit");
        printf("\nenter your choice\t");
        scanf("%d",&x);
        switch(x){
            case 1: 
            printf("\nenter the element to be inserted\n");
            scanf("%d",&x);
            insert(x);
            break;
            case 2:
            printf("\nelements of queue are\n");
            display();
            break;
            case 3:
            exit(1);
            break;
        }
    }
    return 0;
}