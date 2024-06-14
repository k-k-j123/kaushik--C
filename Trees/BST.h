#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *right;
    struct node *left;
};

struct node *create(struct node *root)
{
    int i, data, n;
    struct node *newnode, *temp, *parent;
    printf("\nenter the number of elemets you want to enter in the tree\t");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        printf("\nenter the data to be inserted\t");
        scanf("%d", &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = data;
        newnode->left = newnode->right = NULL;

        if (root == NULL)
        {
            root = newnode;
            continue;
        }
        temp = root;
        while (temp != NULL)
        {
            parent = temp;
            if (data < temp->info)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (data < parent->info)
            parent->left = newnode;
        else
            parent->right = newnode;
    }
    return (root);
}

struct node *insert(struct node *root, int data)
{
    struct node *newnode, *temp = root, *parent;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->left = newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    while (temp != NULL)
    {
        parent = temp;
        if (data < temp->info)
            temp = temp->left;
        else
            temp = temp->right;
    }
    if (data < parent->info)
        parent->left = newnode;
    else
        parent->right = newnode;

    return (root);
}

struct node *search(struct node *root, int data)
{
    struct node *temp=root;
    while(temp!=NULL)
    {
        if(temp->info==data)
            return temp;
        else if(data<temp->info)
            temp=temp->left;
        else 
            temp=temp->right;
    }
    return NULL;
}

struct node *delete(struct node *root, int key)
{
    struct node *temp;
    if (root == NULL)
        return root;
    if (key < root->left)
        root->left = delete (root->left, key);
    else if (key > root->left)
        root->right = delete (root->right, key);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = root->right;
        while (temp && temp->left != NULL)
        root->info = temp->info;
        root->right = delete (root->right, temp->info);
    }
    return root;
}

void preorder(struct node *root)
{
    struct node *temp = root;
    if (temp != NULL)
    {
        printf("%d ", temp->info);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void Inorder(struct node *root)
{
    struct node *temp = root;
    if (temp != NULL)
    {
        Inorder(temp->left);
        printf("%d ", temp->info);
        Inorder(temp->right);
    }
}

void postorder(struct node *root)
{
    struct node *temp = root;
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->info);
    }
}
int countnodes(struct node *root)
{
    static int count = 0;
    struct node *temp = root;
    if (temp != NULL)
    {
        count++;
        countnodes(temp->left);
        countnodes(temp->right);
    }
    return count;
}
int countleaf(struct node *root)
{
    static int leaf = 0;
    struct node *temp = root;
    if (temp != NULL)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            leaf++;
        }
        countleaf(temp->left);
        countleaf(temp->right);
    }
    return leaf;
}