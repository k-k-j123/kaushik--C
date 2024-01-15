#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
int main()
{
    int val, key, choice;
    struct node *root = NULL;
    do
    {
        printf("\nmenu\n");
        printf("\n1)create\n2)insert\n3)preorder\n4)inorder\n5)preorder\n6)search\n7)exit");
        printf("\nenter your choice\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = create(root);
            break;
        case 2:
            printf("\nenter the node value to be inserted\t");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 3:
            printf("\npreorder traversal is\t");
            preorder(root);
            break;
        case 4:
            printf("\ninorder traversal is\t");
            Inorder(root);
            break;
        case 5:
            printf("postorder traversal is\t");
            postorder(root);
            break;
        case 6:
            printf("\nenter the element to search\t");
            scanf("%d", &key);
            root = search(root, key);
            break;
        }
    } while (choice != 7);

    return 0;
}