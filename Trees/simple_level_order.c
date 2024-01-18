#include<stdio.h>
#include<stdlib.h>
#define MAX 10
 struct node {
    int info;
    struct node *right;
    struct node *left;
};

 struct queue{
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

void levelorder(struct node *root)
{
    struct node *temp,*current;
    if(root==NULL)
        return;
    else{
        struct queue *q = (struct queue *)malloc(sizeof(struct queue));
        init(q);
        enqueue(q,root);
        while(!isempty(q)){
            current=dequeue(q);
            printf("%d  ",current->info);
            if(current->left!=NULL)
                enqueue(q,current->left);
            if(current->right!=NULL)
                enqueue(q,current->right);
            
        }
    }
}

int main()
{
    struct node *root=NULL;
    root=create(root);
    printf("\nlevel order traversal of nodes is\n");
    levelorder(root);
    return 0;
}