#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node {
    int info;
    struct node *left;
    struct node *right;
};

struct queue {
    struct node *data[MAX];
    int front, rear;
};

struct node *create(struct node *root) {
    struct node *newnode, *parent, *temp;
    int i, n, num;
    printf("\nhow many nodes\t");
    scanf("%d", &n);
    printf("\nenter the data element\t");
    for (i = 1; i <= n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &num);
        newnode->info = num;
        newnode->left = newnode->right = NULL;

        if (root == NULL) {
            root = newnode;
            continue;
        }

        temp = root;
        while (temp != NULL) {
            parent = temp;
            if (num < temp->info)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (num < parent->info)
            parent->left = newnode;
        else
            parent->right = newnode;
    }
    return root;
}

void init(struct queue *pq) {
    pq->front = pq->rear = 0; // Initialize front and rear to 0
}

void enqueue(struct queue *pq, struct node *treenode) {
    pq->data[pq->rear++] = treenode;

}

struct node *dequeue(struct queue *pq) {
    return pq->data[pq->front++];
}

int isempty(struct queue *pq) {
    return (pq->rear == pq->front);
}

int isfull(struct queue *pq) {
    return (pq->rear == MAX - 1);
}

int levelorder(struct node *root) {
    int i, level = 0;
    struct node *temp, *marker = NULL;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue)); // Allocate memory for the queue
    init(q);
    enqueue(q, root);
    enqueue(q, marker);
    printf("\nlevel %d --->", level);

    while (!isempty(q)) {
        temp = dequeue(q);
        if (temp == marker) {
            level++;
            if (!isempty(q)) {
                enqueue(q, marker);
                printf("\nlevel %d --->", level);
            }
        } else {
            printf("%d\t", temp->info);
            if (temp->left)
                enqueue(q, temp->left);
            if (temp->right)
                enqueue(q, temp->right);
        }
    }
    printf("\n number of levels=%d\n", level);
    free(q); // Free the allocated memory for the queue
    return level;
}

int nodesatlevel(struct node *root, int level) {
    if (root == NULL)
        return 0;
    if (level == 0)
        return 1;
    return nodesatlevel(root->left, level - 1) + nodesatlevel(root->right, level - 1);
}

int main() {
    int level,i;
    struct node *root = NULL;
    root = create(root);
    level=levelorder(root);
    for(i=0;i<level;i++)
        printf("\nnumber of nodes at %d level --> %d",i,nodesatlevel(root,i));
    return 0;
}
