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

struct node *search(struct node *root,int data)
{
    if(root==NULL)
    {
        printf("\nelement not found");
    }
    else if(data<root->info)
    {
        root->left=search(root->left,data);
    }
    else if(data>root->info)
    {
        root->right=search(root->right,data);
    }
    else
    {
        printf("\nelement found is %d",root->info);
        return root;
    }
}

void preorder(struct node *root)
{   
    struct node *temp=root;
    if(temp!=NULL)
    {
        printf("%d ",temp->info);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void Inorder(struct node *root)
{   
    struct node *temp=root;
    if(temp!=NULL)
    {
        Inorder(temp->left);
        printf("%d ",temp->info);
        Inorder(temp->right);
    }
}

void postorder(struct node *root)
{   
    struct node *temp=root;
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ",temp->info); 
       
    }
}

