#include <stdio.h>
#include <stdlib.h>
#define max 10
int queue[max];
int front = -1;
int rear = -1;
int isfull()
{
    if (rear == max - 1)
    {
        return 1;
    }
    return 0;
}
int isempty()
{
    if (front == -1)
    {
        return 1;
    }
    return 0;
}
void enqueue(int value)
{
    if (isfull())
        printf("\nQueue is Full!!");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("\nInserted -> %d", value);
    }
}
void dequeue()
{
    if (isempty())
    {
        printf("\nqueue is empty");
    }
    else
    {

        int element = queue[front];
        printf("\nelement deleted is %d", element);
        front ++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
void display()
{
    if (isempty())
    {
        printf("\nqueue is empty");
    }
    printf("\nelements of queue are\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
}
int main()
{
    int x,element;
    while (1)
    {
        printf("\n********menu********");
        printf("\n1)insert\n2)delete\n3)display\n4)exit\n");
        printf("\nenter your choice\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nenter the element to be inserted\n");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        }
    }
}