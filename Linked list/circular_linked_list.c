#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start, *last;
struct node *create(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}
void add(int data)
{
    struct node *t = create(data);
    if (start == NULL)
    {
        start = t;
        last = t;
    }
    last->next = t;
    last = t;
    last->next = start;//
}
void delatmid()
{
    int pos;
    printf("\nenter the element to be deleted");
    scanf("%d", &pos);
    struct node *t;
    t = start;
    if (pos == start->data)
    {
        if (start->next == start)
        {
            printf("\nlist contains only one element");
            free(start);
            start = NULL;
            return;
        }

        struct node *temp = start;
        start = start->next;//deleting at start

        while (start->next != temp)
        {
            start = start->next;//traverse till end
        }

        start->next = start->next->next;//storing new start in last element
        free(temp);
        return;
    }
    if (start == NULL)
    {
        printf("\nlist empty");
        return;
    }
    while (t->next->data != pos)
    {
        t = t->next;
    }
    if (t->next->next == start)
    {
        t->next = start;//deleting last element
        printf("\nelemetn deleted");
        return;
    }
    t->next = t->next->next;//deleting at mid
    printf("\nelemnt deleted");
}

void display()
{
    struct node *t;
    t = start;
    printf("\nelement of list are\n");
    do
    {
        printf("%d\t", t->data);
        t = t->next;
    } while (t != start);
}
int main()
{
    int x, data;
    while (1)
    {
        printf("\n******menu*****\n");
        printf("\n1)add\n2)display\n3)delete\n99)exit");
        printf("\nenter your choice\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nenter the element to insert\t");
            scanf("%d", &data);
            add(data);
            printf("\nelement inserted\n");
            break;
        case 2:
            display();
            break;
        case 3:
            delatmid();
            break;
        case 99:
            exit(1);
            break;
        }
    }
    return 0;
}