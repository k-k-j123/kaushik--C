#include <stdio.h>
#include <Stdlib.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;
};
struct node *root, *t;
struct node *create_BST(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = data;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
        root = newnode;
    else
    {
        t = root;
        while (t != NULL)
        {
            if (data < t->info)
            {
                if (t->left == NULL)
                {
                    t->left = newnode;
                    break;
                }
                else
                {
                    t = t->left;
                }
            }
            else
            {
                if (t->right == NULL)
                {
                    t->right = newnode;
                    break;
                }
                else
                {
                    t = t->right;
                }
            }
        }
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void Inorder(struct node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        printf("%d", root->info);
        Inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->info);
    }
}
int main()
{
    int x, data;
    while (1)
    {
        printf("\n\n********Menu********");
        printf("\n1)insert data\n2)preorder traverse\n3)inorder traverse\n4)postorder traverse\n99)exit");
        printf("\nenter your choice\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("\nenter the data to insert\t");
            scanf("%d", &data);
            create_BST(data);
            printf("\nelement inserted successfully");
            break;
        case 2:
            printf("\npreorder\n");
            preorder(root);
            break;
        case 3:
            printf("\ninorder\n");
            Inorder(root);
            break;
        case 4:
            printf("\npostorder\n");
            postorder(root);
            break;
        case 99:
            exit(1);
            break;
        }
    }
    return 0;
}
