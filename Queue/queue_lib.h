#include <stdio.h>
#include <stdlib.h>
#define max_size 10
struct Queue
{
    int items[max_size];
    int front;
    int rear;
};

int enqueue(struct Queue *q, int item)
{
    if (q->rear == max_size - 1)
    {
        printf("Queue overflow\n");
        return 1;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
}
int dequeue(struct Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue underflow\n");
        return 1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}
int display(struct Queue *q)
{
    if (q->rear == -1)
    {
        printf("Queue is empty\n");
        return 1;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
}

int reverse(struct Queue *q)
{
    if (q->front == -1)
    {
       return 1;
    }
    int item = dequeue(q);
    reverse(q);
    enqueue(q, item);
}
